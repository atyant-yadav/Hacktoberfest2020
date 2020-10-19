//jshint esversion:6
if (process.env.NODE_ENV !== 'production') {
  const dotenv = require('dotenv');
  dotenv.config();
}

const mongoose = require('mongoose');
const _ = require('lodash');

const dateFormat = require('dateformat');
dateFormat.masks.taskTime = 'dddd, mmmm dS, yyyy, h:MM TT';

const LoremIpsum = require("lorem-ipsum").LoremIpsum;
const lorem = new LoremIpsum({
  sentencesPerParagraph: {
    max: 1,
    min: 1
  },
  wordsPerSentence: {
    max: 6,
    min: 2
  }
});

var Todolist = (function() {
  this._backend = 'array';
  this._tasks = [];
  this._lastUpdated = null;

  this.lastUpdated = function() {
    return _lastUpdated || updateTime();
  };

  this.updateTime = function() {
    _lastUpdated = dateFormat(new Date(), "taskTime");
    return _lastUpdated;
  };

  this.forEach = function(list, callback) {
    return _.forEach(_tasks.filter(task => task.list == list), callback);
  };

  this.lists = function() {
    let lists = new Set();
    _tasks.forEach(task => lists.add(task.list));
    return lists;
  }

  this.refeshTasks = function(list, callback) {
    if (_backend == 'mongo') {
      Task.find(function(err, foundTasks) {
        if (!err) {
          _tasks = foundTasks;
          callback();
        }
      });
    } else {
      callback();
    }
  };

  this.add = function(list, title) {
    if (title.length < 1) return;
    var task = {
      title: title,
      date: updateTime(),
      id: _.kebabCase(title),
      finished: false,
      list: list
    };

    if (_tasks.length > 100) {
      console.log('Safety precaution: stopping inserts to prevent spam');
      return;
    };

    _tasks.push(task);
    console.log(`Added task:\n ${JSON.stringify(task)}`);

    if (_backend == 'mongo') {
      var newTask = new Task(task);
      newTask.save(function(err, insertedTask) {
        if (err) {
          console.log('Problem inserting new task into mongo');
        } else {
          console.log(`Inserted document ${insertedTask}`);
        }
      });
    };
  };

  this.delete = function(list, item_id) {
    var filteredTasks = [];
    var deletedTasks = [];

    if (_backend == 'array') {
      _tasks.forEach(task => {
        if (task.id === item_id && task.list === list) {
          deletedTasks.push(task);
        } else {
          filteredTasks.push(task);
        }
      });
      _tasks = filteredTasks;
      console.log(`Deleted ${deletedTasks.length} tasks:\n ${JSON.stringify(deletedTasks)}`);
    } else {
      Task.deleteOne({
        id: item_id,
        list: list
      }, function(err, result) {
        if (!err) {
          console.log(`Mongo delete result:\n ${JSON.stringify(result)}`);
        } else {
          console.log(`Mongo error result: ${err}`);
        }
      });
    }
  };

  this.buildMocks = function(n = 3) {
    if (_backend == 'array' && _tasks.length < 1) {
      addMocks();
      return;
    } else {
      if (_backend == 'mongo') {
        console.log('Checking mongodb for existing tasks');
        Task.find(function(err, foundTasks) {
          if (err) {
            console.log(`Error connecting to mongo, falling back to array.\n${err}`);
            _backend = 'array';
            buildMocks();
          } else {
            if (foundTasks.length < 1) {
              addMocks(n);
            } else {
              _tasks = foundTasks;
              console.log(`Found ${foundTasks.length} tasks in mongodb, no need to create new ones`);
            }
          }
        });
        return;
      }
    }
    console.log('No mocks needed');
  };

  this.addMocks = function(n = 3) {
    console.log(`Building mock tasks on backend ${_backend}`);
    for (i = 0; i < n; i++) {
      add('Today', `${lorem.generateSentences(1)}`);
    }
    updateTime();
    console.log(`${i} mock tasks added to todolist at ${_lastUpdated}`);
  };

  this.log = function() {
    console.log(JSON.stringify(_tasks));
  };

  this.enableMongo = function(callback) {
    mongoose.connection.on('connected', function() {
      _backend = 'mongo';
      console.log('Switched Todolist to mongo backend');
      if (callback) {
        callback();
      } else {
        console.log('No callback for enableMongo function');
      }
    });
    mongoose.connect(_mconnect, {
      useNewUrlParser: true,
      useUnifiedTopology: true
    }).catch(err => {
        console.log(`Mongoose connection error:\n${_mconnect}\n${err}`);
    });
  };

  const mauth = process.env.MONGO_USER ? `${process.env.MONGO_USER}:${process.env.MONGO_PASSWORD}@` : '';
  const mhost = process.env.MONGO_HOST || 'localhost';
  const mport = process.env.MONGO_PORT || 27017;
  if (process.env.USE_ATLAS == 'true') {
    this._mconnect = `mongodb://${mauth}${mhost}`;
  } else {
    this._mconnect = `mongodb://${mauth}${mhost}:${mport}/todolist`;
  };
  const tasksSchema = {
    title: String,
    date: String,
    id: String,
    finished: Boolean,
    list: String
  };
  this.Task = mongoose.model('Task', tasksSchema);

  console.log(`Todolist singleton created with backend ${_backend}`);
  return this;
})();

module.exports = Todolist;

// https://docs.mongodb.com/manual/tutorial/enable-authentication/
// use admin
// db.createUser(
//   {
//     user: 'brainvat',
//     pwd: passwordPrompt(), // or cleartext password
//     roles: [ { role: 'userAdminAnyDatabase', db: 'admin' }, 'readWriteAnyDatabase' ]
//   }
// )

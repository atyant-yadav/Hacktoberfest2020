//jshint esversion:6
const express = require('express');
const bodyParser = require('body-parser');
const ejs = require('ejs');
const todolist = require('./models/todolist.js');

const app = express();
app.set('view engine', 'ejs');
app.use(bodyParser.urlencoded({extended: true}));
app.use(express.static("public"));

if (process.env.NODE_ENV !== 'production') {
  const dotenv = require('dotenv');
  dotenv.config();
}

const USE_MONGO = process.argv.includes('USE_ARRAY') ? false : true;

// Today methods

app.get('/', function(req, resp) {
  todolist.refeshTasks('Today', function() {
    resp.render('todolist', {todolist: todolist, list: 'Today'});
  });
});

app.post('/', function(req, resp) {
  todolist.add(req.body.list, req.body.newItem);
  resp.redirect('/' + (req.body.list == 'Today' ? '' : req.body.list));
});

app.post('/delete', function(req, resp) {
  todolist.delete(req.body.list, req.body.item_id);
  resp.redirect('/' + (req.body.list == 'Today' ? '' : req.body.list));
});

// Custom List methods, supported only for Mongo backend

app.get('/:customListName', function(req, resp) {
  const list = req.params.customListName;
  todolist.refeshTasks(list, function() {
    resp.render('todolist', {todolist: todolist, list: list});
  });
});

// Other methods

app.get('/p/about', function(req, resp) {
  resp.render('about');
});

app.get('/p/activate-mongo', function(req, resp) {
  todolist.enableMongo(function() {
    todolist.buildMocks();
    resp.redirect('/');
  });
});

// set up Todolist
if (USE_MONGO) {
  todolist.enableMongo(function() {
    todolist.buildMocks();
  });
} else {
  todolist.buildMocks();
}

// use dotenv for port in case this is hosted on Heroku
const port = process.env.PORT || 3000;
app.listen(port, function(){
  console.log(`Express server listening on port ${port}`);
});

//
// git subtree push --prefix projects/todolist_mongoose heroku-todolist master
//

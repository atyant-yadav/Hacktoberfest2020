# json objects    		dict{"key":"value"}
# numbers 10 10.25		int float
# array[10,"string"]	list
#						tuple
# " "					' ' " " """ """
#Null                    None
# true                  True
# false                 False



# json.load(f) load json data from a file ( or file like structure)
# json.loads(s) loads json data from a string 
# json.dump(j,f) write a json object to file (or file like object)
# json.dumps(j) outputs the json object as a string

import json

handle=open("json_input.json","r")
content = handle.read()

# print(content)

# loads function convertes json format file into python datatypes
#handle.close()
#print(handle)
# here content is a string type so we use loads
# we can also use json.load(handle)


d=json.loads(content)
# print(d)
#print(d["database"])
#print(d["database"]["host"])

# d["database"]["host"]="public host"
#print(d)

#print(d['files']['log'])
# d['files']['log']=("/log/app.log","/log/mysql/app.log")
#print(d)


# dumps converts python format to json format
# j=json.dumps(d)
# print(j)
#conversion of a ppython file in to a json file is done by dumps


# handle=open("json_output.json","w")
# handle.write(j)
# handle.close()
# the above will give all in a line with out prettyfy 

# j=json.dumps(d,indent=4)
# handle=open("json_output2.json","w")
# handle.write(j)
# handle.close()
# this will the prettyfied versions

# j=json.dumps(d,indent=4,sort_keys=True)
# Sorts the keys in alphabatical order
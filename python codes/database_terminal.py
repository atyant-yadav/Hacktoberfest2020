import mysql.connector

#connection
mydb = mysql.connector.connect(
  host="database_url",
  user="username",
  password="password",
  database="database_name,
)

mycursor = mydb.cursor()

code = input("Enter SQL code here ")
sql = code
mycursor.execute(sql)

mydb.commit()

print(mycursor.rowcount, "record inserted.")

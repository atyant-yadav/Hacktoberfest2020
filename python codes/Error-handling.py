#2:WAP a python program to open a file in read only mode and try writing

# something to it and handle the subsequent errors using Exception Handling

file = open("rename.txt", "w")

try:

    file.write("This is a text file")

except Exception as e:

    print("Error in the  handling file ")

    print("Error: ", e)

finally:

    file.close()

print("This is  Exception Handling")

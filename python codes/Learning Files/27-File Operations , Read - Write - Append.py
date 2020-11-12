# fp=open("input2.txt","w")
# fp.write("Write this line to a file")
# fp.write("This is a new line")
# it will replace with new once
# when ever we open in write mode it will flush the entire content

# in write mode we cant perform read operation
# content = fp.read()
# error same in read mode we cant perform write operation
# that is the reason that we have w+ mode 
# it stand for write and read

# fp=open("input2.txt","w+")
# fp.write("Sample text line")

# content = fp.read()
# print(content)
# still it wont print any thing but there will be a line in the file
# coz of the pointer


# to move the file pointer
# tell
# seek 

# tell => current fp position 
# seek(offset,position) = > to change the fp position


# fp=open("input2.txt","w+")
# print(fp.tell())
# fp.write("Sample text line")
# print(fp.tell())
# content = fp.read()
# print(fp.tell())
# print(content)

# offset=>no. of character
# position = > 0=start of the file
# 			1=current position
# 			2=end of the file
# seek(15,0) means change the fp by 15 characters from start of the file
# seek(0,2)= means change the fp to 0 position from the end of the file
# when ever we use 1 or 2 the offset value must be 0
# seek(15,1)
# seek(15,2) these are not allowed 


# fp=open("input2.txt","w+")
# print(fp.tell())
# fp.write("Sample text line")
# print(fp.tell())
# fp.seek(0,0)
# print(fp.tell())
# content = fp.read()
# print(fp.tell())
# print(content)

# r+ = read +write
# when we have w+ why r+
# coz when we open a file in w+ it will clean the matter but in r+ it wont


# fp = open("input.txt","r+")
# content = fp.read()
# print(content)

# fp.write("\n\n\n Sample line added using python")
# print(content)

# append and append+ mode as the name suggests that the adding some thinng 
# for existence file then why r+ , w+ 
# in append the file pointer location starts from the ending

# fp = open("input.txt","a+")
# print(fp.tell())
# content = fp.read()
# print(content)

# fp.write("\n\n\n Sample line added using python")
# print(content)

# what is the advantage of this suppose u are using r+ mode if u want
# to write anything u need to use seek function and move it to the last
# in append function we can only write a file but in append+ mode we can 
# also read

# r=> fp => start, file should already exist, read
# r+ => fp =>start,file should already exist, read and write

# w=> fp=> start,creat a new file, write
# w+=> fp=> start, creat a new file, write + read

# a=> fp=> end , creat a new file , write at the end
# a+ = > fp => end, create a new file and read and write
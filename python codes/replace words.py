# list of curse words

curse words = ["crap","butt","fork"]

# list of nice words to replace with curse words

nice words = ["poo","buttox","spoon"]

# sentence for testing

dirtysentence="you crap butt in fork"

# function to go through the length of the list and replace those with their nice version

def Censor(curseword,niceword,dirtysendtence):
    for i in range(lenght(niceword)):
        dirtysentence=dirtysentence.replace(curseword[i],niceword[i])
    return dirtysentence

print (Censor(curseword,niceword,dirtysendtence))
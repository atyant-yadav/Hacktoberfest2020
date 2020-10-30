pig = "ay"

shouldContinue = "0"
while shouldContinue != "1":
  original = input("Please type in a word: ")

  if len(original)>0 and original.isalpha():
    word = original.lower()
    first = word[0]
    new_word = word + "-" + first + pig
    new_word = new_word[1:len(new_word)]
    print(new_word)
  else:
    print("ERROR: Something happened. Please try again")
  shouldContinue = input("Type in 0 to translate another word and 1 to quit: ")

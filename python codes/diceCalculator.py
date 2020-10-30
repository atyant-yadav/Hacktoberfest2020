from random import randint
from time import sleep
while True:
  instruction = "Please enter your dice in this format: NdN (e.g. 6d20 will roll 6 20-sided dice)"
  print(instruction)
  user_choice = input("Enter your die: ").upper()
  print("Rolling...")
  #sleep(2)
  def roll_die(faces):
    return randint(0,faces)
  def num_rolls():
    user_split = list(user_choice)
    thing = ""
    thingo = 0
    for x in user_split:
      if x != "D" and thingo == 0:
        thing = thing + x
      elif x == "D":
        thingo = 1
    if thing.isdigit() == True and thing != "":
      return int(thing)
    elif thing == "":
      thing = 1
      return int(thing)
    else:
      return "Please enter a proper number of rolls."
  def die_faces():
    user_split2 = list(user_choice)
    thing2 = ""
    thingo2 = 1
    for x in user_split2:
      if x != "D" and thingo2 == 0:
        thing2 = thing2 + x
      elif x == "D":
        thingo2 = 0
    if thing2.isdigit() == True:  
      return int(thing2)
    else:
      return "Please enter a proper number of faces."
  roll = num_rolls()
  faces = die_faces()
  result = 0
  die_results = []
  pretotal = 0
  thing = ""
  if roll > 1:
    thing = "c"
  else:
    thing = ""
  for a in range(roll):
    pretotal = roll_die(faces)
    result = result + pretotal
    die_results.append(pretotal)
  result_listring = str(die_results).replace("[", "")
  result_listring = result_listring.replace("]", "")
  result_listring = result_listring.replace("'", "")
  result_listring = result_listring.replace('"', "")
  result_listring = result_listring.replace(",", "")
  result_listring = result_listring.split()
  result_listring = " + ".join(result_listring)
  answer = "You rolled " + str(roll) + " " + str(faces) + "-sided " + "di" + thing + "e" " and got... " + result_listring + " = " + str(result)
  if result == faces * roll:
    print("You got a critical!")
  elif result < ((faces * roll) / 2):
    print("Uh oh...")
  else:
    print("You have a somewhat resonable chance of surviving this time.")

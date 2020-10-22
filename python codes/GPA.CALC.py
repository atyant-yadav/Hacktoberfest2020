#Initalizing variables
classgradepregpa = 0
wasithonorsAPregular = ""
gpafclass = 0
#Not gonna do half credits cause that would take literal years
numofclass7sem1 = int(input("How many High School Courses did you take in the first semester of seventh grade?: "))
numofclass7sem2 = int(input("How many High School Courses did you take in the second semester of seventh grade?: "))
numofclass8sem1 = int(input("How many High School Courses did you take in the first semester of eighth grade?: "))
numofclass8sem2 = int(input("How many High School Courses did you take in the second semester of eighth grade?: "))
numofclass9sem1 = int(input("How many High School Courses did you take in the first semester of ninth grade?: "))
numofclass9sem2 = int(input("How many High School Courses did you take in the second semester of ninth grade?: "))
numofclass10sem1 = int(input("How many High School Courses did you take in the first semester of tenth grade?: "))
numofclass10sem2 = numofclass10sem1 = int(input("How many High School Courses did you take in the second semester of tenth grade?: "))
#For cumulative GPA
everygrade = []
#Calc first sem GPA
fstsemsevgpalist = []
for i in range(0, numofclass7sem1): 
  classgradepregpa = int(input("What was your grade for a class the first semester of 7th grade? "))
  wasithonorsAPregular = input("Was the course Honors/AP/Regular? ANSWER WITH ONLY AP, H or R!")
  if(wasithonorsAPregular == "AP"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 6.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 5.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 5.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 5.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 4.4
    elif(classgradepregpa == 70):
      gpafclass = 4.2
    else:
      gpafclass = 0.0
  elif(wasithonorsAPregular == "H"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.5
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.3
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.1
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.9
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.7
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.5
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.3
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.1
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.9
    elif(classgradepregpa == 70):
      gpafclass = 3.7
    else:
      gpafclass = 0
  elif(wasithonorsAPregular == "R"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 4.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 4.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 3.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 3.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.4
    elif(classgradepregpa == 70):
      gpafclass = 3.2
    else:
      gpafclass = 0
  else:
    print("Why did you not put H, R, or AP? You just broke the program!")
  fstsemsevgpalist.append(gpafclass)
  everygrade.append(gpafclass)
if(numofclass7sem1 > 0):
  svnfstsemav = sum(fstsemsevgpalist) / len(fstsemsevgpalist)
  svnfstsemav = str(svnfstsemav)
  print("You got a "+svnfstsemav+" the first semester of 7th grade") 
#Calc second sem 7th GPA
if(numofclass7sem2 > 0):
  print("Moving on to second sem of 7th grade")
secsemsevgpalist = []
for i in range(0, numofclass7sem2): 
  classgradepregpa = int(input("What was your grade for a class the second semester of seventh grade? "))
  wasithonorsAPregular = input("Was the course Honors/AP/Regular? ANSWER WITH ONLY AP, H or R!")
  if(wasithonorsAPregular == "AP"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 6.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 5.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 5.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 5.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 4.4
    elif(classgradepregpa == 70):
      gpafclass = 4.2
    else:
      gpafclass = 0.0
  elif(wasithonorsAPregular == "H"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.5
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.3
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.1
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.9
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.7
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.5
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.3
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.1
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.9
    elif(classgradepregpa == 70):
      gpafclass = 3.7
    else:
      gpafclass = 0
  elif(wasithonorsAPregular == "R"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 4.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 4.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 3.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 3.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.4
    elif(classgradepregpa == 70):
      gpafclass = 3.2
    else:
      gpafclass = 0
  else:
    print("Why did you not put H, R, or AP? You just broke the program!")
  secsemsevgpalist.append(gpafclass)
  everygrade.append(gpafclass)
if(numofclass7sem2 > 0):
  svnsecsemav = sum(secsemsevgpalist) / len(secsemsevgpalist)
  svnsecsemav = str(svnsecsemav)
  print("You got a "+svnsecsemav+" the second semester of 7th grade") 
#Calc first sem 8th GPA
if(numofclass8sem1 > 0):
  print("Moving on to the first sem of 8th grade")
fstsem8thgpalist = []
for i in range(0, numofclass8sem1): 
  classgradepregpa = int(input("What was your grade for a class the first semester of eighth grade? "))
  wasithonorsAPregular = input("Was the course Honors/AP/Regular? ANSWER WITH ONLY AP, H or R!")
  if(wasithonorsAPregular == "AP"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 6.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 5.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 5.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 5.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 4.4
    elif(classgradepregpa == 70):
      gpafclass = 4.2
    else:
      gpafclass = 0.0
  elif(wasithonorsAPregular == "H"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.5
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.3
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.1
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.9
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.7
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.5
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.3
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.1
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.9
    elif(classgradepregpa == 70):
      gpafclass = 3.7
    else:
      gpafclass = 0
  elif(wasithonorsAPregular == "R"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 4.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 4.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 3.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 3.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.4
    elif(classgradepregpa == 70):
      gpafclass = 3.2
    else:
      gpafclass = 0
  else:
    print("Why did you not put H, R, or AP? You just broke the program!")
  fstsem8thgpalist.append(gpafclass)
  everygrade.append(gpafclass)
if(numofclass8sem1 > 0):
  eightsemoneav = sum(fstsem8thgpalist) / len(fstsem8thgpalist)
  eightsemoneav = str(eightsemoneav)
  print("You got a "+eightsemoneav+" the first semester of 8th grade") 
#Calc second sem 8th GPA
if(numofclass8sem2 > 0):
  print("Moving on to the second sem of 8th grade")
secsem8thgpalist = []
for i in range(0, numofclass8sem2): 
  classgradepregpa = int(input("What was your grade for a class the second semester of eighth grade? "))
  wasithonorsAPregular = input("Was the course Honors/AP/Regular? ANSWER WITH ONLY AP, H or R!")
  if(wasithonorsAPregular == "AP"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 6.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 5.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 5.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 5.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 4.4
    elif(classgradepregpa == 70):
      gpafclass = 4.2
    else:
      gpafclass = 0.0
  elif(wasithonorsAPregular == "H"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.5
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.3
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.1
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.9
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.7
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.5
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.3
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.1
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.9
    elif(classgradepregpa == 70):
      gpafclass = 3.7
    else:
      gpafclass = 0
  elif(wasithonorsAPregular == "R"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 4.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 4.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 3.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 3.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.4
    elif(classgradepregpa == 70):
      gpafclass = 3.2
    else:
      gpafclass = 0
  else:
    print("Why did you not put H, R, or AP? You just broke the program!")
  secsem8thgpalist.append(gpafclass)
  everygrade.append(gpafclass)
if(numofclass8sem2 > 0):
  eightsemtwoav = sum(secsem8thgpalist) / len(secsem8thgpalist)
  eightsemtwoav = str(eightsemoneav)
  print("You got a "+eightsemtwoav+" the second semester of 8th grade")
#Calc first sem 9th GPA
if(numofclass9sem1 > 0):
  print("Moving on to the first sem of 9th grade")
fstsem9thgpalist = []
for i in range(0, numofclass9sem1): 
  classgradepregpa = int(input("What was your grade for a class the first semester of ninth grade? "))
  wasithonorsAPregular = input("Was the course Honors/AP/Regular? ANSWER WITH ONLY AP, H or R!")
  if(wasithonorsAPregular == "AP"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 6.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 5.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 5.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 5.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 4.4
    elif(classgradepregpa == 70):
      gpafclass = 4.2
    else:
      gpafclass = 0.0
  elif(wasithonorsAPregular == "H"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.5
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.3
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.1
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.9
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.7
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.5
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.3
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.1
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.9
    elif(classgradepregpa == 70):
      gpafclass = 3.7
    else:
      gpafclass = 0
  elif(wasithonorsAPregular == "R"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 4.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 4.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 3.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 3.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.4
    elif(classgradepregpa == 70):
      gpafclass = 3.2
    else:
      gpafclass = 0
  else:
    print("Why did you not put H, R, or AP? You just broke the program!")
  fstsem9thgpalist.append(gpafclass)
  everygrade.append(gpafclass)
if(numofclass9sem1 > 0):
  ninthsemoneav = sum(fstsem9thgpalist) / len(fstsem9thgpalist)
  ninthsemoneav = str(ninthsemoneav)
  print("You got a "+ninthsemoneav+" the first semester of 9th grade") 
#Calc second sem 9th GPA
if(numofclass9sem2 > 0):
  print("Moving on to the second sem of 9th grade")
secsem9thgpalist = []
for i in range(0, numofclass9sem2): 
  classgradepregpa = int(input("What was your grade for a class the second semester of ninth grade? "))
  wasithonorsAPregular = input("Was the course Honors/AP/Regular? ANSWER WITH ONLY AP, H or R!")
  if(wasithonorsAPregular == "AP"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 6.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 5.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 5.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 5.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 4.4
    elif(classgradepregpa == 70):
      gpafclass = 4.2
    else:
      gpafclass = 0.0
  elif(wasithonorsAPregular == "H"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.5
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.3
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.1
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.9
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.7
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.5
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.3
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.1
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.9
    elif(classgradepregpa == 70):
      gpafclass = 3.7
    else:
      gpafclass = 0
  elif(wasithonorsAPregular == "R"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 4.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 4.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 3.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 3.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.4
    elif(classgradepregpa == 70):
      gpafclass = 3.2
    else:
      gpafclass = 0
  else:
    print("Why did you not put H, R, or AP? You just broke the program!")
  secsem9thgpalist.append(gpafclass)
  everygrade.append(gpafclass)
if(numofclass9sem2 > 0):
  ninthsemtwoav = sum(secsem9thgpalist) / len(secsem9thgpalist)
  ninthsemtwoav = str(ninthsemtwoav)
  print("You got a "+ninthsemtwoav+" the second semester of 9th grade")
#Calc first sem 10th GPA
if(numofclass10sem1 > 0):
  print("Moving on to the first sem of 10th grade")
fstsem10thgpalist = []
for i in range(0, numofclass10sem1): 
  classgradepregpa = int(input("What was your grade for a class the first semester of tenth grade? "))
  wasithonorsAPregular = input("Was the course Honors/AP/Regular? ANSWER WITH ONLY AP, H or R!")
  if(wasithonorsAPregular == "AP"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 6.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 5.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 5.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 5.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 4.4
    elif(classgradepregpa == 70):
      gpafclass = 4.2
    else:
      gpafclass = 0.0
  elif(wasithonorsAPregular == "H"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.5
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.3
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.1
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.9
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.7
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.5
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.3
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.1
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.9
    elif(classgradepregpa == 70):
      gpafclass = 3.7
    else:
      gpafclass = 0
  elif(wasithonorsAPregular == "R"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 4.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 4.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 3.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 3.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.4
    elif(classgradepregpa == 70):
      gpafclass = 3.2
    else:
      gpafclass = 0
  else:
    print("Why did you not put H, R, or AP? You just broke the program!")
  fstsem10thgpalist.append(gpafclass)
  everygrade.append(gpafclass)
if(numofclass10sem1 > 0):
  tenthsemoneav = sum(fstsem10thgpalist) / len(fstsem10thgpalist)
  tenthsemoneav = str(tenthsemoneav)
  print("You got a "+tenthsemoneav+" the first semester of 10th grade")
#Calc second sem 10th GPA
if(numofclass10sem1 > 0):
  print("Moving on to the second sem of 10th grade")
secsem10thgpalist = []
for i in range(0, numofclass10sem2): 
  classgradepregpa = int(input("What was your grade for a class the second semester of tenth grade? "))
  wasithonorsAPregular = input("Was the course Honors/AP/Regular? ANSWER WITH ONLY AP, H or R!")
  if(wasithonorsAPregular == "AP"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 6.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 5.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 5.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 5.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 4.4
    elif(classgradepregpa == 70):
      gpafclass = 4.2
    else:
      gpafclass = 0.0
  elif(wasithonorsAPregular == "H"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.5
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 5.3
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 5.1
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.9
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.7
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.5
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 4.3
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 4.1
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.9
    elif(classgradepregpa == 70):
      gpafclass = 3.7
    else:
      gpafclass = 0
  elif(wasithonorsAPregular == "R"):
    if(classgradepregpa == 100 or classgradepregpa == 99 or classgradepregpa == 98 or classgradepregpa == 97):
      gpafclass = 5.0
    elif(classgradepregpa == 96 or classgradepregpa == 95 or classgradepregpa == 94):
      gpafclass = 4.8
    elif(classgradepregpa == 93 or classgradepregpa == 92 or classgradepregpa == 91 or classgradepregpa == 90):
      gpafclass = 4.6
    elif(classgradepregpa == 89 or classgradepregpa == 88 or classgradepregpa == 87):
      gpafclass = 4.4
    elif(classgradepregpa == 86 or classgradepregpa == 85 or classgradepregpa == 84):
      gpafclass = 4.2
    elif(classgradepregpa == 83 or classgradepregpa == 82 or classgradepregpa == 81 or classgradepregpa == 80):
      gpafclass = 4.0
    elif(classgradepregpa == 79 or classgradepregpa == 78 or classgradepregpa == 77):
      gpafclass = 3.8
    elif(classgradepregpa == 76 or classgradepregpa == 75 or classgradepregpa == 74):
      gpafclass = 3.6
    elif(classgradepregpa == 73 or classgradepregpa == 72 or classgradepregpa == 71 ):
      gpafclass = 3.4
    elif(classgradepregpa == 70):
      gpafclass = 3.2
    else:
      gpafclass = 0
  else:
    print("Why did you not put H, R, or AP? You just broke the program!")
  secsem10thgpalist.append(gpafclass)
  everygrade.append(gpafclass)
if(numofclass10sem2 > 0):
  tenthsemtwoav = sum(secsem10thgpalist) / len(secsem10thgpalist)
  tenthsemtwoav = str(tenthsemtwoav)
  print("You got a "+tenthsemtwoav+" the second semester of 10th grade") 
#There done.
print("Here are you GPA's")
if(numofclass7sem1>0):
  #7th
  svnfstsemav = str(svnfstsemav)
  print("First Semester of Seventh Grade: "+ svnfstsemav)
if(numofclass7sem2>0):
  svnsecsemav = str(svnsecsemav)
  print("Second Semester of Seventh Grade: "+ svnsecsemav)
#8th
if(numofclass8sem1>0):
  eightsemoneav = str(eightsemoneav)
  print("First Semester of Eighth Grade: "+ eightsemoneav)
if(numofclass8sem2>0):
  eightsemtwoav = str(eightsemtwoav)
  print("Second Semester of Eighth Grade: "+ eightsemtwoav)
#9th
if(numofclass9sem1>0):
  ninthsemoneav = str(ninthsemoneav)
  print("First Semester of Ninth Grade: "+ ninthsemoneav)
if(numofclass9sem2>0):
  ninthsemtwoav = str(ninthsemtwoav)
  print("Second Semester of Ninth Grade: "+ ninthsemtwoav)
#10th
if(numofclass10sem1>0):
  tenthsemoneav = str(tenthsemoneav)
  print("First Semester of Tenth Grade: "+ tenthsemoneav)
if(numofclass10sem2>0):
  tenthsemtwoav = str(tenthsemtwoav)
  print("Second Semester of Tenth Grade: "+ ninthsemtwoav)
CumulativeGPA = sum(everygrade) / len(everygrade)
CumulativeGPA = str(CumulativeGPA)
print("Here is your CumulativeGPA: "+CumulativeGPA)

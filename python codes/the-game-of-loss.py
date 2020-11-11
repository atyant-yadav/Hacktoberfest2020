import time
import sys
import random


def printOut(m):
    l = list(m)
    for i in range(0, len(l)):
        print(l[i], end='', flush=True)
        time.sleep(0.01)
    print()


def house():  # House
    global cuts
    global ankle
    global sprainedWrist
    inHouse = 1

    printOut("\nYou step into the hallway, ready for the day!")
    printOut("You need to go downstairs and make some food.")
    time.sleep(1)
    while inHouse == 1:
        randomChance = random.randint(0, 10)
        printOut("\nHow will you get down?\nSteps    Railing    Window")
        options = input()
        if options.upper() == "STEPS":
            printOut("\nYou walk down the stairs.")
            break
        elif options.upper() == "RAILING":
            printOut("You slide down the railing. Why not have a little fun?")
            time.sleep(0.8)
            printOut("You've never done this before, and you don't know how.\n")
            time.sleep(1)
            if randomChance >= 5:
                printOut("You slide down nicely, satisfied with your attempt.")
                break
            elif randomChance < 5:
                printOut("You fall off of the railing and sprain your wrist.\n")
                time.sleep(2)
                printOut("Great job.\n")
                time.sleep(1)
                printOut("You walk to the kitchen, gritting your teeth to withstand the pain of your wrist.")
                sprainedWrist = 1
                break
        elif options.upper() == "WINDOW":
            printOut("You walk up to the window.\nDive    Climb")
            options = input()
            if options.upper() == "DIVE":
                printOut("\nYou rear up, getting ready to dive...")
                time.sleep(2)
                if randomChance >= 6:
                    printOut("\nYou ace it! You break through the window and end on a roll from the two story drop.")
                    time.sleep(2.5)
                    printOut("You look up at the broken window, realizing that it wasn't the best idea to do that.")
                    time.sleep(2)
                    printOut("..Whatever.")
                    time.sleep(1)
                    printOut("You enter the house from the back door, because you always forget to lock it.")
                    time.sleep(3)
                    break

                elif randomChance < 6:
                    printOut("\nYou fail the dive, ending up with a lot of cuts on your skin from the broken glass.")
                    time.sleep(2.5)
                    printOut("You writhe in pain on the ground for a bit, and then pick yourself up.")
                    time.sleep(2)
                    cuts = 1
                    printOut("You enter the house from the back door, because you always forget to lock it.")
                    time.sleep(3)
                    break

            if options.upper() == "CLIMB":
                printOut("\nYou walk up to the window, release the lock, and open it.")
                time.sleep(0.8)
                printOut("You start to climb out...")
                time.sleep(1)

                if randomChance >= 4:
                    printOut("You safely climb down.")
                    time.sleep(0.7)
                    printOut("You enter the house from the back door, because you always forget to lock it.")
                    time.sleep(1)
                    break

                if randomChance < 4:
                    printOut("You slip and twist your ankle from the fall.")
                    time.sleep(1.2)
                    ankle = 1
                    printOut("You hobble into the house from the back door, because you always forget to lock it.")
                    time.sleep(1)
                    break


def makeEgg():
    randomChances = random.randint(0, 10)
    global makeEggs
    makeEggs = 1
    global pan
    pan = 0
    global stove
    stove = 0
    global egg
    egg = 0
    global options

    printOut("You want to make an egg. What do you need to do?\nEgg  -  Stove  -  Pan  -  Oil")
    options = input()

    if options.upper() == "EGG":

        if egg == 1 or egg == -1:

            printOut("Pour the egg?\nYes    No")
            options = input()

            if options.upper() == "NO" and pan == 0:
                printOut("Right, you haven't put the pan on yet!")

            elif options.upper() == "YES" and pan == 0:
                printOut(
                    "You pour the egg on the stove. You forgot the pan. It seeps through the burner, and your egg is now ruined.")
                makeEggs = 0

            elif options.upper() == "NO" and pan == 1:
                printOut("You don't pour the egg on the pan.")

            elif options.upper() == "YES" and pan == 1:
                printOut("You pour the egg on the pan.")
            if stove == 1:
                printOut("It sizzles and starts to coagulate.")



        elif egg == 0:
            printOut("You attempt to crack the egg and pour it into a bowl...")
            time.sleep(2)
            if randomChances >= 4:
                printOut("You successfully crack the egg.")
                time.sleep(1.5)
                egg = 1


            elif randomChances < 4:
                printOut(
                    "You apply an excessive amount of force and slam the egg into the bowl.\nThere is now a bunch of egg shell mixed in with your egg.")
                time.sleep(3)
                egg = -1


    elif options.upper() == "STOVE":

        if stove == 1:
            printOut("You turn the stove off")
            stove = 0

        elif stove == 0:
            printOut("You turn the stove on")
            stove = 1


    elif options.upper() == "PAN":

        if pan == 1:
            printOut("You take the pan off of the stove.")
            pan = 0

        elif pan == 0:
            printOut("You place the pan on the stove.")
            pan = 1


def kitchen():  # Kitchen

    global randomChance
    randomChance = random.randint(0, 10)

    global makeBacon
    makeBacon = 1
    global makeToast
    makeToast = 1
    global makeCereal
    makeCereal = 1
    printOut("You enter the kitchen.")
    time.sleep(1)

    printOut("What should you eat?\nEgg    Bacon    Toast    Cereal")
    options = input()

    if options.upper() == "EGG":
        makeEgg()


def bedroom():  # Bedroom
    global sleptIn
    sleptIn = 0
    global inBedroom
    inBedroom = 1
    global wearSuit
    wearSuit = 0
    global wearPajamas
    wearPajamas = 0
    global wearDenim
    wearDenim = 0
    global wearNothing
    wearNothing = 0
    global windowOpen
    windowOpen = 0

    while inBedroom == 1:
        time.sleep(1.5)
        printOut("\nYour options are...\nCloset    Bed    Window    Door")
        options = input()

        if options.upper() == "CLOSET":  # Bedroom Closet
            printOut("\nYou head over to your walk-in closet. Should you get dressed?\nYes    No")
            options = input()

            if options.upper() == "YES":
                printOut("\nWhat should you wear?\nSuit    Pajamas    Denim")
                options = input()

                if options.upper() == "SUIT":
                    printOut("\nYou're feeling fancy, so you put on your favorite suit and tie.")
                    wearSuit = 1
                    wearPajamas = 0
                    wearDenim = 0
                    wearNothing = 0

                elif options.upper() == "PAJAMAS":
                    printOut("\nYou're feeling lazy, so you put on some loose pajamas.")
                    wearSuit = 0
                    wearPajamas = 1
                    wearDenim = 0
                    wearNothing = 0

                elif options.upper() == "DENIM":
                    printOut("\nYou're feeling ordinary, so you put on some jeans and a shirt.")
                    wearSuit = 0
                    wearPajamas = 0
                    wearDenim = 1
                    wearNothing = 0

            elif options.upper() == "NO":

                if wearSuit == 0 and wearPajamas == 0 and wearDenim == 0:
                    printOut("You walk out of the closet, wearing nothing but your underwear.")
                    wearNothing = 1

                elif wearNothing == 0:
                    printOut("You walk out of the closet.")



        elif options.upper() == "BED":  # Bedroom Bed
            printOut("\nYou go back to bed. Sleep?\nYes    No")
            options = input()

            if options.upper() == "YES":

                def sleeping():
                    time.sleep(2)
                    printOut(".")
                    time.sleep(0.7)
                    printOut(".")
                    time.sleep(0.7)
                    printOut(".\n")
                    time.sleep(1.5)

                if sleptIn == 0:
                    printOut("You go back to bed.")
                    sleeping()
                    printOut("You wake up a couple of hours later.")
                    sleptIn = 1

                elif sleptIn == 1:
                    printOut("You lie in bed, but fail to fall asleep.")

                elif sleptIn == -1:
                    printOut("Despite refusing earlier, you decide to sleep. Just a little nap...")
                    sleeping()
                    printOut("You wake up a couple of hours later.")
                    sleptIn = 1
            elif options.upper() == "NO":

                if sleptIn == 0:
                    printOut("You probably shouldn't sleep, as tempting as it looks.")
                    sleptIn = -1
                elif sleptIn == 1:
                    printOut("You decide not to. You've already slept enough, better not waste time!")



        elif options.upper() == "WINDOW":  # Bedroom Window

            if windowOpen == 0:

                printOut("\nYou walk to the window. Open it?\nYes    No")
                options = input()

                if options.upper() == "YES":
                    printOut("You decide to let the cool breeze in.")
                    windowOpen = 1

                elif options.upper() == "NO":
                    printOut("You leave it closed.")
                    windowOpen = 0


            elif windowOpen == 1:
                printOut("\nYou walk to the opened window. Close it?\nYes    No")
                options = input()
                if options.upper() == "YES":
                    printOut("You regret your decision to open the window, and close it.")
                    windowOpen = -1

                elif options.upper() == "NO":
                    printOut("You leave it open.")


            elif windowOpen == -1:
                printOut("\nYou walk to the closed window. Re-open it?\nYes    No")
                options = input()
                if options.upper() == "YES":
                    printOut("\nYou re-open the window, welcoming the breeze back in.")
                    windowOpen = 1

                elif options.upper() == "NO":
                    printOut("\nYou leave it closed.")


        elif options.upper() == "DOOR":  # Bedroom Door
            printOut("\nExit your room?\nYes    No")
            options = input()

            if options.upper() == "YES":
                break

            elif options.upper().lower == "NO":
                printOut("\nYou take some more time to get ready for the day.")


# Prologue


printOut("This game is a comedy text-based adventure, based on the Loss comic. Yep, it's that bad.\n")
time.sleep(2)
printOut("Your actions actually do have consequences.\n")
time.sleep(2)
printOut("To pick options, type the word. Ignore parentheses.\n")
time.sleep(2)

options = input("Continue?\nYes    No\n")

if options.upper() == "no":
    exit(0)

time.sleep(2)
print("\n\n\n")

printOut("You wake up in a bed, not knowing where or who you are...\n")
time.sleep(2.5)
printOut("But then you remember where and who you are. \nYou're in your house, and your name is Ethan.")
time.sleep(3)
printOut("You're just a slow thinker.\n")
time.sleep(2)
printOut("You slowly raise yourself out of bed.\n")
time.sleep(2)

bedroom()
house()
kitchen()

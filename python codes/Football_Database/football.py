#!/usr/bin/python

# uses csv files from https://www.fantasyfootballdatapros.com/csv_files

def main():
        isRunning = True

        while(isRunning):
                print("Enter the year you would like to analyze.")
                valid = False

                while(valid is False):
                        year = int(input("Please select a year between 1970 and 2019: "))

                        if (year > 1969) and (year < 2020):
                                selection = "data/" + str(year) + ".csv"
                                valid = True
                        else:
                                print("\nInvalid input.\n")


                file = open(selection, "r")

                pYards = {}
                rYards = {}
                reYards = {}

                while not file.closed:
                        line = file.readline().rstrip()
                        if(line == ""):
                                file.close()
                        else:
                                fields = line.split(",")
                                if(fields[3] == "QB"):
                                        pYards[int(float(fields[9]))] = fields[1]
                                if(fields[3] == ("RB" or "QB")):
                                        rYards[int(float(fields[12]))] = fields[1]
                                if(fields[3] == ("WR" or "TE" or "RB")):
                                        reYards[int(float(fields[15]))] = fields[1]

                passer = 0
                rusher = 0
                receiver = 0

                for x in pYards:
                        if x > passer:
                                passer = x

                for x in rYards:
                        if x > rusher:
                                rusher = x

                for x in reYards:
                        if x > receiver:
                                receiver = x

                print("\n\tStatistics for " + str(year))
                print("-" * 35)
                print("Top passer: " + pYards[passer] + "   "
                + str(passer) + " yds")
                print("Top rusher: " + rYards[rusher] + "   "
                + str(rusher) + " yds")
                print("Top receiver: " + reYards[receiver] + "   "
                + str(receiver) + " yds")
                
                selection = input("\nWould you like to search another year?\nPlease enter yes or no: ")
                if(selection.upper() == "YES"):
                        isRunning = True
                else:
                        isRunning = False


main()

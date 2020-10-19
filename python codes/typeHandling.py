#python program checks if input is an int, float, or str
def main():
    user = input("Enter anything: ")
    try:
        usertype = int(user)
        print("You typed in an int: ", usertype)
    except ValueError:
        try:
            usertype = float(user)
            print("You typed in a float: ", usertype)
        except ValueError:
            print("You typed in a string input")
main()
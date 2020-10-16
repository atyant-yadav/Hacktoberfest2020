import books_manager

def add_book():
    name = input("Enter book title: ")
    author = input("Enter book author: ")
    book = {'title': name, 'author': author}
    books_manager.addBook(book)


def list_all_books():
    for book in books_manager.listAllBooks():
        print(f"=> {book['title'].title()} by {book['author'].title()}")


def read_unread_book(b):
    name = str(input("Enter the name of book you want to read: ")) if b else str(input("Enter the name of book you "
                                                                                       "want to finish reading off: "))
    book = books_manager.readAndUnreadBook(name, b)
    if book['read']:
        print(f"\nYou are currently reading -> {book['title']} by {book['author']}")
    else:
        print(f"\nYou have just finished reading -> {book['title']} by {book['author']}")


def delete_book():
    name = str(input("Enter the name of book you want to delete: "))
    books_manager.deleteBook(name)


def initialise():
    print('\nEnter "a" to add book\nEnter "r" to read book\nEnter "f" to finish reading book\nEnter "d" to delete '
          'book\nEnter "l" to get all books\nEnter "q" to quit\n')
    choice = input("Enter your choice: ")
    print()
    if choice != 'q':
        if choice == 'a':
            add_book()
        elif choice == 'l':
            list_all_books()
        elif choice == 'r':
            read_unread_book(True)
        elif choice == 'd':
            delete_book()
        elif choice == 'f':
            read_unread_book(False)
        else:
            print("Invalid Choice")
        initialise()
    else:
        pass


initialise()

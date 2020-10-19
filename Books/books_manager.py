import sqlite3


def createLibrary():
    with sqlite3.connect('server.db') as connection:
        cursor = connection.cursor()
        cursor.execute('CREATE TABLE IF NOT EXISTS book(title text, author text, read boolean)')
        connection.commit()


createLibrary()


def throwError(message):
    raise Exception(message)


def throwSoftError(message):
    print(f"\n<==========>{message}<==========>")


def addBook(book):
    if book['title'] and book['author']:
        with sqlite3.connect('server.db') as connection:
            cursor = connection.cursor()
            cursor.execute("INSERT INTO book VALUES(?, ?, FALSE )", (book['title'], book['author']))
            connection.commit()
    else:
        throwSoftError("You just missed to fill fields.")


def listAllBooks():
    with sqlite3.connect('server.db') as connection:
        cursor = connection.cursor()
        cursor.execute('SELECT * FROM book')
        books = ({'title': book[0], 'author': book[1], 'read': book[2]} for book in cursor.fetchall())
        return books


def readAndUnreadBook(key, r):
    with sqlite3.connect('server.db') as connection:
        cursor = connection.cursor()
        if not r:
            cursor.execute('SELECT read FROM book WHERE title =?', (key,))
            previous_reading_state = bool(cursor.fetchall()[0][0])
            if r == previous_reading_state:
                throwError("You never started reading this book.")

        cursor.execute('UPDATE book SET read = ? WHERE title = ?', (r, key,))
        cursor.execute('SELECT * FROM book WHERE title =?', (key,))
        book = cursor.fetchall()[0]
        connection.commit()
        return {'title': book[0], 'author': book[1], 'read': book[2]}


def deleteBook(key):
    if key:
        with sqlite3.connect('server.db') as connection:
            cursor = connection.cursor()
            cursor.execute('DELETE FROM book WHERE title = ?', (key,))
            connection.commit()
    else:
        throwSoftError("You need to enter the name of book to delete it.")

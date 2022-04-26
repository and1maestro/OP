import pickle

class Work:

    def __init__(self, name: str, date_of_finishing: int, date_of_publication: int):
        self.name = name
        self.date_of_finishing = date_of_finishing
        self.date_of_publication = date_of_publication

    def __str__(self):
        info = f"{self.name}, date of finishing: {self.date_of_finishing}, date of publication: {self.date_of_publication}"
        return info

def create_first_file(file_name: str, n: int):
    file_mode = "wb"
    book_list = list()
    for i in range(n):
        print(f"Book {i+1}:")
        name = input("Enter the name of the book: ")
        date_of_finishing = input("Enter the date of finishing: ")
        date_of_publication = input("Enter the date of publication: ")
        book = Work(name, date_of_finishing, date_of_publication)
        book_list.append(book)
    with open(file_name, file_mode) as file:
        pickle.dump(book_list, file)


def create_second_file(file_name_1: str, file_name_2: str):
    with open(file_name_1, "rb") as file:
        book_list = pickle.load(file)
    recent_books = list()
    for book in book_list:
        year = int(book.date_of_finishing)
        if 2022 - year < 5:
            recent_books.append(book)
    with open(file_name_2, "wb") as file:
        pickle.dump(recent_books, file)


def output_difference(file_name: str):
    with open(file_name, "rb") as file:
        book_list = pickle.load(file)
    late_books = list()
    for book in book_list:
        if int(book.date_of_publication) - int(book.date_of_finishing) > 5:
            late_books.append(book)
    for book in late_books:
        print(book)


def output_file(file_name: str):
    with open(file_name, "rb") as file:
        book_list = pickle.load(file)
    for book in book_list:
        print(book)
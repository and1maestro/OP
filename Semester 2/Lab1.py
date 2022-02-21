# -*- coding: cp1251 -*-

def input_text_in_file(file_name):
    with open(file_name, "w") as my_file:
        print("Enter text(��� �������� ��������, ������ � ������ ����� ctrl + Z � ��������� ������� enter):")
        try:
            while(True): 
                my_file.write(input() + "\n")
        except EOFError:
            pass
    pass

def output_text_from_file(file_name):
    print("\n���� ����� " + file_name + ":")
    with open(file_name, "r") as my_file:
        print(my_file.read())
    pass

def find_words_with_symbol(filename, symbol):
    with open(filename, "r") as myfile:
        text = ""
        for x in myfile:
            text = text + x + "\n"
    return text

def input_words_in_new_file(new_filename, text):
    with open(new_filename, "w") as newfile:
        newfile.write(text)

file_name = "111.txt"
input_text_in_file(file_name)
output_text_from_file(file_name)

symbol = input("������ ������ �����: ")
words_with_symbol = find_words_with_symbol(file_name, symbol)
print("\n�����, �� ����������� �� ������ �����:\n" + words_with_symbol + "\n")

new_file_name = "new_file.txt"
input_words_in_new_file(new_file_name, words_with_symbol)
output_text_from_file(new_file_name)
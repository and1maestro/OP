# -*- coding: cp1251 -*-

def input_text_in_file(file_name):
    with open(file_name, "w") as my_file:
        print("Enter text(щоб зупинити введення, зажміть у новому рядку ctrl + Z і підтвердіть клавішою enter):")
        try:
            while(True): 
                my_file.write(input() + "\n")
        except EOFError:
            pass
    pass

def output_text_from_file(file_name):
    print("\nВміст файлу " + file_name + ":")
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

symbol = input("Введіть бажану літеру: ")
words_with_symbol = find_words_with_symbol(file_name, symbol)
print("\nСлова, що починаються на задану літеру:\n" + words_with_symbol + "\n")

new_file_name = "new_file.txt"
input_words_in_new_file(new_file_name, words_with_symbol)
output_text_from_file(new_file_name)
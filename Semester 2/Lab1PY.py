def input_text_in_file(filename):
    with open(filename, "w") as myfile:
        print("Enter text (to stop typing, press Ctrl + Z and confirm with Enter):")
        try:
            while(True): 
                myfile.write(input() + "\n")
        except EOFError:
            pass
    pass

def output_text_from_file(file_name):
    print("\nContents of " + file_name + ":")
    with open(file_name, "r") as myfile:
        print(myfile.read())
    pass

filename = "111.txt"
input_text_in_file(filename)
output_text_from_file(filename)

def delete_spaces(filename):
    with open(filename, "r") as myfile:
        text = ""
        for x in myfile:
            s = x
            while "  " in x:
                x = x.replace("  ", " ")
            x = x.strip()
            c = len(s) - len(x)
            text = text + x + " " + str(c) + "\n"
    return text

def input_words_in_new_file(new_filename, text):
    with open(new_filename, "w") as newfile:
        newfile.write(text)

text = delete_spaces(filename)
new_filename = "new_file.txt"
input_words_in_new_file(new_filename, text)
output_text_from_file(new_filename)

your_text = input()

def minmax(text):
    CharNum = ""
    minn = len(text)
    maxx = 0
    min = ""
    max = ""
    for i in text:
        if i not in CharNum:
            if text.count(i) > maxx:
                maxx = text.count(i)
                max = str(i)
            elif text.count(i) == maxx:
                max = max + " " + str(i)
            if text.count(i) < minn:
                minn = text.count(i)
                min = str(i)
            elif text.count(i) == minn:
                min = min + " " + str(i)
            CharNum = CharNum + i
    result = "Max: " + max + " " + str(maxx) + " time(s)" + "\n" + "Min: " + min + " " + str(minn) + " time(s)"
    return result

res = minmax(your_text)
print(res)
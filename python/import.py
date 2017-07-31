from sys import argv

script , text = argv

txt = open(text , 'w')

print("ttype what you want\n")

line1 = input("line 1: ")
line2 = input("line 2: ")


txt.write(line1)
txt.write(line2)


txt.close()

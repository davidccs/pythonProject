# this is a link list written in python

class link:
    def __init__(self):
        self.item = []

    # appends value onto list
    def appendValue(self, item):
        self.item.append(item)

    #deletes value position value given
    def deleteValue(self, position):
        self.item.pop(position)

    # prints value
    def printValue(self):
        print("first value = %d " % self.item[0])

def Listlink():
    linkList = link()
    linkList.appendValue(3)
    #print("first value = %d " % linkList.printValue())
    linkList.appendValue(4)
    linkList.deleteValue(0)
    linkList.printValue()

def firstSol(list):
    # sorting the list to be in ascending order
    i = 0
    while i != len(list):
        if list[i] >= list[i+1]:
            temp = list[i]
            list[i] = list[i+1]
            list[i+1] = temp
        if i-1 == len(list):
            break
        i = i + 1

def main():
    #Listlink()
    list = [10,3,4,5,6,2,6,4,2,5,6,7,2]
    firstSol(list)


if __name__ == "__main__":
    main()

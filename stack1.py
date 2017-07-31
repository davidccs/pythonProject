import unittest

class stack:
	def __init__(self):
		self.items = []

	def push(self, item):
		return self.items.append(item)

	def pop(self):
		return self.items.pop()

	def checkStack(self):
		if self.items[0] != None:
			for i in self.items:
				print ("%d " % self.items[i-1])
		else:
			print("Empty Stack")
	def sizeOfStack(self):
		return len(self.items)





s = stack()
s.push(1)
s.push(2)
print("is = %d " % s.sizeOfStack())
s.checkStack()
s.pop()
s.checkStack()


#s.pop()

#unittest.main()
#s.pop()
#s.checkStack()

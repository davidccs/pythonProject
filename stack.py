class Stack(object):
	def __init__(self):
		self.items = []

	def isEmpty(self):
		return self.items == []

	def push(self, item):
		return self.items.append(item)

	def pop(self):
		return self.items.pop()

	def peek(self):
		return self.items[len(self.items)-1]

	def size(self):
		return len(self.items)


def main():

	s = Stack()
	print(s.isEmpty())
	s.push(3)
	s.push(4)
	print(s.size())

if __name__ == "__main__":
	main()							
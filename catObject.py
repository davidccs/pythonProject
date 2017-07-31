class cat(object):
	def __init__(self, name, weight, color):
		self.name = name
		self.weight = weight
		self.color = color		

	def name_print(self):
		print ('the cat is %s' % cat.name)

	def meow(self):
		print ('meow')	

class babycat(object):
	def __init__(self,name,weight,color, new):
		self.name = name
		self.weight = weight
		self.color = color
		self.new = new	

class old_cat(cat,babycat):
	def __init__(self,name,weight,color,illness):
		cat.__init__(self,name,weight,color)
		babycat.__init__(self,name,weight,color, new)
		#super().__init__()
		#self.new = new
		self.illness = illness

	def has_illness(self):
		if self.illness != 'none':
			print('your cat is sick\n')
		else:
			print('your cat is fine')	

	
def main():
	lol = babycat('d', 4, 'urple', 3)
	lol.new = 3

	ruth = old_cat('ruth', 5, 'red', 'is sick')
	ruth.has_illness()
	ruth.meow()

if __name__ =='__main__':		
	main()
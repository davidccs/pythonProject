class Door(object):
    def __init__(self, color):
        self.color = color

    def door_open(self, open):
    	self.open     

class Whiteboard(object):
    def __init__(self, default_text=''):
        self.text = ''
        self.write_text(default_text)

    def write_text(self, text):
        self.text += text

    def erase(self):
        self.text = ''


class Room(object):
    def __init__(self, doorcolor, whiteboardtext=''):
        self.whiteboard = Whiteboard(whiteboardtext)
        self.door = Door(doorcolor)



def main():

	door1 = Door('blue')
		# make a room with a red door and no text on the whiteboard
	room1 = Room('red')

	# make a room with a blue door and 'yeah, whiteboard' on the whiteboard
	room2 = Room('blue', 'yeah, whiteboard')

	room4 = Room('red colour', 'fuck school')

	# make a room with a green door
	room3 = Room('green')

	print 'the writing in room2 is ' + room2.whiteboard.text

	print 'door1 is color ' + door1.color

	print 'room 4 says ' + room4.whiteboard.text

	print ('#############')

	room4.whiteboard.write_text('mudda hel')

	print ('after erasing room4 board it says = ' + room4.whiteboard.text)

	# now I can play around with my 'rooms' and they keep track of everything internally

	print 'room 1 door color: ' + room1.door.color
		

if __name__ == "__main__":
	main()		
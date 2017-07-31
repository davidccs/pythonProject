from PIL import Image
from playsound import playsound


def main():

	image = Image.open('invent.jpg')
	s = sound()
	
	if image is not None:
		image.show('invent.jpg')
	else:
		print('Unsuccessful\n')	
		s.read('sound.wav')
		s.play()

if __name__ == "__main__":
	main()
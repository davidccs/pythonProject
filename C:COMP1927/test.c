#include <stdio.h>
#include <stdlib.h>


void optionsUI();
int main (int argc, char **argv){



	char character = 'Q';
	char command = ' ';

	optionsUI();

	scanf("%c", &command);

	if (command == character){
		printf("terminate\n");
	}
	if (command == 'I'){
		printf("Opening inventory\n");
	}
	if (command == 'M'){
		printf("Opening Maps\n");
	}
	if (command == 'S'){
		printf("Opening Stats\n");
	}
	if (command == 'E'){
		printf("Opening Equips\n");
	} else {
		printf("Invalid Please Retry\n");
	}
}


void optionsUI(){
	printf("I to Open Inventory\n");
	printf("M to Open Maps\n");
	printf("S to check Stats \n");
	printf("E to open Equips\n");
	printf("Q to quit\n");
}
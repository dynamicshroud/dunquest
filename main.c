#include <stdio.h>
#include "game.h"

void loop(){
	
	do {
		int c = getchar();
		parse(c);	
	} while(1);

}

int main(){
	
	loop();
	
	return 0;
}

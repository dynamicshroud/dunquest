#include <stdio.h>
#include "game.h"

void loop();

void loop(){
	struct player pl;
	// defaults
	pl.life = 10;
	pl.strength = 1;
	pl.maxweight = 20;

	if(check_for_savefile() == 0){
		create_savefile(pl.life, pl.strength, pl.maxweight);
	}
}

int main(){
	loop();
}

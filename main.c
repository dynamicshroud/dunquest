#include <stdio.h>
#include "game.h"

void loop(){
	struct room r = gen_room();
	
	do {
		int c = getchar();
		parse(c, r);
		int i = iscollide(r.ox, r.oy, pl.x, pl.y);
		printf("%d", i);
	} while(1);
}

int main(){
	
	loop();
	
	return 0;
}

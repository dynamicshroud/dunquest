#include "game.h"
#include <unistd.h>
#include <stdio.h>
#include <time.h> // for seed generation


void heal(int life, int amount){
	life = life + amount;
}

void damage(int life, int amount){
	life = life - amount;
}

void devstr(int str, int amount){
	str = str + amount;
}

void decstr(int str, int amount){
	str = str - amount;
}

void dmgenm(int life, int amount){
	life = life - amount;
}

void log(const char* info){
	puts(info);
}

void move_up(int y){
	y = y + 1;
}

void move_down(int y){
	y = y - 1;
}

void move_left(int x){
	x = x - 1;
}

void move_right(int x){
	x = x + 1;
}

struct room gen_room(){
	/* rooms will always be rectangular to avoid more work :/ */
	
	time_t seed;
        srand((unsigned)time(&seed));

        int rx = rand() % (23 + 1 - 3);
        int ry = rand() % (13 + 1 - 3);
        int addup = rand() % (6 + 1 - 1) + 1;

        if(rx == 0) { rx = rx + addup; }
        if(ry == 0) { ry = ry + addup; }

	struct room r = {rx, ry, rx+2, ry+2};
	return r;
	

}

int iscollide(int wx, int wy int x, int y){
	// find position of player through parameters
	// and detect if coords are equal to wall. if
	// so, then return 1. if not, return 0.
	
	
	if(x == wx){
		x = x - 1;
		return 1;
	}
	if(y == wy){
		y = y - 1;
		return 1;
	}
	if((x == wx) && (y == wy)){
		x = x - 1;
		y = y - 1;
		return 1;
	}
	
	return 0;
}

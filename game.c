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

void equip(){
	// TODo
}
struct room gen_room(){
	/* rooms will always be rectangular to avoid more work :/ */
	
	
	time_t seed;
        srand((unsigned)time(&seed));
        
        int rx = rand() % 23;
        int ry = rand() % 13;
        
        int addup = rand() % (6 + 1 - 1) + 1;

        if(rx < 2) { rx = rx + addup; }
        if(ry < 2) { ry = ry + addup; }

	struct room r = {rx, ry, rx+2, ry+2};
	return r;
	

}

/* this just returns an int bool (0, 1) */
int iscollide(int ix, int iy, int x, int y){
	// find position of player through parameters
	// and detect if coords are equal to wall. if
	// so, then return 1. if not, return 0.

        if(x > ix){
                return 1;
        }
        else if(y > iy) {
                return 1;
        } else {
	        return 0;
        }
}

void parse(int input, struct room r){
		int i = iscollide(r.ix, r.iy, pl.x, pl.y);
		
                /* move commands */
                if(input == 119){ pl.y++; printf("y: %d\n", pl.y); } // w
                if(input == 97){ pl.x--; printf("x: %d\n", pl.x);  } // a
                if(input == 115){ pl.y--; printf("y: %d\n", pl.y); } // s
                if(input == 100){ pl.x++; printf("x: %d\n", pl.x); } // d
                
                
                /* basic commands */
                if(input == 99) { // c
                        printf("LIFE %d\n", pl.life);
                        printf("STR %d\n", pl.strength);
                        printf("MAXW %d\n", pl.maxweight);
                        printf("X %d\n", pl.x);
                        printf("Y %d\n", pl.y);
                        printf("WX %d\n", r.ox);
                        printf("WY %d\n", r.oy);
                        printf("IC %d\n", i);
                }

        /*
         * TODO: Get this function to parse commands that can move the
         * TODO: Get this function to parse commands that can use items
         */
}

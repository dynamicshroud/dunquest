#include "game.h"
#include <unistd.h>
#include <stdio.h>
#include <time.h> // for seed generation
#include <stdlib.h>


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
	str = str -  amount;
}

void equip(){
	// TODO
}
struct room gen_room(){
	/* rooms will always be rectangular to avoid more work :/ */
	
	
	time_t seed;
        srand((unsigned)time(&seed));
        
        int rx = rand() % 23;
        int ry = rand() % 13;
        
        int addup = rand() % 7;

        if(rx < 2) { rx = rx + addup; }
        if(ry < 2) { ry = ry + addup; }

	struct room r = {rx, ry, rx+2, ry+2};
	return r;
	

}

/* this just returns an int bool (0, 1) */
int iscollide(int i, int c){
	// find position of player through parameters
	// and detect if coords are equal to wall. if
	// so, then return 1. if not, return 0.

        if(c > i){
                return 1;
        } else {
                return 0;
        }	
}

void parse(int input, struct room r){
		int cx = iscollide(r.ix, pl.x);
		int cy = iscollide(r.iy, pl.y);
		
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
                        printf("CX %d\n", cx);
                        printf("CY %d\n", cy);
                }
        /* this'll also detect IC then lower its value until IC = 0*/
                if(cx == 1){
                        do {
                                cx = iscollide(r.ix, pl.x);
                                pl.x--;
                        } while(cx == 1);
                }
                if(cy == 1){
                        do {
                                cy = iscollide(r.iy, pl.y);
                                pl.y--;
                        } while(cx == 1);
                }
        /*
         * TODO: Get this function to parse commands that can move the
         * TODO: Get this function to parse commands that can use items
         */
}

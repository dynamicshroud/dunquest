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
	
	time_t seed;
        srand((unsigned)time(&seed));
        
        int rx = rand() % 23;
        int ry = rand() % 13;
        
        int addup = rand() % 7;
        
        if(rx < 2) { rx = rx + addup; }
        if(ry < 2) { ry = ry + addup; }

        int dx = rx + rand() / (RAND_MAX / (rx+2 - rx + 1) + 1);
        int dy = ry + rand() / (RAND_MAX / (ry+2 - ry + 2) + 1);
        
	struct room r = {rx /*inner x*/, ry /*inner y*/, rx+2 /*outer x*/, ry+2 /*outer y*/, dx /*door x*/, dy /*door y*/};
	
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
                        printf("LIFE %d | ", pl.life);
                        printf("STR %d | ", pl.strength);
                        printf("MAXW %d\n", pl.maxweight);
                        printf("X %d | ", pl.x);
                        printf("Y %d | ", pl.y);
                        printf("WX %d | ", r.ox);
                        printf("WY %d | ", r.oy);
                        printf("CX %d | ", cx);
                        printf("CY %d\n", cy);
                        printf("DX %d | ", r.dx);
                        printf("DY %d\n", r.dy);
                }
                
                // TODO: DEVELOP A DOOR SYSTEM BUT DONT GET RID OF COLLISION
                if(pl.x < 2){
                        do {
                                pl.x++;
                        } while(pl.x < 2);
                }
                
                if(pl.y < 2){
                        do {
                                pl.y++;
                        } while(pl.y < 2);
                }
                
                if((pl.x == r.dx) && (pl.y == r.dx)){
                        r = gen_room();
                }
                
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
                        } while(cy == 1);
                }
                
        /*
         * TODO: Get this function to parse commands that can move the
         * TODO: Get this function to parse commands that can use items
         */
}
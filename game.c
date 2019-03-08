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
        
        int choice = rand() % 4; // 5 room selections
        int opc = rand() % 1; // if 0 then add if 1 then subtract
        int opn = rand() % 4; // to add randomness, we add or subtract the variable by opn so we give the room some RANDOM
        
        int x, y, dx, dy;
        
        // coords
        switch(opc){
                case 0:
                     x = Defaults[choice].x + opn;
                     y = Defaults[choice].y + opn;
                     break;
                case 1:
                     x = Defaults[choice].x - opn;
                     y = Defaults[choice].y - opn;
                     break;
                default:
                     break;
        }
        
        // doors
        int dchoice = rand() % 3; // 4 possibilities
        /*
        * chances:
        * dx = x and dy = ? (0 to y) ( right side )
        * dx = ? (0 to x) and dy = y ( up side )
        * dx = 1 and dy = ? (0 to y) ( left side )
        * dx = ? (0 to x) and dy = 1 ( down side )
        */
        switch(dchoice){
                case 0: // right
                        dx = x + 2;
                        dy = rand() % y+2;
                        if(dy <= 0){
                                dy += 2;
                        }
                        break;
                case 1: // up
                        dx = rand() % x+2;
                        dy = y+2;
                        if(dx <= 0){
                                dx += 2;
                        }
                        break;
                case 2:
                        dx = 1;
                        dy = rand() % y+2;
                        if(dy <= 0){
                                dy += 2;
                        }
                        break;
                case 3:
                        dx = rand() % x+2;
                        dy = 1;
                        if(dx <= 0){
                                dx += 2;
                        }
                        break;
        }
        
        struct room r = {x, y, dx, dy};                 
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

/* returns an int bool (0, 1) */
int isdoor(int x, int y, int dx, int dy){
        if((dx == x) && (dy == y)){
                return 1;
        } else {
                return 0;
        }
}

void parse(int input){
		
		struct room r = gen_room();
		
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
                        printf("WX %d | ", r.x+2);
                        printf("WY %d | ", r.y+2);
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
                int cx = iscollide(r.x, pl.x);
                int cy = iscollide(r.y, pl.y);
                int dc = isdoor(pl.x, pl.y, r.x, r.y);
                
                if(cx == 1){
                        do {
                                cx = iscollide(r.x, pl.x);
                                pl.x--;
                        } while(cx == 1);
                }
                
                if(cy == 1){
                        do {
                                cy = iscollide(r.y, pl.y);
                                pl.y--;
                        } while(cy == 1);
                }
                
                if((cx == 1) || (cy == 1)){
                         if(dc == 1){
                                 r = gen_room(); // trying to generate new room
                         }       
                }
        /*
         * TODO: Get this function to parse commands that can move the
         * TODO: Get this function to parse commands that can use items
         */
}
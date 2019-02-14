#include "game.h"
#include <unistd.h>
#include <stdio.h>

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

int check_for_savefile(){
	if(access("savefile", F_OK) != -1){
		return 1;
	} else {
		return 0;
	}
}

void create_savefile(int life, int strength, int maxweight){
	FILE *f = fopen("savefile", "w");
	fprintf(f, "%i\n", life);
	fprintf(f, "%i\n", strength);
	fprintf(f, "%i\n", maxweight);
	fclose(f);
}

void read_savefile(){
	
}

struct room mkroom(){
	struct room r;
	r.x = 0;
	r.y = 0;
	r.type = std;
	return r;
}


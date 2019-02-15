#ifndef GAME_H
#define GAME_H

struct player {
	int life;
	int strength;
	int maxweight;
	
};

struct item {
	const char* name;
	int weight;
	int power;	
} 	const Weapons[] = { {"Sword", 5, 2}, {"Club", 5, 4}, {"Dagger", 2, 2}, {"Longsword", 10, 7}  },
	
	Potions[] = { {"SmallHealth", 0, 5}, {"BigHealth", 0, 10}, {"StrengthBoost", 0, 3}, {"SuperStrengthBoost", 0, 5} };


struct enemy {
	char* name;
	int life; 
	int power;
};


struct room {
	int x;
	int y;
	int type; // gonna be an enum
};

enum roomtypes {
	std = 0, // normal room
	fld = 2 // flooded room (water)
};

//void log(const char*); // log info (TODO)
void heal(int, int); // increase life 
void damage(int, int); // decrease life
void devstr(int, int); // increase strength
void decstr(int, int); // decrease strength
void dmgenm(int, int); // damage enemy
struct item additm(struct item, char*, int, int); // declare item

/* savefile stuff */
int check_for_savefile(); // check
void create_savefile(int, int, int); // create a game file to read from for next visit
void read_savefile(); // reading savefile after it was created

/* movements */
void move_up();
void move_down();
void move_left();
void move_right();

#endif /* game.h */

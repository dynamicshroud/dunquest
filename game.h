#ifndef GAME_H
#define GAME_H

struct player {
	int life;
	int strength;
	int maxweight;
	int x;
	int y;
} static pl = {30, 0, 20, 2, 2}; // default player count


struct item {
	const char* name;
	int weight;
	int power;	
} static Weapons[] = { {"Sword", 5, 5}, {"Longsword", 7, 7}, {"Dagger", 3, 2}, {"Fist", 0, 1}, {"Club", 5, 6}, {"SpikedClub", 5, 7} },
	 Potions[] = { {"SmallHealth", 0, 5}};

struct enemy {
	char* name;
	int life; 
	int power;
} static Enemies[] = { {"Orc", 10, 5}, {"Troll", 7, 3} };

/* 
 * TODO: find a way to generate a room that you can control
 * TODO: find a way to generate a dungeon that has rooms in it
 * TODO: get sleep
 * TODO: random number generators for item generator!!!!
 */
struct room {
	int ix; // flooring
	int iy; 
	int ox; // walls
	int oy;	
};

/* functions !!! */
void heal(int, int); // increase life 
void damage(int, int); // decrease life
void devstr(int, int); // increase strength
void decstr(int, int); // decrease strength
void equip(); // equip item from Weapons[]
/* room stuff */
struct room gen_room();
int iscollide(int, int);

/* input */
void parse(int, struct room); // TODO
#endif /* game.h */

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
	int x; // 2d coords
	int y; 
	int dx; // door location
	int dy;	
} static Defaults[] = { {22, 7, 0, 0}, {14, 12, 0, 0}, {14, 9, 0, 0}, {19, 8, 0, 0}, {14, 9, 0, 0} }; // these defaults will be randomly selected when calling gen_room() also TODO

/* functions !!! */
void heal(int, int); // increase life 
void damage(int, int); // decrease life
void devstr(int, int); // increase strength
void decstr(int, int); // decrease strength
void equip(); // equip item from Weapons[]
/* room stuff */
struct room gen_room();
int iscollide(int, int);
void room_routine(); // this'll be used to constantly edit the room variable whenever the player uses a door
/* input */
void parse(int); // TODO
#endif /* game.h */

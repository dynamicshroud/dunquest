#ifndef GAME_H
#define GAME_H

#include <stdio.h> // for NULL
struct player {
	int life;
	int strength;
	int maxweight;
	int x;
	int y;
} static pl = {30, 0, 20, 2, 2}; // default player count

struct item {
	char* name;
	int weight;
	int power;	
	int ispotion; // (0,1) is this a potion?
} static Items[] = { {"Sword", 5, 5, 0}, {"Longsword", 7, 7, 0}, {"Dagger", 3, 2, 0}, {"Fist", 0, 1, 0}, {"Club", 5, 6, 0}, {"SpikedClub", 5, 7, 0}, {"SmallHealth", 0, 5, 1}, {"BigHealth", 0, 5, 1} };

struct enemy {
	char* name;
	int life; 
	int power;
} static Enemies[] = { {"Orc", 10, 5}, {"Troll", 7, 3} };

/* 
 * TODO: get sleep
 * TODO: random number generators for item generator!!!!
 */

struct room {
	// actual room stuff
	int x; // 2d coords
	int y; 
	int dx; // door location
	int dy;
	struct item genitem; // generated item
	int ix; // item location
	int iy;
	/*
	* item types:
	* 0 - no items
	* 1 - weapon
	* 2 - potion
	*
	* enemy types:
	* 0 - no enemy
	* 1 - enemy
	*/	
} static Defaults[] = { {22, 7, 0, 0, NULL, 0, 0}, {14, 12, 0, 0, NULL, 0, 0}, {14, 9, 0, 0, NULL, 0, 0}, {19, 8, 0, 0, NULL, 0, 0}, {14, 9, 0, 0, NULL, 0, 0} }; // these defaults will be randomly selected when calling gen_room()

/* functions !!! */
void heal(int, int); // increase life 
void damage(int, int); // decrease life
void devstr(int, int); // increase strength
void decstr(int, int); // decrease strength
void equip(struct player, struct item); // equip item from Weapons[]
/* room stuff */
struct room gen_room();
int iscollide(int, int);
int isdoor(int, int, int, int); // is player pos == door pos
int isitem(int, int, int, int); // is player pos == item pos
/* input */
void parse(int); // TODO
#endif /* game.h */

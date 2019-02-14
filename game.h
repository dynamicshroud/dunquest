struct player {
	int life;
	int strength;
	int maxweight;
	
};

struct item {
	char* name;
	int weight;
	int power;	
};

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

struct room mkroom();
void log(const char*); // log info (TODO)
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

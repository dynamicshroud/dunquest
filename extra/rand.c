#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	time_t seed;
        srand((unsigned)time(&seed));

        int rx = rand() % (23 + 1 - 3);
        int ry = rand() % (13 + 1 - 3);
        int addup = rand() % (6 + 1 - 1) + 1;
        
        if(rx == 0) { rx = rx + addup; }
	if(ry == 0) { ry = ry + addup; }

        printf("x:%d and y:%d", rx, ry);
}

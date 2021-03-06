#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

extern int ary[8];
extern int count;
extern int float_pos;
void print_bits(void *);
int DispElement(void *Mem, int n)
{
	int read = 0;
    int printed = 0;

	if (n)
		system("clear");
	if (n)
		printf(BOLDMAGENTA "\t\tDISPLAY ELEMENTS\n" RESET);
	printf("The Store contains : \n");
	if (*ary < 1 || *ary > 4) {
		printf("NOTHING\n");
	}
	for(int i = 0; i < count; i++) {
		if (1 == *(ary + i)) {
			printf("%d. (int)   : " BOLDRED "%d\n" RESET, i+1, (int)(*(long *)Mem >> read)); 
			read += 32;
		} else if (2 == *(ary + i)) {
			printf("%d. (char)  : " BOLDRED "%c\n" RESET, i+1, (char)(*(long *)Mem >> read)); 
			read += 8;
		} else if (3 == *(ary + i)) {
			for (int j = 0; j <= float_pos; j++) {
                if (printed == 2)
                    break;
		        if (*(ary + i) == 3)    
                    printf("%d. (float) : " BOLDRED "%f\n" RESET, j + 1, (*((float *)Mem + j))); 
			read += 32;
            ++printed;
			}
        
        } else if (4 == *(ary + i)) {
			printf("%d. (double) : " BOLDRED "%lf\n" RESET, i+1, (*(double *)Mem)); 
			read += 64;
		}
	}
}

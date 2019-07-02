#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>
#include <ctype.h>

struct ascii_map {
	char a;
	int equ;
};

struct ascii_map map[] = {
	{'a', 10},
	{'b', 11},
	{'c', 12},
	{'d', 13},
	{'e', 14},
	{'f', 15},
	{'1', 1},
	{'2', 2},
	{'3', 3},
	{'4', 4},
	{'5', 5},
	{'6', 6},
	{'7', 7},
	{'8', 8},
	{'9', 9},
};

int main(int argc, char *argv[])
{
	int j=0,i=0;
	bool found = false;
	char *octet = NULL;
	char *res = NULL;
	uint8_t mac[6] = {0};

	if(argc != 2)
		return -1;
	if(strlen(argv[1]) != 17) {
		printf("Wrong MAC address format\n");
		return -1;
	}

	octet = strtok_r(argv[1], ":",&res);
	while(NULL != octet) {
		if(isalpha(octet[0]))
			octet[0] = tolower(octet[0]);
		if(isalpha(octet[1]))
			octet[1] = tolower(octet[1]);
		for(i=0; i<16; i++) {
			if(octet[0] == map[i].a) {
				mac[j] |= ((map[i].equ << 4) & 0xFF);
				found = true;
				break;
			}
		}
		if(!found) {
			printf("Wrong MAC address format\n");
			return -1;
		}
		found = false;
		for(i=0; i<16; i++) {
			if(octet[1] == map[i].a) {
				mac[j] |= ((map[i].equ) & 0xF);
				found = true;
				break;
			}
		}
		if(!found) {
			printf("Wrong MAC address format\n");
			return -1;
		}
		found = false;
		j++;
		octet = strtok_r(res, ":",&res);
	}
	printf("%.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	return 0;
}

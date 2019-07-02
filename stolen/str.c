#include<stdio.h>
#include<stdint.h>
#include<string.h>

#define FAIL -1
#define SUCCESS 0
static inline int char2addr(char* addr)
{
    int i;
    int values[6];

    if(6 == sscanf(addr,"%2x:%2x:%2x:%2x:%2x:%2x%*c",
                &values[0], &values[1], &values[2],
                &values[3], &values[4], &values[5])) {
        for(i = 0; i < 6; i++) {
            addr[i] = (uint8_t) values[i];
        }
    } else {
        return FAIL;
    }
	printf("%x:%x:%x:%x:%x:%x\n",(unsigned char)addr[0],(unsigned char)addr[1],(unsigned char)addr[2],(unsigned char)addr[3],(unsigned char)addr[4],(unsigned char)addr[5]);
    return SUCCESS;
}

int main(int argc, char *argv[])
{
	char *mac = argv[1];
	uint8_t addr[6];

	char2addr(mac);
	memcpy((void *)addr, mac, 6);
	printf("%x:%x:%x:%x:%x:%x\n",(unsigned char)addr[0],(unsigned char)addr[1],(unsigned char)addr[2],(unsigned char)addr[3],(unsigned char)addr[4],(unsigned char)addr[5]);
	return 0;
}

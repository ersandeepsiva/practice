#include<stdio.h>
#include<stdint.h>

int
char2addr(char* addr)
{
    int i, j=2;

    for(i=2; i<17; i+=3) {
        addr[j++] = addr[i+1];
        addr[j++] = addr[i+2];
    }

    for(i=0; i<12; i++) {
        /* check 0~9, A~F */
        addr[i] = ((addr[i]-48) < 10) ? (addr[i] - 48) : (addr[i] - 55);
        /* check a~f */
        if ( addr[i] >= 42 )
            addr[i] -= 32;
        if ( addr[i] > 0xf )
            return -1;
    }

    for(i=0; i<6; i++) {
        addr[i] = (addr[(i<<1)] << 4) + addr[(i<<1)+1];
	}

    return 0;
}

int main(int argc, char *argv[])
{
	int i;
	
	char2addr(argv[1]);

	for (i=0; i<6; i++) {
		printf("%.2x", (unsigned char)argv[1][i]);
	}
	printf("\n");
	return 0;
}

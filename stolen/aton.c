#include<stdio.h>
#include<string.h>
#include<stdint.h>
static int hex2num(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	return -1;
}
/*int hex2byte(const char *hex)
{
	int a, b;
	a = hex2num(*hex++);
	if (a < 0)
		return -1;
	b = hex2num(*hex++);
	if (b < 0)
		return -1;
	return (a << 4) | b;
}*/
/**
 * hwaddr_aton - Convert ASCII string to MAC address (colon-delimited format)
 * @txt: MAC address as a string (e.g., "00:11:22:33:44:55")
 * @addr: Buffer for the MAC address (ETH_ALEN = 6 bytes)
 * Returns: 0 on success, -1 on failure (e.g., string not a MAC address)
 */
int hwaddr_aton(const char *txt, uint8_t *addr)
{
	int i;
	for (i = 0; i < 6; i++) {
		int a, b;
		a = hex2num(*txt++);
		if (a < 0)
			return -1;
		b = hex2num(*txt++);
		if (b < 0)
			return -1;
		*addr++ = (a << 4) | b;
		if (i < 5 && *txt++ != ':')
			return -1;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	uint8_t addr[6];
	char *mac = argv[1];
	uint8_t mine[6];

	hwaddr_aton(mac, addr);
	printf("%.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",addr[0],addr[1],addr[2],addr[3],addr[4],addr[5]);
	strncpy((void *)mine, (void *)addr, 6);
	printf("%.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n",mine[0],mine[1],mine[2],mine[3],mine[4],mine[5]);
	return 0;
}

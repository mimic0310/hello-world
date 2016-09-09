

#include <stdio.h>
#include <errno.h>
#include <string.h>

int _check_str(const char *golden)
{
    char buf[32];
    char str[32];

    if(fgets(buf, sizeof(buf), stdin) == NULL)
    {
        printf("fgets():xxxxx\n");
        return;
    }

    sscanf(buf, "%s", str);

    printf("Your input is: %s\n", str);

    if(0 == strncmp(golden, str, strlen(golden) ))
    {
	printf("match!!\n");
        return 0;
    }

	printf("FUCK!!\n");
    return 1;
}

int _str2hex(unsigned char *s, const unsigned char *h, int size)
{
    int i, j, len = strlen((const char *)h);
    unsigned char a, b;

    for(i = 0, j = 0; j < size && i < len; j++, i += 2) {
        if(h[i] == '\0' || h[i+1] == '\0')
            break;
        a = h[i] <= '9' ? h[i] - '0' : tolower(h[i]) - 'a' + 10;
        b = h[i+1] <= '9' ? h[i+1] - '0' : tolower(h[i+1]) - 'a' + 10;

        printf("a = 0x%x\n",a);
        printf("b = 0x%x\n",b);

        s[j] = (a << 4) | b;

        printf("s[j] = 0x%x\n",s[j]);

    }

    return j;
}

struct test
{
//char z;
int a;
int x;
void *b;
int c;
int d;
int e;
};

void main()
{
	int i;
	//_check_str("qwer");
	unsigned char hex[100] ={0x00};
	_str2hex(hex,"1234567890abcdef",100);
//#define HEX2CHAR(x) (char)(((x) > 9) ? (x) + '0' : (x) + 'A')
//	char test  = HEX2CHAR(0x9);
//	printf("%c\n",test);

	for(i = 0;i<16;i++)	printf("0x%x\n",hex[i]);

    unsigned int a=0,b=3,c=3;
    printf("a=%u, b=%u, c=%u\n",a,b,c);
    a = b == c;
    printf("a=%u, b=%u, c=%u\n",a,b,c);

    long unsigned int size = 0;
    size = sizeof(struct test);
    printf("struct size: %lu\n", size);
    printf("int size: %lu\n", sizeof(int));

}

#include <stdio.h>

char encrypt(char x);
void rot(char* from, char* to);

int main()
{
	char m[] = "HELLO";
	char c[6];

	rot(m, c);
	printf("%s\n", c);

	return 0;
}

char encrypt(char x)
{
		return (x%26)+65; 
}

void rot(char* from, char* to)
{
	for(;*from != '\0'; from++)
		*to++ = encrypt(*from);

	*to = '\0';
}
//! ROT-13
char encrypt(char x)
{
		if('A' <= x && x <= 'Z')
			return (x % 26) + 'A'; 
		else if('a' <= x && x <= 'z')
			return ((x - 'a') + 13) + 'a';
		return x;
}

void rot13(char* from, char* to)
{
	for(;*from != '\0'; from++)
		*to++ = encrypt(*from);

	*to = '\0';
}
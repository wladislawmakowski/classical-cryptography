#include <stdio.h>
#include "../headers/caesar.h"

static char _alpha[89] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-=~!@#$%^&*()_+{};':,./<>? ";
static int index_message, i;

static char encrypt
(
	const int MODE,
	const int key,
	const char message
)
{
	for(i = 0;i < 89;i++)
		if(message == _alpha[i])
			index_message  = i;

	if(MODE == 1)
		return _alpha[(index_message + key) % 89];
	if(MODE == -1)
		return _alpha[(index_message - key) % 89];
	return message;
}

void caesar
(
	const int MODE,
	char* const from,
	int const key,
	char* to
)
{
	char* p_from = from;
	for(;*p_from != '\0'; ++p_from)
		*to++ = encrypt(MODE, key, *p_from);
	*to = '\0';
}
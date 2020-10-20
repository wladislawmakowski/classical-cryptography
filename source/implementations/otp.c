#include <stdio.h>
#include "../headers/otp.h"

static char _alpha[89] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-=~!@#$%^&*()_+{};':,./<>? ";
static int k1;

static int mod(int n, int d)
{
    int result = n % d;
    if (result * d < 0)
        result += d;
    return result;
}

static char encrypt
(
	const int MODE,
	const int key,
	const char message
)
{
	int i, k1, k2;
	for(i = 0;i < 89;i++)
		if(message == _alpha[i])
			k1 = i;

	if(MODE == 1)
		return _alpha[mod((k1 + key), 89)];
	if(MODE == -1)
		return _alpha[mod((k1 - key), 89)];
	return message;
}

void otp
(
	const int MODE,
	char* from,
	int* key,
	int size,
	char* to
)
{
	char* p_from = from;
	int p_key;
	for(p_key = 0;*p_from != '\0', p_key < size; ++p_from, ++p_key)
		*to++ = encrypt(MODE, key[p_key], *p_from);
	*to = '\0';
}
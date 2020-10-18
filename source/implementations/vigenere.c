<<<<<<< HEAD
#include "../headers/vigenere.h"

=======
>>>>>>> 92331fc7ca7636639e9874411bded1887ed88ddd
static char _alpha[89] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-=~!@#$%^&*()_+{};':,./<>? ";
static int k1, k2;

static int mod(int n, int d)
{
    int result = n % d;
    if (result * d < 0)
        result += d;
    return result;
}

static char encrypt(
	const int MODE,
	const char key,
	const char message
)
{
	int i;
	for(i = 0;i < 89; i++)
	{
		if(_alpha[i] == message)
			k1 = i;
		if(_alpha[i] == key)
			k2 = i;
	}

	if(MODE == 1)
		return _alpha[mod((k1 + k2), 89)];
	else if(MODE == -1)
		return _alpha[mod((k1 - k2), 89)];
	return message;

}

void vigenere
(
	const int MODE,
	char* const from,
	char* const key,
	char* to
)
{
	char* p_from = from;
	char* p_key = key;
	for(;*p_from != '\0', *p_key != '\0'; ++p_from, ++p_key)
		*to++ = encrypt(MODE, *p_key, *p_from);
	*to = '\0';
}

#include <stdio.h>
#include "../headers/polybius.h"

static char _alpha[89] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-=~!@#$%^&*()_+{};':,./<>? ";
static int _length_alpha = 89;

static int get_size(int length)
{
	int i;
	while(i * i < length)
		i++;
	return i;
}

static void fill_the_matrix(char* matrix, int size)
{
	int i, j;
	for(i = 10;i < size * 10;i += 10)
		for(j = 1;j < size;j++)
			*matrix++ = i + j;
	*matrix = '\0';
}

static char encrypt
(
	char symbol,
	char* alpha,
	char* matrix
)
{
	for(;*alpha != '\0', *matrix != '\0'; ++alpha, ++matrix)
		if(*alpha == symbol)
			return *matrix;
	return symbol;
}

void polybius
(
	int MODE,
	char* from,
	char* to
)
{
	const int _size_of_matrix = get_size(_length_alpha);

	char matrix[_size_of_matrix * _size_of_matrix + 1];
	fill_the_matrix(matrix, _size_of_matrix);

	char* p_alpha = (MODE == 1) ? _alpha : matrix;
	char* p_matrix = (MODE == 1) ? matrix : _alpha;

	char* p_from = from;
	for(;*p_from != '\0'; ++p_from)
		*to++ = encrypt(*p_from, p_alpha, p_matrix);
	*to = '\0';
}

int main()
{
	//char m[61] = "Makowski Wladislaw Nikolaiewicz 25.03.2003 Rudny, Kazachstan";
	char m[61] = {24, 39, 51, 55, 64, 59, 51, 48, 32, 35, 52, 39, 43, 48, 59, 52, 39, 64, 32, 25, 48, 51, 55, 52, 39, 48, 44, 64, 48, 42, 67, 32, 71, 74, 46, 68, 72, 46, 71, 68, 68, 72, 32, 29, 62, 43, 54, 66, 44, 32, 22, 39, 67, 39, 42, 47, 59, 61, 39, 54, 0};
	char c[61];
	int i;

	polybius(-1, m, c);

	for(i = 0;i < 61;i++)
	{
		printf("%c", c[i]);
	}
	printf("\n");

	return 0;
}
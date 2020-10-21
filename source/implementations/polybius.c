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
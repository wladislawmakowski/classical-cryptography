#include <stdio.h>

int main()
{
	int mod(int n, int d);
	char _alpha[75] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+";

	int i, j;
	int k1, k2;
	char m[1024];
	char k[1024];
	char c[1024];

	scanf("%s", m);
	scanf("%s", k);

	for(i = 0;i < 1024;i++)
	{
		for(j = 0;j < 75;j++)
		{
			if(m[i] == _alpha[j])
			{
				k1 = j;
			}

			if(k[i] == _alpha[j])
			{
				k2 = j;
			}
		}

		c[i] = _alpha[(k1 + k2)%75];
	}

	for(i = 0;i < 1024;i++)
	{
		printf("%c", c[i]);
	}
	printf("\n");

	printf("-----------------------\n");

	for(i = 0;i < 1024;i++)
	{
		for(j = 0;j < 75;j++)
		{
			if(c[i] == _alpha[j])
			{
				k1 = j;
			}

			if(k[i] == _alpha[j])
			{
				k2 = j;
			}
		}

		printf("|i: %d||%d = %c|\n", i, ((k1-k2)%75), _alpha[mod((k1 - k2), 75)]);
		c[i] = _alpha[mod((k1 - k2), 75)];
	}

	printf("------------------------\n");

	for(i = 0;i < 1024;i++)
	{
		printf("%c", c[i]);
	}
	printf("\n");

	printf("%d\n", mod(-42, 75));

	return 0;
}

int mod(int n, int d)
{
    int result = n % d;
    if (result * d < 0)
        result += d;
    return result;
}

//c[i] = (char)((((int)m[i] + (int)k[i])%26)+65);
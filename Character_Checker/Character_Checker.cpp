#include<stdio.h>

int check(char, char);

int main()
{
	char c[10000];
	char* n = c;
	int all;
	int result;
	for (int i = 0; i < 10000; i++)
	{
		scanf_s("%c", &c[i]);
		int a = c[i];
		if (a == 10)
		{
			all = i;
			i = 10002;
		}
	}
	for (int i = 0; i < all - 1; i++)
	{
		switch (check(*n, *(n + 1)))
		{
		case 0:
			printf("ERROR");
			return 1;
			break;
		case 1:
			result = 0;
			break;
		case 2:
			result = 1;
			break;
		case 3:
			result = 2;
			i = all;
			break;
		default:
			break;
		}
		n++;
	}
	switch (result)
	{
	case 0:
		printf("All Capital Letter");
		break;
	case 1:
		printf("All Small Letter");
		break;
	case 2:
		printf("Mix");
		break;
	default:
		break;
	}
	return 0;
}

int check(char a, char b)
{
	int inta = a, intb = b;
	if ((inta < 65 || inta > 122) || (intb < 65 || intb > 122))
	{
		return 0;
	}
	else if ((inta > 90 && inta < 97) || (intb > 90 && intb < 97))
	{
		return 0;
	}
	if (inta > 64 && inta < 91)
	{
		if (intb > 64 && intb < 91)
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
	else 
	{
		if (intb > 64 && intb < 91)
		{
			return 3;
		}
		else
		{
			return 2;
		}
	}
}

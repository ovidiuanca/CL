#include "header.h"

int		ft_atoi(char *string)
{
		// Converts the number from a string format to an integer.

		int number, i;

		number = 0;
		i = 0;
		while (string[i])
		{
				number = number * 10 + (string[i] - 48);
				i++;
		}
		return (number);
}

void	add_digit(char *result, char digit);

char	*ft_itoa(int number)
{
		// Converts an integer number into a string format number.		

		char *result;

		result = (char*)malloc(sizeof(char) * 1000);
		while (number)
		{
				add_digit(result, (number % 10) + 48);
				number /= 10;
		}
		return (result);
}

int		power(int base, int exponent)
{
		// Calculates 'base' at the power of 'exponent'.

		int i, result;

		if (base == 0)
				return (0);
		if (exponent == 0)
				return (1);
		result = base;
		for (i = 2; i <= exponent; i++)
				result *= base;
		return (result);
}

int		charToIntDigit(char c)
{
		// Converts a digit from character to integer.

		if (c == 'A' || c == 'a')
				return (10);
		else if (c == 'B' || c == 'b')
				return (11);
		else if (c == 'C' || c == 'c')
				return (12);
		else if (c == 'D' || c == 'd')
				return (13);
		else if (c == 'E' || c == 'e')
				return (14);
		else if (c == 'F' || c == 'f')
				return (15);
		else
				return (c - 48);
}

char	ft_digit(int rest)
{
		// Converts the rest into a character, ready to be added to the result, at the beginning of the string.

		if (rest == 10)
				return 'A';
		else if (rest == 11)
				return 'B';
		else if (rest == 12)
				return 'C';
		else if (rest == 13)
				return 'D';
		else if (rest == 14)
				return 'E';
		else if (rest == 15)
				return 'F';
		else
				return (rest + 48);
}

void	add_digit(char *result, char digit)
{
		// Adds a digit at the beginning of the result string.

		strcpy(result + 1, result);
		result[0] = digit;
}

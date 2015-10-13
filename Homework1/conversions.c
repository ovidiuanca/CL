#include "header.h"

char	*convertToDecimal(char *number, int base)
{
		// Converts a number from a given base into decimal.

		int i, digit, decimal;

		decimal = 0;
		i = 0;
		while (number[i + 1]) // places i at the end of the string.
				i++;
		for (; i >= 0; i--)
		{
				digit = charToIntDigit(number[i]);
				decimal = decimal + (digit * power(base, strlen(number) - i - 1));
		}

		// now we have to convert decimal from an integer to a string form.

		number = ft_itoa(decimal);
		return (number);
}

char	*decimalToBase(char *number, int resultBase)
{
		// Converts the number from decimal to the given base.

		int		decimalInteger, i, rest;
		char	*result, hexChar;

		result = (char*)malloc(sizeof(char) * 1000);
		decimalInteger = ft_atoi(number);
		while (decimalInteger)
		{
				rest = decimalInteger % resultBase;
				hexChar = ft_digit(rest);
				add_digit(result, hexChar);
				decimalInteger /= resultBase;
		}
		return (result);
}

char	*conversion(char *number, int base, int resultBase)
{
		// Converts the number to a given base.

		char *result;

		if (base == 10)
				result = decimalToBase(number, resultBase);
		else
		{
				number = convertToDecimal(number, base);
				result = decimalToBase(number, resultBase);
		}
		return (result);
}

char	*operation(char *firstNumber, char *secondNumber, int base, char operator)
{
		char	*result;
		int		resultInt, firstInt, secondInt;

		result = (char*)malloc(sizeof(char) * 1000);

		firstNumber = convertToDecimal(firstNumber, base);
		secondNumber = convertToDecimal(secondNumber, base);
		firstInt = ft_atoi(firstNumber);
		secondInt = ft_atoi(secondNumber);
		// conditions for each operator.

		if (operator == '+')
				resultInt = firstInt + secondInt;
		else if (operator == '-')
				resultInt = firstInt - secondInt;
		else if (operator == '*')
				resultInt = firstInt * secondInt;
		else if (operator == '/')
				resultInt = firstInt / secondInt;
		else
		{
				printf("Error! Wrong input data.");

		}

		// converting the integer result into a string one.

		result = ft_itoa(resultInt);

		// converting the result in base 10 back to its initial base.

		result = decimalToBase(result, base);
		return (result);
}

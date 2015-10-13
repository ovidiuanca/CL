#ifndef __HEADER_H
#define __HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		ft_atoi(char *string);

void	add_digit(char *result, char digit);

char	*ft_itoa(int number);

int		power(int base, int exponent);

int		charToIntDigit(char c);

char	*convertToDecimal(char *number, int base);

char	ft_digit(int rest);

char	*decimalToBase(char *number, int resultBase);

char	*conversion(char *number, int base, int resultBase);

char	*operation(char *firstNumber, char *secondNumber, int base, char operator);

#endif

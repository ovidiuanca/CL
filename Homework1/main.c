#include "header.h"

void	decision1(void)
{
		// Does the actual conversion of a number from a base to another base.

		int 	base, resultBase;
		char	*number, *resultNumber;

		printf("Give your number: ");

		number = (char*)malloc(sizeof(char) * 1000);

		scanf("%s", number);
		printf("Give its base: ");
		scanf("%d", &base);
		printf("Give the base you want that number be converted in: ");
		scanf("%d", &resultBase);

		resultNumber = (char*)malloc(sizeof(char) * 1000);

		resultNumber = conversion(number, base, resultBase);
		printf("%s in base %d = %s in base %d\n", number, base, resultNumber, resultBase);
}

void	decision2(void)
{
		// Does the arithmetic operation of the given numbers in a base, based on the given operator.

		int		base;
		char	operator, *firstNumber, *secondNumber, *result;
		
		firstNumber = (char*)malloc(sizeof(char) * 1000);
		secondNumber = (char*)malloc(sizeof(char) * 1000);
		result = (char*)malloc(sizeof(char) * 1000);
		
		printf("Give the first number: ");
		scanf("%s", firstNumber);
		printf("Give the second number: ");
		scanf("%s", secondNumber);
		printf("Specify the base: ");
		scanf("%d", &base);
		printf("Give the operator (+, -, *, /): ");
		scanf(" %c", &operator); // space needed for IDK what reason.

		result = operation(firstNumber, secondNumber, base, operator);
		printf("%s %c %s = %s\n", firstNumber, operator, secondNumber, result);
}

void	error(void)
{
		// Prints out "Error" if the user gives another option than 1 or 2.

		printf("Error! Please insert ONLY 1 or 2!\n");
}

int		main(void)
{
		int decision;

		printf("Press <1> or <2> depending on your need:\n");
		printf("(1) To convert a number from a base to another.\n");
		printf("(2) For arithmetic operations of two numbers in a base.\n");
		scanf("%d", &decision);
		if (decision == 1)
				decision1();
		else if (decision == 2)
				decision2();
		else
				error();
		return (0);
}

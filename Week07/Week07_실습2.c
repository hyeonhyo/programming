#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int sumTwo(int a, int b)
{
	return a+b;

}

int square(int n)
{
	return n*n;
}

int get_max(int x, int y)
{
	if (x<y)
	return y;
	
	else if (x>y)
	return x;
}

int main()
{
	int first, second;
	printf("Enter the integers: ");
	
	scanf("%d %d", &first, &second);
	
	int Sum = sumTwo(first, second);
	int Square = square(first);
	int Max = get_max(first, second);
	
	printf("Result - Sum: %d, Square: %d, Max: %d", Sum, Square, Max);

	
	
	return 0;
}

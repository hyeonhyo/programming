#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a, b;
	char op;
	printf("Enter the calculation: ");
	scanf("%d %c %d", &a, &op, &b);
	
	if (op=='+')
	printf("= %d", a+b);
	
	else if (op=='-')
	printf("=%d", a-b);
	
	else if (op=='*')
	printf("=%d", a*b);
	
	else if (op=='/')
	printf("%d", a/b);
	
	return 0;
}

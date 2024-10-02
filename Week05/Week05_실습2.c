#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a, b;
	
	printf("Input two integers: ");
	scanf("%d %d", &a, &b);
	
	printf("+ result is %d\n", a+b);
	printf("- result is %d\n", a-b);
	printf("* result is %d\n", a*b);
	printf("/ result is %d\n", a/b);
	printf("%% result is %d\n", a%b);
	
	return 0;
}

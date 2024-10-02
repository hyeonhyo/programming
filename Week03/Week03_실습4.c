#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float a, b;
	
	printf("enter two integers: ");
	scanf("%f, %f", &a, &b);
	printf("%f / %f = %f", a, b, a/b);
	
	return 0;
}

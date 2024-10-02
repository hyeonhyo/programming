#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char c;
	char next_c;
	
	
	
	printf("enter a character: ");
	scanf("%c", &c);
	
	next_c = c + 1;
	printf("The next character of %c (%i) is %c (%i)", c, c, next_c, next_c);
	return 0;
}

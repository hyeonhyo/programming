#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a;
	
	printf("Enter an integer: ");
	scanf("%d", &a);
	
	if (a == 0){
	printf("this is 0.");
	}
	else if(a>0){
	printf("this is positive number.");
	}
	else if(a<0){
	printf("this is negative number.");
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	int a;
	int num=0;
	
	printf("Enter a number: ");
	scanf("%d",&a);
	
	for (i=1;i<a+1;i++)
	num = num+i;

	printf("the result is %d", num);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int get_integer();
int combination(int n, int r);
int factorial(int n);

int main(void)
{	int n, r,comb;

	printf("Enter the value:");
	n = get_integer();
	printf("Enter the value:");
	r = get_integer();
	comb = combination(n,r);
	printf("The result of C(%d, %d) is %d", n, r,comb);
	
	return 0;
}

int combination(int n, int r)
{
	return factorial(n)/(factorial(n-r)*factorial(r));
	
}

int factorial(int n)
{
	int i;
	int res =1;
	for(i=1;i<=n;++i)
	res = res*i;
	return res; 
}
int get_integer()
{
	int value;
	
	scanf("%d", &value);
	
	return value;
	
}














#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int grade[5];
	int *g = grade;
	int sum = 0;
	int ave;
	for(i=0;i<5;i++)
	{
		printf("Input value - grade[%i]=", i);
		scanf("%d", &grade[i]);
	}
	for(i=0;i<5;i++){
		printf("grade[%i] = %d\n", i, *(g+i));
		sum += *(g + i);
	}
	ave = sum/5.0;
  
 printf("Average = %d", ave);
}

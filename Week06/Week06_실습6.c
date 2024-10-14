#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int answer = 50;
	int guess;
	int Trials = 0;
	
	do
	{
		printf("Guess a number: ");
		scanf("%d", &guess);
		Trials +=1;	
		
		if (guess < answer)
		printf("low!\n");
		else if (guess > answer)
		printf("high!\n");
	}while (guess != answer);
	 
		printf("congratulation! Trials: %d", Trials);
	
	return 0;
}

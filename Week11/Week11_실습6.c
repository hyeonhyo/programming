#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp = NULL;
	char c;
	fp = fopen("sample.txt", "r");
	if (fp == NULL)
	printf("������ ������\n");
	
	while ((c = fgetc(fp)) != EOF)
	putchar(c);
	
	fclose(fp);
} 

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	FILE *fp;
    char w;  
    int i;
    char c;

  
    for (i = 0; i < 3; i++){
        printf("input a word: "); 
        scanf("%s", &w);  
	}

    fp = fopen("sample.txt", "w");


    for (i = 0; i < 3; i++) {
        fprintf(fp, "%s", w);  
    }

    fclose(fp);  
    
    fp = fopen("sample.txt", "r");
   
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);  
    }

    fclose(fp);
    return 0;
}


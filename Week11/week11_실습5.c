#include <stdio.h>
#include <stdlib.h>

int main() {
	
	FILE *fp;
    char w[3][100];  
    int i;
    

    for (i = 0; i < 3; i++){
        printf("input a word: "); 
        scanf("%s", &w[i]);  
	}

    fp = fopen("sample.txt", "w");


    for (i = 0; i < 3; i++){
        fprintf(fp, "%s\n", w[i]);  
    }
    fclose(fp);
    return 0;
}


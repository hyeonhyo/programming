#include <stdio.h>

int main()
{
    FILE *fp;
    char c[3];  
    int i;

  
    for (i = 0; i < 3; i++){
        printf("input a word: "); 
        scanf("%s", &c[i]);  
	}

    fp = fopen("sample.txt", "w");


    for (i = 0; i < 3; i++) {
        fprintf(fp, "%s", c[i]);  
    }

    fclose(fp);  

    return 0;
}



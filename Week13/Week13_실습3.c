#include <stdio.h>
#define STUDENTNUM 4

struct student {
    int ID;
    int score;
};

int main(void) {
    struct student s[STUDENTNUM];
    int sum = 0;
    int max = 0;
    int max_ID = 0;
    int i; 

    for (i = 0; i < STUDENTNUM; i++) {
        printf("Input the ID: ");
        scanf("%d", &s[i].ID);

        printf("Input the score: ");
        scanf("%d", &s[i].score);
    }

    for (i = 0; i < STUDENTNUM; i++) {
        sum += s[i].score;
    }
    printf("The average of the score: %d\n", sum / STUDENTNUM);

    for (i= 0; i < STUDENTNUM; i++) {
        if (max < s[i].score) {
            max = s[i].score;
            max_ID = i;
        }
    }

    printf("The highest score - ID: %d, score: %d\n", s[max_ID].ID, max);

}



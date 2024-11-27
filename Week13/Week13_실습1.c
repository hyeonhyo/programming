#include <stdio.h>

struct student{
	int ID;
	char name[10];
	double grade;
};

int main(void){
	struct student s = {2210981,"hyeonhyo",4.2};
	
	
	printf("ID: %d\n", s.ID);
	printf("name: %s\n", s.name);
	printf("grade: %f", s.grade);
};

#include <stdio.h>

typedef struct _Date{
	int year;
	int month;
	int day;
} Date;

Date *NextDate(Date*);  
Date *NewDateInstance(int year, int month, int day);
void ShowDate(Date*);
bool checkDate(Date* a, int true_year, int true_mouth, int true_day);




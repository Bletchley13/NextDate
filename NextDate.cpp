#include <stdlib.h>
#include "NextDate.h"


Date *NextDate(Date *argv)
{
	Date *ret = (Date *)malloc(sizeof(Date));
	ret->year = -1;
	ret->month = -1;
	ret->day = -1;
	return ret;
}  

Date *NewDateInstance(int year, int month, int day)
{
	Date *ret = (Date *)malloc(sizeof(Date));
	ret->year = -1;
        ret->month = -1;
        ret->day = -1;
	return ret;
}

void ShowDate(Date* date)
{
	printf("%d-%d-%d\n", date->year, date->month, date->day);
}

bool checkDate(Date* a, int true_year, int true_mouth, int true_day)
{
        if(a->year == true_year && a->month == true_mouth && a->day == true_day){
                return true;
        }
        return false;
}


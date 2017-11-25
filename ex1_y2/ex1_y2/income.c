#include "income.h"
#include <stdio.h>
income* new_income(int amount, char* new_place)
{
	income* ptr = malloc(sizeof(income));
	ptr->wage = amount;
	strncpy(ptr->place, new_place, INCOME_PLACE_STR_SIZE);
	return ptr;
}

void print_income(income* ptr)
{
	printf("Company name : %s Wage: %d ", ptr->place,ptr->wage);
}

int income_sum(income* ptr)
{
	return (ptr != NULL) ? ptr->wage : 0;
}

int cmp_income(income* s1, income* s2)
{
	return (s1->wage > s2->wage) ? 1 : -1;
}
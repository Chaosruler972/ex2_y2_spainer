#pragma once
#define INCOME_PLACE_STR_SIZE 20
typedef struct income
{
	int wage;
	char place[INCOME_PLACE_STR_SIZE];
}income;

income* new_income(int amount, char* new_place);

void print_income(income* ptr);

int income_sum(income* ptr);

int cmp_income(income* s1, income* s2);
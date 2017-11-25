#pragma once
#include "node.h"
#include <stdio.h>
typedef struct Stud
{
	int id;
	float grade_avg;
	float income_avg;
	node* list_grades;
	node* list_income;
}Stud;

Stud* new_student(int id);


Stud* find_student(Stud** arr, int id, int SIZE);

Stud** create_array(int SIZE);

void print_student(Stud* ptr);

void print_all_students(Stud** arr, int SIZE);

void free_student(Stud** arr, int SIZE);

void sort_students(Stud** arr, int SIZE, int(*cmp)(const struct Stud* s1, const struct Stud* s2), int ascending_descending);

int sort_by_grade_avg(const struct Stud* s1, const struct Stud* s2);

int sort_by_income_avg(const struct Stud* s1, const struct Stud* s2);
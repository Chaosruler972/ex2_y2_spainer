#include "Stud.h"
#include "node.h"
#include "course.h"
#include "income.h"

Stud* new_student(int id)
{
	Stud* ptr =(Stud*) malloc(sizeof(Stud));
	ptr->id = id;
	ptr->income_avg = 0;
	ptr->list_grades = NULL;
	ptr->list_income = NULL;
	ptr->grade_avg = 0;
	return ptr;
}

Stud* find_student(Stud** arr, int id, int SIZE)
{
	int i = 0;
	for (i = 0; i < SIZE; i++)
	{
		if (arr[i]!= NULL && arr[i]->id == id)
			return arr[i];
	}
	return NULL;
}

Stud** create_array(int SIZE)
{
	Stud** ptr = (Stud**)malloc(SIZE * sizeof(Stud*));
	int i;
	for (i = 0; i < SIZE; i++)
		ptr[i] = NULL;
	return ptr;
}

void print_student(Stud* ptr)
{
	if (ptr == NULL)
		return;
	printf("ID: %d\n", ptr->id);
	printf("Grades : ");
	print_list(&ptr->list_grades, print_course);
	printf("\nWages : ");
	print_list(&ptr->list_income, print_income);
	printf("\n");
}

void print_all_students(Stud** arr, int SIZE)
{
	Stud* current = arr[0];
	int i;
	for (i = 0; i < SIZE; i++)
		print_student(arr[i]);
}

void free_student(Stud** arr, int SIZE)
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		if (arr[i] != NULL)
		{
			free_list(arr[i]->list_grades);
			free_list(arr[i]->list_income);
			free(arr[i]);
		}
	}
	free(arr);
}

void sort_students(Stud** arr, int SIZE, int(*cmp)(const struct Stud* s1, const struct Stud* s2), int ascending_descending)
{
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		if (arr[i] == NULL)
			break;
		int me = i;
		int peak = i;
		for (j = i; j < SIZE; j++)
		{
			if (arr[j] == NULL)
				break;
			Stud* compartor = arr[j];
			if (ascending_descending)
			{
				if (cmp(arr[peak], compartor) < 0)
					peak = j;
			}
			else
			{
				if (cmp(arr[peak], compartor) > 0)
					peak = j;
			}
		}
		Stud* backup = arr[me];
		arr[me] = arr[peak];
		arr[peak] = backup;
	}
}

int sort_by_grade_avg(const struct Stud* s1, const struct Stud* s2)
{
	return (s1->grade_avg > s2->grade_avg) ? 1 : -1;
}

int sort_by_income_avg(const struct Stud* s1, const struct Stud* s2)
{
	return (s1->income_avg > s2->income_avg) ? 1 : -1;
}
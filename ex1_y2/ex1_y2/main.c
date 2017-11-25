#include "Stud.h"
#include "course.h"
#include "node.h"
#include "income.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STUD_SIZE 30
#define INPUT_SHIT_SORTED 1

#define NEW_GRADE "ng"
#define NEW_STUDENT "ns"
#define NEW_INCOME "ni"
#define WANTED_STUD "ws"
#define PRINT_ARRAY "pa"
#define SORT_ARRAY "sa"
#define GRADE_STR "g"
#define INCOME_STR "i"
#define ASCENDING "a"
#define DESCENDING "d"
#define END "end"
#define DOUBLE_STUDENT_ERROR_MESSAGE "DOUBLESTUD\n"
#define ERROR_NO_PLACE_IN_ARRAY "No Place in Student Array\n"
#define ERROR_NO_STUDENT "Student doesn't exist!\n"
#define ENTER_STUD_ID_MSG "Please enter Student's ID and than press enter: "
#define ENTER_GRADE_MSG "Please enter a grade and than press enter : "
#define INPUT_ERR "Input Error\n"
#define ENTER_COURSE_NAME "Please enter a course name and than press enter : "
#define SUCCESS "Success!\n"
#define INCOME_NAME_MSG "Please enter an income place and than press enter : "
#define INCOME_MONEY_MSG "Please enter your wage and than press enter : "
#define ENTER_COMMAND "Enter command and than press enter: (available commands ng,ns,ni,ws,pa,sa) "
#define ENTER_WHAT_SHOULD_WE_SORT "Enter what should we sort and press enter : (available commands g,i) "
#define ENTER_ASCENDING_OR_DESCENDING "Please enter a command for ascending or descending and press enter: (commands available a,d) "

int grab_input(char* str, char* msg);

int main(int argc, char** argv)
{
	unsigned char input[4];
	Stud** arr = create_array(STUD_SIZE);
	while (1)
	{
		if (!grab_input(input, ENTER_COMMAND))
			continue;
		if (!strcmp(input, NEW_STUDENT))
		{
			char ID[10];
			if(grab_input(ID,ENTER_STUD_ID_MSG))
			{
				int id = atoi(ID);
				if (find_student(arr, id, STUD_SIZE) != NULL)
				{
					printf(DOUBLE_STUDENT_ERROR_MESSAGE);
				}
				else
				{
					int i;
					for (i = 0; i < STUD_SIZE; i++)
					{
						if (arr[i] == NULL)
						{
							arr[i] = new_student(id);
							break;
						}
					}
					if (i == STUD_SIZE)
					{
						printf(ERROR_NO_PLACE_IN_ARRAY);
					}
				}
			}
		}
		else if (!strcmp(input, NEW_GRADE))
		{
			char ID[10];
			if (grab_input(ID, ENTER_STUD_ID_MSG))
			{
				int id = atoi(ID);
				Stud* student = NULL;
				if (  (student = find_student(arr, id, STUD_SIZE) ) != NULL)
				{
					char COURSE_NAME[COURSE_NAME_SIZE];
					if (grab_input(COURSE_NAME, ENTER_COURSE_NAME))
					{
						char GRADE[8];
						if(grab_input(GRADE,ENTER_GRADE_MSG))
						{
							int grade = atoi(GRADE);
							course* course = get_course(COURSE_NAME, GRADE);
							node* new_node = new_data(course);
#if INPUT_SHIT_SORTED == 0
							if (add_to_list(&student->list_grades, get_tail(&student->list_grades), new_node) != 0)
							{
								printf(SUCCESS); 
								student->grade_avg = avg(&student->list_grades, get_course_sum);
							}
#else
							node* limit = get_closest(&student->list_grades, cmp_grade, new_node);
							struct course* lim_data = NULL;
							if(limit)
								lim_data = limit->data;
							if (add_to_list(&student->list_grades, limit, new_node) != 0)
							{
								printf(SUCCESS);
								student->grade_avg = avg(&student->list_grades, get_course_sum);
							}
#endif 
							else
							{
								printf(INPUT_ERR);
							}
						}
					}
				}
				else
				{
					printf(ERROR_NO_STUDENT);
				}
			}
		}
		else if (!strcmp(input, NEW_INCOME))
		{
			char ID[10];
			if(grab_input(ID,ENTER_STUD_ID_MSG))
			{
				int id = atoi(ID);
				Stud* student = NULL;
				if ((student = find_student(arr, id, STUD_SIZE)) != NULL)
				{
					char PLACE_NAME[INCOME_PLACE_STR_SIZE];
					if(grab_input(PLACE_NAME,INCOME_NAME_MSG))
					{
						char INCOME[8];
						if(grab_input(INCOME,INCOME_MONEY_MSG))
						{
							int income_wage = atoi(INCOME);
							income* wage = new_income(income_wage,PLACE_NAME);
							node* new_node = new_data(wage);
#if INPUT_SHIT_SORTED == 0
							if (add_to_list(&student->list_income, get_tail(&student->list_income), new_node) != 0)
							{
								printf(SUCCESS);
								student->income_avg = avg(&student->list_income, income_sum);
							}
#else
							node* limit = get_closest(&student->list_income, cmp_income, new_data);
							if (add_to_list(&student->list_income, limit, new_node) != 0)
							{
								printf(SUCCESS);
								student->income_avg = avg(&student->list_income, income_sum);
							}
#endif
							else
							{
								printf(INPUT_ERR);
							}
						}
					}
				}
				else
				{
					printf(ERROR_NO_STUDENT);
				}
			}
		}
		else if (!strcmp(input, WANTED_STUD))
		{
			char ID[10];
			if(grab_input(ID,ENTER_STUD_ID_MSG))
			{
				int id = atoi(ID);
				Stud* student = NULL;
				if ((student = find_student(arr, id, STUD_SIZE)) != NULL)
				{
					print_student(student);
				}
				else
				{
					printf(ERROR_NO_STUDENT);
				}
			}
		}
		else if (!strcmp(input, PRINT_ARRAY))
		{
			print_all_students(arr, STUD_SIZE);
		}
		else if (!strcmp(input, SORT_ARRAY))
		{

			if(grab_input(input,ENTER_WHAT_SHOULD_WE_SORT))
			{
				if (!strcmp(input, GRADE_STR))
				{
					if(grab_input(input,ENTER_ASCENDING_OR_DESCENDING))
					{
						if (!strcmp(input, DESCENDING))
						{
							sort_students(arr, STUD_SIZE, sort_by_grade_avg, 1);
						}
						else if(!strcmp(input, ASCENDING))
						{
							sort_students(arr, STUD_SIZE, sort_by_grade_avg, 0);
						}
						else
						{
							printf(INPUT_ERR);
						}
					}
				}
				else if (!strcmp(input, INCOME_STR))
				{
					if (grab_input(input, ENTER_ASCENDING_OR_DESCENDING))
					{
						if (!strcmp(input, DESCENDING))
						{
							sort_students(arr, STUD_SIZE, sort_by_income_avg, 1);
						}
						else if (!strcmp(input, ASCENDING))
						{
							sort_students(arr, STUD_SIZE, sort_by_income_avg, 0);
						}
						else
						{
							printf(INPUT_ERR);
						}
					}
				}
			}
		}
		else if(!strcmp(input,END))
			break;
		else
		{
				printf(INPUT_ERR);
		}
	}
	free_student(arr, STUD_SIZE);
}

int grab_input(char* str, char* msg)
{
	printf("%s", msg);
	if (scanf("%s", str) == 1)
		return 1;
	else
	{
		printf("%s", INPUT_ERR);
		return 0;
	}
}

#include "course.h"
course* get_course(char* course_name, char* grade)
{
	course* data = (course*)malloc(sizeof(course));
	data->grade = atoi(grade);
	strncpy(data->name, course_name, COURSE_NAME_SIZE);
	return data;
}

void print_course(course* ptr)
{
	printf("Course name: %s Grade: %d ", ptr->name, ptr->grade);
}

int get_course_sum(course* ptr)
{
	return (ptr != NULL) ? ptr->grade : 0;
}

int cmp_grade(course* s1, course* s2)
{
	return (s1->grade > s2->grade) ? 1 : -1;
}
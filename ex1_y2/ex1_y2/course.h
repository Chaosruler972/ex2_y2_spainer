#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define COURSE_NAME_SIZE 20
typedef struct course
{
	char name[COURSE_NAME_SIZE];
	unsigned int grade;
}course;

course* get_course(char* course_name, char* grade);

void print_course(course* ptr);

int get_course_sum(course* ptr);

int cmp_grade(course* s1, course* s2);
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	void* data;
	struct node* next;
}node;


node* new_data(void* data);

int add_to_list(node** head, node* place, node* data);

node* get_tail(node** head);

void print_list(node** head, void(*prnt)(void* data));

int count_elements(node** head);

int sum_elements(node** head, int(*getsum)(void* head));

float avg(node** head, int(*getsum)(void* head));

void free_list(node* head);

node* get_closest(node** head, int(*cmp)(void* elem1, void* elem2), node* data);
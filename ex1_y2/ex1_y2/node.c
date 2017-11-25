#include "node.h"
#include "course.h"
#include "income.h"
node* new_data(void* data)
{
	node* ptr = (node*)malloc(sizeof(node));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

int add_to_list(node** head, node* place, node* data)
{
	node* current = head[0];
	if (current == NULL)
	{
		head[0] = data;
	}
	else
	{
		if (place == NULL)
		{
			place = get_tail(head);
			place->next = data;
			return 1;
		}
		if (head[0] == place)
		{
			data->next = place;
			head[0] = data;
			return 1;
		}
		
		while (current->next != place)
		{
			if (current->next == NULL)
			{
				return 0;
			}
			current = current->next;
		}
		data->next = place;
		current->next = data;
		
	//	place->next = data;
	}
	return 1;
}

node* get_closest(node** head, int is_grade,node* ptr)
{
	node* current = head[0];
	if (current == NULL)
		return NULL;
	while (current != NULL)
	{
		int s1;
		int s2;
		if (is_grade)
		{
			course* me = current->data;
			course* to_add = ptr->data;
			s1 = to_add->grade;
			s2 = me->grade;
		}
		else
		{
			income* me = current->data;
			income* to_add = ptr->data;
			s1 = to_add->wage;
			s2 = me->wage;
		}

		if (s1<s2)
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}

node* get_tail(node** head)
{
	node* current = head[0];
	if (current == NULL)
		return NULL;
	while (current->next != NULL)
		current = current->next;
	return current;
}

void print_list(node** head, void (*prnt)(void* data))
{
	node* current = head[0];
	if (current == NULL)
		printf("Empty");
	while (current != NULL)
	{
		prnt(current->data);
		if (current->next != NULL)
			printf(", ");
		current = current->next;
	}
}

int count_elements(node** head)
{
	node* current = head[0];
	int counter = 0;
	while (current != NULL)
	{
		current = current->next;
		counter++;
	}
	return counter + 1;
}

int sum_elements(node** head, int(*getsum)(void* head))
{
	node* current = head[0];
	int sum = 0;
	while (current != NULL)
	{
		sum += getsum(current->data);
		current = current->next;
	}
	return sum;
}

float avg(node** head, int(*getsum)(void* head))
{
	int n = count_elements(head);
	if (head == 0)
		return 0;
	int sum = sum_elements(head, getsum);
	return ((float) sum) / n;
}

void free_list(node* head)
{
	if (head == NULL)
		return;
	free_list(head->next);
	free(head->data);
	free(head);
}
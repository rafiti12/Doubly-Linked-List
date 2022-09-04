#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

struct doubly_linked_list_t* dll_create()
{
	struct doubly_linked_list_t* a = malloc(sizeof(struct doubly_linked_list_t));
	if (a == NULL) return NULL;
	a->head = NULL;
	a->tail = NULL;
	return a;
}

int dll_push_back(struct doubly_linked_list_t* dll, int value)
{
	if (dll == NULL) return 1;
	struct node_t* a = malloc(sizeof(struct node_t));
	if (a == NULL) return 2;
	if (dll->head == NULL)
	{
		dll->head = a;
		dll->tail = a;
		a->next = NULL;
		a->prev = NULL;
		a->data = value;
	}
	else
	{
		dll->tail->next = a;
		a->next = NULL;
		a->prev = dll->tail;
		a->data = value;
		dll->tail = a;
	}
	return 0;
}

int dll_push_front(struct doubly_linked_list_t* dll, int value)
{
	if (dll == NULL) return 1;
	struct node_t* a = malloc(sizeof(struct node_t));
	if (a == NULL) return 2;
	if (dll->head == NULL)
	{
		dll->head = a;
		dll->tail = a;
		a->next = NULL;
		a->prev = NULL;
		a->data = value;
	}
	else
	{
		a->next = dll->head;
		a->prev = NULL;
		a->data = value;
		dll->head->prev = a;
		dll->head = a;
	}
	return 0;
}

int dll_pop_front(struct doubly_linked_list_t* dll, int* err_code)
{
	if (dll == NULL)
	{
		if (err_code != NULL)
			*err_code = 1;
		return -1;
	}
	if (dll->head == NULL)
	{
		if (err_code != NULL)
			*err_code = 1;
		return -1;
	}
	struct node_t* a = dll->head;
	int val = a->data;
	dll->head = dll->head->next;
	free(a);
	if(dll->head != NULL) dll->head->prev  = NULL;
	if (dll->head == NULL)
		dll->tail = NULL;
	if (err_code != NULL)
		*err_code = 0;
	return val;
}

int dll_pop_back(struct doubly_linked_list_t* dll, int* err_code)
{
	if (dll == NULL)
	{
		if (err_code != NULL)
			*err_code = 1;
		return -1;
	}
	if (dll->head == NULL)
	{
		if (err_code != NULL)
			*err_code = 1;
		return -1;
	}
	struct node_t* a = dll->tail;
	struct node_t* b = dll->head;
	if (a == b)
	{
		int val = a->data;
		free(a);
		if (err_code != NULL)
			*err_code = 0;
		dll->head = NULL;
		dll->tail = NULL;
		return val;
	}
	int val = dll->tail->data;
	while (1)
	{
		if (b->next == dll->tail)
		{
			dll->tail = b;
			break;
		}
		else b = b->next;
	}
	free(a);
	dll->tail->next = NULL;
	if (err_code != NULL)
		*err_code = 0;
	return val;
}

int dll_back(const struct doubly_linked_list_t* dll, int* err_code)
{
	if (dll == NULL)
	{
		if (err_code != NULL)
			*err_code = 1;
		return -1;
	}
	if (dll->head == NULL)
	{
		if (err_code != NULL)
			*err_code = 1;
		return -1;
	}
	if (err_code != NULL)
		*err_code = 0;
	return dll->tail->data;
}

int dll_front(const struct doubly_linked_list_t* dll, int* err_code)
{
	if (dll == NULL)
	{
		if (err_code != NULL)
			*err_code = 1;
		return -1;
	}
	if (dll->head == NULL)
	{
		if (err_code != NULL)
			*err_code = 1;
		return -1;
	}
	if (err_code != NULL)
		*err_code = 0;
	return dll->head->data;
}

struct node_t* dll_begin(struct doubly_linked_list_t* dll)
{
	if (dll == NULL) return NULL;
	return dll->head;
}

struct node_t* dll_end(struct doubly_linked_list_t* dll)
{
	if (dll == NULL) return NULL;
	return dll->tail;
}

int dll_size(const struct doubly_linked_list_t* dll)
{
	if (dll == NULL) return -1;
	if (dll->head == NULL) return 0;
	int count = 1;
	struct node_t* a = dll->head;
	while (a->next != NULL)
	{
		count++;
		a = a->next;
	}
	return count;
}

int dll_is_empty(const struct doubly_linked_list_t* dll)
{
	if (dll == NULL) return -1;
	if (dll->head == NULL) return 1;
	return 0;
}

int dll_at(const struct doubly_linked_list_t* dll, unsigned int index, int* err_code)
{
	if (dll == NULL)
	{
		if (err_code != NULL)
			*err_code = 1;
		return -1;
	}
	if (dll->head == NULL)
	{
		if (err_code != NULL)
			*err_code = 1;
		return -1;
	}
	if (index == 0)
	{
		if (err_code != NULL)
			*err_code = 0;
		return dll->head->data;
	}
	unsigned int count = 0;
	struct node_t* a = dll->head;
	while (a->next != NULL)
	{
		a = a->next;
		count++;
		if (count == index)
		{
			if (err_code != NULL)
				*err_code = 0;
			return a->data;
		}
	}
	if (err_code != NULL)
		*err_code = 1;
	return -1;
}

int dll_insert(struct doubly_linked_list_t* dll, unsigned int index, int value)
{
	if (dll == NULL) return 1;
	unsigned int count = 0;
	if (index == 0)
	{
		struct node_t* a = malloc(sizeof(struct node_t));
		if (a == NULL) return 2;
		if (dll->head == NULL)
		{
			dll->head = a;
			dll->tail = a;
			a->next = NULL;
			a->prev = NULL;
			a->data = value;
			return 0;
		}
		a->prev = NULL;
		dll->head->prev = a;
		a->next = dll->head;
		dll->head = a;
		a->data = value;
		return 0;
	}
	if (dll->head == NULL) return 1;
	struct node_t* b = dll->head;
	while (b->next != NULL)
	{
		b = b->next;
		count++;
		if (count == index)
		{
			struct node_t* a = malloc(sizeof(struct node_t));
			if (a == NULL) return 2;
			b = dll->head;
			for (unsigned int i = 0; i < count - 1; i++)
				b = b->next;
			struct node_t* d = b->next;
			d->prev = a;
			a->next = b->next;
			a->data = value;
			a->prev = b;
			b->next = a;
			return 0;
		}
	}
	count++;
	if (count == index)
	{
		struct node_t* a = malloc(sizeof(struct node_t));
		if (a == NULL) return 2;
		a->prev = dll->tail;
		dll->tail->next = a;
		a->next = NULL;
		a->data = value;
		dll->tail = a;
		return 0;
	}
	return 1;
}

int dll_remove(struct doubly_linked_list_t* dll, unsigned int index, int* err_code)
{
	if (dll == NULL)
	{
		if (err_code != NULL)
			*err_code = 1;
		return -1;
	}
	if (dll->head == NULL)
	{
		if (err_code != NULL)
			*err_code = 1;
		return -1;
	}
	unsigned int count = 0;
	struct node_t* b = dll->head;
	if (index == 0)
	{
		int val = b->data;
		dll->head = dll->head->next;
		if(dll->head != NULL) dll->head->prev = NULL;
		free(b);
		if (dll->head == NULL)
			dll->tail = NULL;
		if (err_code != NULL)
			*err_code = 0;
		return val;
	}
	while (b->next != NULL)
	{
		b = b->next;
		count++;
		if (count == index)
		{
			struct node_t* a = b;
			int val = a->data;
			b = dll->head;
			for (unsigned int i = 0; i < count - 1; i++)
				b = b->next;
			b->next = a->next;
			struct node_t* d = a->next;
			if(d != NULL) d->prev = b;
			if (b->next == NULL)
				dll->tail = b;
			free(a);
			if (err_code != NULL)
				*err_code = 0;
			return val;
		}
	}
	if (err_code != NULL)
		*err_code = 1;
	return -1;
}

void dll_clear(struct doubly_linked_list_t* dll)
{
	if (dll == NULL) return;
	while (dll->head != NULL)
		dll_pop_back(dll, NULL);
}

void dll_display(const struct doubly_linked_list_t* dll)
{
	if (dll == NULL) return;
	struct node_t* a = dll->head;
	while (a != NULL)
	{
		printf("%d ", a->data);
		a = a->next;
	}
}

void dll_display_reverse(const struct doubly_linked_list_t* dll)
{
	if (dll == NULL) return;
	struct node_t* a = dll->tail;
	while (a != NULL)
	{
		printf("%d ", a->data);
		a = a->prev;
	}
}

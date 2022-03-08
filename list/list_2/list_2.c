#include <stdio.h>
#include <stdlib.h>
//........................................
//........................................
typedef int Data;
struct Node {
	struct Node * next;
	struct Node * prev;
	Data data;
};
//........................................
//........................................
void list_init(struct Node * list);

void list_insert(struct Node * list, struct Node * t);
void list_insert_before(struct Node * list, struct Node * t);
void list_remove(struct Node * t);

struct Node * list_push_front(struct Node * list, Data d);
struct Node * list_push_back(struct Node * list, Data d);

Data List_pop_front (struct Node * list);
Data List_pop_back (struct Node * list);

Data list_pop_front(struct Node * list);
Data list_pop_back(struct Node * list);
Data list_delete(struct Node * t);

void list_print (struct Node * list);
int list_is_empty(struct Node * list);

void list_clear(struct Node * list);
//........................................
//........................................
int main()
{ 
    struct Node * a = malloc(sizeof(struct Node));
    struct Node * b = malloc(sizeof(struct Node));
    struct Node * c = malloc(sizeof(struct Node));
    b->data = 228;
    c->data = 322;
    int x = 0;
    list_init(a);
    list_insert(a, b);
    list_print(a);
    list_clear(a);

    list_insert(a, c);
    list_print(a);
    list_clear(a);
    list_print(a);
    list_remove(a);
    x = list_is_empty(a);
    printf("x = %d\n%p\n", x, a);
    //printf("%p\n", a->next);

    //list_print(a);
}
//........................................
//........................................
//int flag = 0;

void list_init(struct Node* list)
{
    list->next = list;
    list->prev = list;
    return;
}
//........................................
// вставляет элемент t после элемента list
void list_insert(struct Node * list, struct Node * t)
{
    t->next = list->next;
    t->prev = list;

    list->next->prev = t;
    list->next = t;

    return;
}
//........................................
// вставляет элемент t перед элементом list
void list_insert_before(struct Node * list, struct Node * t)
{
    t->next = list;
    t->prev = list->prev;

    list->prev->next = t;
    list->prev = t;
    
    return;
}
//........................................
// удаляет элемент t из списка
void list_remove(struct Node * t)
{

    t->next->prev = t->prev;
    t->prev->next = t->next;
    
    return;
}
//........................................
// печатает список
void list_print (struct Node * list)
{
    struct Node* tmp = list->next;

    while(tmp != list)
    {
        if(tmp->next == list)
            printf("%d \n", tmp->data);
        else
            printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    return;
}
//........................................
//вставляет элемент в голову
struct Node * list_push_front(struct Node * list, Data d)
{
    struct Node* new = calloc(1, sizeof(struct Node));
    if(new == NULL)
        return NULL;
    new->data = d;
    list_insert(list, new);

    return new;
}
//........................................
//вставляет элемент в хвост
struct Node * list_push_back(struct Node * list, Data d)
{
    struct Node* new = calloc(1, sizeof(struct Node));
    if(new == NULL)
        return NULL;
    new->data = d;
    list_insert_before(list, new);

    return new;
}
//........................................
//удаляет голову (хвост, указанный элемент t) списка, возвращая данные. 
Data list_pop_front(struct Node * list)
{
    return list_delete(list->next);
}
//........................................
//удаляет голову (хвост, указанный элемент t) списка, возвращая данные. 
Data list_pop_back(struct Node * list)
{
    return list_delete(list->prev);
}
//........................................
//удаляет голову (хвост, указанный элемент t) списка, возвращая данные. 
Data list_delete(struct Node * t)
{
    Data tmp = t->data;
    list_remove(t);
    free(t);
    return tmp;
}
//........................................
//........................................
int list_is_empty(struct Node * list)
{
    return (list->prev == list && list->next == list);
}
//........................................
//опустошает список, освобождая память. После этого можно опять добавлять элементы в список.
void list_clear(struct Node * list)
{
    while (!list_is_empty(list))
    list_pop_front(list);
    return;
}
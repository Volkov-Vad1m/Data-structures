void list_init (struct Node * list)
{
    list->next = list;
    list->prev = list;
}

void list_insert (struct Node * list, struct Node * t)
{
    t->prev = list;
    t->next = list->next;
    t->next->prev = t;
    list->next = t;
}

void list_insert_before (struct Node * list, struct Node * t)
{
    t->next = list;
    t->prev = list->prev;
    t->prev->next = t;
    list->prev = t;
}

void list_remove (struct Node * t)
{
t->prev->next = t->next;
t->next->prev = t->prev;
}

struct Node * list_push_front (struct Node * list, Data d)
{
    struct Node * tmp = calloc(1, sizeof(struct Node));
    tmp->data = d;
    list_insert(list, tmp);
    return tmp;
}

struct Node * list_push_back (struct Node * list, Data d)
{
    return list_push_front(list->prev, d);
}

Data list_pop_front (struct Node * list)
{
    return list_delete(list->next);
}

Data list_pop_back (struct Node * list)
{
return list_delete(list->prev);
}
Data list_delete (struct Node * t)
{
    Data ret = t->data;
    list_remove(t);
    free(t);
    t = 0;
    return ret;
}

void list_print (struct Node * list)
{
for (struct Node * pr = list->next; pr != list; pr = pr->next)
printf("%d ", pr->data);
printf("\n");
}

int list_is_empty (struct Node * list)
{
return (list->prev == list && list->next == list);
}

void list_clear (struct Node * list)
{
    while (!list_is_empty(list))
    list_pop_front(list);
}
Вадим
Вадим 22:11
 

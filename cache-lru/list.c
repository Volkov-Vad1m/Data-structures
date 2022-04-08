#include "LRU.h"
//...............................................................
// create empty list +
List* List_Create()
{
    List* tmp = calloc(1, sizeof(List));
    return tmp;
}
//...............................................................
// return the amount of elements in the list  +
int List_Size(const List* list) 
{
    int count = 0;
    Node* ptr = list->top;
    while(ptr)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
//...............................................................
// pop an element from the end of the list +
void List_Pop_Back(List* list)
{
    Node* prev = list->back; // запоминаем старый хвост
    
    list->back = list->back->prev;
    list->back->next = NULL;

    free(prev); // удаляем старый хвост
    return;
}
//...............................................................
// +
void List_Push_Front(List* list, int data)
{
    Node* new = calloc(1, sizeof(Node)); // выделяем память под новый узел
    new->data = data; // кладем в узел данные

    if(!list->top) // если в листе не было элементов
    {
        list->top = new;
        list->back = list->top;
        return;
    }

    new->next = list->top; 
    list->top->prev = new;
    new->prev = NULL;
    list->top = new;
        
    return;
}
//...............................................................
//...............................................................
void List_Print(List* list) // +
{
    Node* ptr = list->top;
    while (ptr)
    {
        if(ptr->next)
            printf("%d ", ptr->data);
        else
            printf("%d\n", ptr->data);
        ptr = ptr ->next;
    }
}
//...............................................................
//...............................................................
void List_Move_Upfront ( List* lst, Node *p) // +
{
    if( p == lst->top ) // если найденный элемент совпадает с головой - ничего не делаем
        return;
    if( p == lst->back) // если это хвост 
    {

        lst->back->prev->next = NULL;
        lst->back = lst->back->prev; 

        p->next = lst->top;
        p->prev = NULL;
        lst->top->prev = p;
        lst->top = p;
        
        return;
    }


    p->prev->next = p->next;
    p->next->prev = p->prev;


    lst->top->prev = p;

    p->prev = NULL;
    p->next = lst->top;
    lst->top = p;
    return;
}
//...............................................................
//...............................................................
void List_Free(List* list) // +
{
    Node* ptr = list->top;
    Node* prev = NULL;
    while(ptr)
    {
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
    free(list);
    return;  
}

#include "list.h"
//-------------------------------------------------------------
//Создание списка
List* Create_List()
{
    List* tmp = calloc(1, sizeof(List));
    return tmp;
}
//-------------------------------------------------------------
//Вставка элемента в голову
void Insert_Head(List* lst, int data)
{
    Node* new = calloc(1, sizeof(Node)); // выделяем память под узел
    new->data = data; // кладём данные в выделенный узел
    new->next = lst->head; // выделенный узел указывает на старую голову 
    lst->head = new; // выделенный узел становится головой листа 

    if ( !lst->head->next ) // если новая голова это единственный узел листа (список был пуст)
        lst->tail = lst->head;    
    return;
}
//-------------------------------------------------------------
//Вставка элемента в хвост
void Insert_Tail(List* lst, int data)
{
    Node* new = calloc(1, sizeof(Node)); // выделяем память под узел 
    new->data = data; // кладём данные в выделенный узел
    new->next = NULL; // выделенный узел указывает в никуда (так как это будующий хвост)

    if(!lst->tail) // если список был пуст 
    {
        lst->tail = new; // хвостом становится выделенный узел
        lst->head = lst->tail; // голова и узел совпадают
        return;
    }
    lst->tail->next = new; // прикрепляем выделенный узел к старому хвосту 
    lst->tail = new; // новый хвост - выделенный узел
    return;
}
//-------------------------------------------------------------
//Печать списка
void Print_List(List* lst)
{
    Node* ptr = lst->head;
    while(ptr)
    {
        if(ptr->next)
            printf("%d->", ptr->data);
        else
            printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    return;
}
//-------------------------------------------------------------
//Уничтожение списка
void Destroy_List(List* lst)
{
    Node* ptr = lst->head;
    Node* prev = NULL;
    while(ptr)
    {
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
    free(lst);
    return;  
}
//-------------------------------------------------------------
//Ищет в списке элемент, возвращает первый найденный узел с ним.
Node* Find_Elem(List* lst, int elem)
{
    assert(lst);
    Node* ptr = lst->head;
    while(ptr)
    {
        if (ptr->data == elem)
            return ptr;
        ptr = ptr->next;
    }
    return 0;
}
//-------------------------------------------------------------
//
void Delete_Node(List* lst, Node* del) // удаляем узел
{
    if(!lst) // если лист пустой 
    {
        printf("nothing to delete\n");
        return;
    }

    if(del == lst->head) // если удаляем голову 
    {
        Node* prev = lst->head; // запоминаем старую голову
        lst->head = lst->head->next; // меняем в листе указатель(голова) на следующей за ней узел
        free(prev); // очищаем старую голову
        return;
    }

    if(del == lst->tail) // если удаляем хвост 
    {
        Node* prev = lst->tail; // запоминаем старый хвост
        Node* ptr = lst->head; // будет бегать по списку
        while(ptr->next != lst->tail)
        {
            ptr = ptr->next;
        }
        // после цикла в ptr лежит предыдущий узел до хвоста. 
        lst->tail = ptr;
        lst->tail->next = NULL;
        free(prev); // удаляем старый хвост
        return;
    }

    // если удаляем из середины
    Node* ptr = lst->head; // будет бегать по списку
    while(ptr->next != del)
    {
        ptr = ptr->next;
    }
    // после цикла в ptr лежит предыдущий узел до del
    ptr->next = del->next;
    free(del);
    

    

}
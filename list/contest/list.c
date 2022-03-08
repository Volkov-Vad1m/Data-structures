#include "list.h"
//-------------------------------------------------------------
//Создание списка
List list_create()
{
    //List tmp = calloc(1, sizeof(struct Node));
    return NULL;
}
//-------------------------------------------------------------
//	кладет число х верхним элементом списка
void list_push (List * plist, Data x) 
{
    List new = calloc(1, sizeof(struct Node)); // выделяем память под узел
    new->val = x; // кладём данные в выделенный узел
    new->next = *plist; // выделенный узел указывает на старую голову 
    *plist = new; // выделенный узел становится головой листа   
    return;
}
//-------------------------------------------------------------
// достает верхнее число из списка и возвращает его
Data list_pop (List * plist)
{
    List prev = *plist; // запоминаем старую голову
    Data tmp = (*plist)->val;
    *plist = (*plist)->next; // меняем в листе указатель(голова) на следующей за ней узел
    free(prev); // очищаем старую голову
    return tmp;
}
//-------------------------------------------------------------
// возвращает число, лежащее в верхнем узле, не изменяя состояния списка
Data list_get(List list)
{
    return list->val;
}	
//-------------------------------------------------------------
//-------------------------------------------------------------
void list_print (List list)
{
    if(!list)
        printf("Empty list\n");
    while(list)
    {
        if(list->next)
            printf("%d ", list->val);
        else
            printf("%d\n", list->val);
        list = list->next;
    }
    return;
}
//-------------------------------------------------------------
//-------------------------------------------------------------
int list_size(List list)
{
    int count = 0;
    List ptr = list;
    while(ptr)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
//-------------------------------------------------------------
//-------------------------------------------------------------
int list_is_empty(List list)
{
    int tmp = list_size(list);
    return (!tmp);
}
//-------------------------------------------------------------
//-------------------------------------------------------------
void list_clear(List * plist)
{
    List ptr = *plist;
    List prev = NULL;
    while(ptr)
    {
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
    //free(plist);
    *plist = NULL;
    return; 
}






// //-------------------------------------------------------------
// //Вставка элемента в голову
// void Insert_Head(List* lst, int data)
// {
//     Node* new = calloc(1, sizeof(Node)); // выделяем память под узел
//     new->data = data; // кладём данные в выделенный узел
//     new->next = lst->head; // выделенный узел указывает на старую голову 
//     lst->head = new; // выделенный узел становится головой листа 

//     if ( !lst->head->next ) // если новая голова это единственный узел листа (список был пуст)
//         lst->tail = lst->head;    
//     return;
// }
// //-------------------------------------------------------------
// //Вставка элемента в хвост
// void Insert_Tail(List* lst, int data)
// {
//     Node* new = calloc(1, sizeof(Node)); // выделяем память под узел 
//     new->data = data; // кладём данные в выделенный узел
//     new->next = NULL; // выделенный узел указывает в никуда (так как это будующий хвост)

//     if(!lst->tail) // если список был пуст 
//     {
//         lst->tail = new; // хвостом становится выделенный узел
//         lst->head = lst->tail; // голова и узел совпадают
//         return;
//     }
//     lst->tail->next = new; // прикрепляем выделенный узел к старому хвосту 
//     lst->tail = new; // новый хвост - выделенный узел
//     return;
// }
// //-------------------------------------------------------------
// //Печать списка
// void Print_List(List* lst)
// {
//     Node* ptr = lst->head;
//     while(ptr)
//     {
//         if(ptr->next)
//             printf("%d->", ptr->data);
//         else
//             printf("%d\n", ptr->data);
//         ptr = ptr->next;
//     }
//     return;
// }
// //-------------------------------------------------------------
// //Уничтожение списка
// void Destroy_List(List* lst)
// {
//     Node* ptr = lst->head;
//     Node* prev = NULL;
//     while(ptr)
//     {
//         prev = ptr;
//         ptr = ptr->next;
//         free(prev);
//     }
//     free(lst);
//     return;  
// }
// //-------------------------------------------------------------
// //Ищет в списке элемент, возвращает первый найденный узел с ним.
// Node* Find_Elem(List* lst, int elem)
// {
//     assert(lst);
//     Node* ptr = lst->head;
//     while(ptr)
//     {
//         if (ptr->data == elem)
//             return ptr;
//         ptr = ptr->next;
//     }
//     return 0;
// }
// //-------------------------------------------------------------
// //
// void Delete_Node(List* lst, Node* del) // удаляем узел
// {
//     if(!lst) // если лист пустой 
//     {
//         printf("nothing to delete\n");
//         return;
//     }

//     if(del == lst->head) // если удаляем голову 
//     {
//         Node* prev = lst->head; // запоминаем старую голову
//         lst->head = lst->head->next; // меняем в листе указатель(голова) на следующей за ней узел
//         free(prev); // очищаем старую голову
//         return;
//     }

//     if(del == lst->tail) // если удаляем хвост 
//     {
//         Node* prev = lst->tail; // запоминаем старый хвост
//         Node* ptr = lst->head; // будет бегать по списку
//         while(ptr->next != lst->tail)
//         {
//             ptr = ptr->next;
//         }
//         // после цикла в ptr лежит предыдущий узел до хвоста. 
//         lst->tail = ptr;
//         lst->tail->next = NULL;
//         free(prev); // удаляем старый хвост
//         return;
//     }

//     // если удаляем из середины
//     Node* ptr = lst->head; // будет бегать по списку
//     while(ptr->next != del)
//     {
//         ptr = ptr->next;
//     }
//     // после цикла в ptr лежит предыдущий узел до del
//     ptr->next = del->next;
//     free(del);
    

    

// }
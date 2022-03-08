#include "list.h"

int main()
{
    List* top = NULL;

    top = Create_List ();

    Insert_Head (top, 5);
    Print_List(top);
    Insert_Head (top, 1);
    Print_List(top);
    Insert_Tail(top, 10);
    Print_List(top);
    Node* huy = Find_Elem(top, 5);
    printf("%p\n", huy->next);
    printf("%d\n", huy->data);
    Delete_Node(top, huy);
    Print_List(top);
    Destroy_List(top);
    return 0;
}
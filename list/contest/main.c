#include "list.h"

int main()
{
    List list = list_create();
    list_print(list);
    list_push(&list, 5);
    list_print(list);
    list_clear(&list);
    return 0;
}
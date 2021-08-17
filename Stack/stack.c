#include "stack.h"
//.............................................................
//.............................................................
Stack* Stack_Construct(int cap) // создание стэка
{
   Stack* stk = calloc(1, sizeof(Stack) + sizeof(type) * cap);
   assert(stk != NULL);
   stk->capacity = cap;
   stk->stk_ptr = stk->stk_start;
   
   return stk; 
}
//.............................................................
//.............................................................
int Is_Stack_Full(Stack *stk) //проверка на переполнение стэка
{
    if( (stk->stk_ptr - stk->stk_start) >= stk->capacity )
        return 1;
    return 0;
}
//.............................................................
//.............................................................
void Stack_Push(Stack* stk, type elem) // положить на стэк
{
    assert(stk != NULL);
    if (Is_Stack_Full(stk))
    {
        printf("Stack is full(master)\nNuhay bebru\n");
        return;
    }
    *(stk->stk_ptr) = elem;
    stk->stk_ptr++;

}
//.............................................................
//.............................................................
void Stack_Print(Stack* stk)
{
    assert(stk != NULL);
    int i = 0;
    printf("capacity: %d\n", stk->capacity);
    for(i; i < stk->stk_ptr - stk->stk_start; i++)
        printf("[%d]: %d\n",i, stk->stk_start[i]);
}
//.............................................................
//.............................................................
int Is_Stack_Empty(Stack* stk)
{
    if( stk->stk_ptr - stk->stk_start <= 0 )
        return 1;
    return 0;
}
//.............................................................
//.............................................................
type Stack_Pop(Stack* stk)
{
    assert(stk != NULL);
    if( Is_Stack_Empty(stk) )
    {
        printf("Jui opilki, ya pust dyadya!\n");
        return 0;
    }
    type tmp = *(stk->stk_ptr - 1);
    *(stk->stk_ptr - 1) = POISON;
    stk->stk_ptr--;
    return tmp;
}
//.............................................................
//.............................................................
void Stack_Destrucktor(Stack* stk)
{
    free(stk);
};
//.............................................................
//.............................................................

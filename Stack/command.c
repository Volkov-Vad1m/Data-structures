#include "stack.h"
//.............................................................
//............................................................. 
static int flag = 0;
//.............................................................
//............................................................. 
void Stack_Start()
{ 
    char buf[20];
    Stack* stack;
    while (1)
    {
        scanf("%s", buf);
        switch (Command_Recognize(buf))
        {
        case 0: printf("Good bye!\n"); return;
        case 1: Work_With_Push(stack); break;
        case 2: Work_With_Pop(stack); break;
        case 3: stack = Work_With_Construct(stack); break; 
        case 4: Work_With_Destruct(stack); break;
        case 5: Work_With_Print(stack); break;
        default: printf("I don't know this command\n"); break;
        }
    }
}
//.............................................................
//.............................................................
int Command_Recognize(char* buf)
{
    if (strcmp(buf, "exit") == 0)
        return 0;
    if (strcmp(buf, "push") == 0)
        return 1;
    if (strcmp(buf, "pop") == 0)
        return 2;
    if (strcmp(buf, "construct") == 0)
        return 3;
    if (strcmp(buf, "destruct") == 0)
        return 4;
    if (strcmp(buf, "print") == 0)
        return 5;
}
//.............................................................
//.............................................................
int Argument_Receiver()
{
    int tmp = 0;
    scanf("%d", &tmp);
    return tmp;  
}
//.............................................................
//.............................................................
void Work_With_Push(Stack* stack)
{
    if (flag == 0)
    {
        printf("Stack not created\n");
        return;
    }
    
    int elem = Argument_Receiver();
    Stack_Push(stack, elem);
    return;
}
//.............................................................
//.............................................................
void Work_With_Pop(Stack* stack)
{
   if (flag == 0)
    {
        printf("Stack not created\n");
        return;
    }
    
    Stack_Pop(stack);
    return;
}
//.............................................................
//.............................................................
Stack* Work_With_Construct(Stack* stack)
{
    if (flag == 1)
    {
        printf("The stack has already been created\n");
        return stack;
    }
    stack = Stack_Construct(Argument_Receiver());
    flag = 1;
    printf("Stack successfully created\n");
    return stack;
}
//.............................................................
//.............................................................
void Work_With_Destruct(Stack* stack)
{
    if (flag == 0)
    {
        printf("Stack has not been created yet\n");
        return;
    }
    Stack_Destrucktor(stack);
    flag = 0;
    printf("Stack successfully removed\n");
}
//.............................................................
//.............................................................
void Work_With_Print(Stack* stack)
{
    if (flag == 0)
    {
        printf("Stack not created\n");
        return;
    }
    Stack_Print(stack);
    return;
}
//.............................................................
//.............................................................
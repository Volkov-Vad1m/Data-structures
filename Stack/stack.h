#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//.............................................................
//.............................................................
#define POISON -666
//.............................................................
//.............................................................
typedef int type;

typedef struct
{
    int capacity;
    type* stk_ptr;
    type stk_start[0];
    
}Stack;
//.............................................................
//.............................................................
Stack* Stack_Construct(int cap);
int Is_Stack_Full(Stack *stk);
void Stack_Push(Stack* stk, type elem);
void Stack_Print(Stack* stk);
int Is_Stack_Empty(Stack* stk);
type Stack_Pop(Stack* stk);
void Stack_Destrucktor(Stack* stk);
void Stack_Start();
int Command_Recognize(char* buf);
int Argument_Receiver();
void Work_With_Push(Stack* stack);
void Work_With_Pop(Stack* stack);
Stack* Work_With_Construct(Stack* stack);
void Work_With_Destruct(Stack* stack);
void Work_With_Print(Stack* stack);
//.............................................................
//.............................................................

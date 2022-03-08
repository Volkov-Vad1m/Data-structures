#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SIZE 10
//-------------------------------------------------------------
//-------------------------------------------------------------
typedef struct Nod
{
    struct Nod* next;
    int data;    
}Node;

typedef struct
{
    Node* head;
    Node* tail;
}List;
//-------------------------------------------------------------
//-------------------------------------------------------------
List* Create_List();
void Insert_Head(List* lst, int data);
void Insert_Tail(List* lst, int data);
void Print_List(List* lst);
void Destroy_List(List* lst);
Node* Find_Elem(List* lst, int elem);
void Delete_Node(List* lst, Node* del);

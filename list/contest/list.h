#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SIZE 10
//-------------------------------------------------------------
//-------------------------------------------------------------
typedef int Data;
struct Node {
    Data val;
    struct Node * next;
};
typedef struct Node* List;
//-------------------------------------------------------------
//-------------------------------------------------------------
List list_create (); 
void list_push (List * plist, Data x); 
Data list_pop (List * plist); 	
Data list_get(List list); 
void list_print (List list); 
int list_size(List list);
void list_clear(List * plist);
int list_is_empty(List list);
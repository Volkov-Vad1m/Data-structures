#pragma once
#include <stdio.h>
#include <stdlib.h>

enum SIZE{
    SIZE = 21373
};
// List part
//...............................................................
typedef struct list_node_t 
{
    struct list_node_t *next;
    struct list_node_t *prev;
    int data;
}Node; // узел списка

typedef struct list_t 
{
    struct list_node_t *top;
    struct list_node_t *back;
}List; // структура хранит указатели на голову и хвост 
//...............................................................
//...............................................................
List* List_Create();
int List_Size(const List *list);
void List_Pop_Back(List* list);
void List_Push_Front(List* list, int data);
void List_Print(List* list);
void List_Move_Upfront ( List* lst, Node* p);
void List_Free(List* list);
//...............................................................
//...............................................................
// Hash part

typedef struct hashmap_node_t {
    struct hashmap_node_t* next;
    struct hashmap_node_t* prev;
    int key;
    Node* node;
}Hash_Node; // узел хэш массива

typedef struct hash_t {
    Hash_Node **htab;
    int len;
}Hash; // структура хранит указатель на начало массива указателей на хэш узлы и размер массива
//...............................................................
//...............................................................
Hash* Htable_Create(int len);
Node* Htable_Find(Hash* h, int request);
int Hash_of_Data (int data);
void Htable_Free(Hash* h);
void Htable_Insert(Hash* h, Node* data);
void Htable_Print(Hash* htable);
void Htable_Erase(Hash* h, int request);
void Hlist_Free(Hash_Node* node);
//...............................................................
//...............................................................
// Cache part
typedef struct cache_t{
    int size;
    Hash* hash; 
    List* lst;
}Cache;

Cache* Cache_Create(int cache_size);
int Cache_Lookup_Update(Cache *c, int request);
void Cache_Free(Cache* cache);
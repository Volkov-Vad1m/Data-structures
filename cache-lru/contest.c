#include <stdio.h>
#include <stdlib.h>

enum SIZE {
    SIZE = 51373
};
// List part
//...............................................................
typedef struct list_node_t {
    struct list_node_t *next;
    struct list_node_t *prev;
    int data;
} Node; // узел списка

typedef struct list_t {
    struct list_node_t *top;
    struct list_node_t *back;
} List; // структура хранит указатели на голову и хвост 
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
} Hash_Node; // узел хэш массива

typedef struct hash_t {
    Hash_Node **htab;
    int len;
} Hash; // структура хранит указатель на начало массива указателей на хэш узлы и размер массива
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
typedef struct cache_t {
    int size;
    Hash* hash; 
    List* lst;
} Cache;

Cache* Cache_Create(int cache_size);
int Cache_Lookup_Update(Cache *c, int request);
void Cache_Free(Cache* cache);


int main()
{
    int size = 0;
    int num_queries = 0;
    scanf("%d", &size);
    scanf("%d", &num_queries);
    Cache* cache = NULL;
    cache = Cache_Create(size);
    int hits = 0;
    int id = 0;
    for (int i = 0; i < num_queries; i++) 
    {
        scanf("%d", &id);
        if (Cache_Lookup_Update(cache, id) )
            hits += 1;
    }
    printf("%d\n", hits);

    Cache_Free(cache);

}
//...............................................................
// create empty list +
List* List_Create()
{
    List* tmp = (List*)calloc(1, sizeof(List));
    return tmp;
}
//...............................................................
// return the amount of elements in the list  +
int List_Size(const List* list) 
{
    int count = 0;
    Node* ptr = list->top;
    while(ptr)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
//...............................................................
// pop an element from the end of the list +
void List_Pop_Back(List* list)
{
    Node* prev = list->back; // запоминаем старый хвост
    
    list->back = list->back->prev;
    list->back->next = NULL;

    free(prev); // удаляем старый хвост
    return;
}
//...............................................................
// +
void List_Push_Front(List* list, int data)
{
    Node* newNode = (Node*)calloc(1, sizeof(Node)); // выделяем память под новый узел
    newNode->data = data; // кладем в узел данные

    if(!list->top) // если в листе не было элементов
    {
        list->top = newNode;
        list->back = list->top;
        return;
    }

    newNode->next = list->top; 
    list->top->prev = newNode;
    newNode->prev = NULL;
    list->top = newNode;
        
    return;
}
//...............................................................
//...............................................................
void List_Print(List* list) // +
{
    Node* ptr = list->top;
    while (ptr)
    {
        if(ptr->next)
            printf("%d ", ptr->data);
        else
            printf("%d\n", ptr->data);
        ptr = ptr ->next;
    }
}
//...............................................................
//...............................................................
void List_Move_Upfront ( List* lst, Node *p) // +
{
    if( p == lst->top ) // если найденный элемент совпадает с головой - ничего не делаем
        return;
    if( p == lst->back) {

        lst->back->prev->next = NULL;
        lst->back = lst->back->prev; 

        p->next = lst->top;
        p->prev = NULL;
        lst->top->prev = p;
        lst->top = p;
        
        return;
    }


    p->prev->next = p->next;
    p->next->prev = p->prev;


    lst->top->prev = p;

    p->prev = NULL;
    p->next = lst->top;
    lst->top = p;
    return;
}
//...............................................................
//...............................................................
void List_Free(List* list) // +
{
    Node* ptr = list->top;
    Node* prev = NULL;
    while(ptr)
    {
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
    free(list);
    return;  
}
//...........................................................
// создаёт пустой хеш с заданным количеством бакетов
Hash* Htable_Create(int len) // +
{
    Hash*  htable = (Hash*)calloc(1, sizeof(Hash));
    htable->len = len;
    htable->htab = (struct hashmap_node_t**)calloc(len, sizeof(struct hashmap_node_t*));
    return htable;
}
//...........................................................
// ищет узел по ключу
Node* Htable_Find(Hash* h, int request) //+
{
    int key = Hash_of_Data(request);

    Hash_Node* cur = h->htab[key];
    while(cur)
    {
        if(cur->node->data == request)
            return cur->node;
        
        cur = cur->next;
    }

    return NULL;

}

int Hash_of_Data (int data) // +
{
    int key = 0;

    int size = SIZE;
    int prime = 29091;
    int coeff_1 = 211;
    int coeff_2 = 5211;

    key = ((coeff_1 * data + coeff_2) % prime) % size;

    return key;
}

void Hlist_Free(Hash_Node* node) // +
{
    Hash_Node* prev = NULL;
    while(node)
    {
        prev = node;
        node = node->next;
        free(prev);
    }
    return;  
}

void Htable_Free(Hash* h) // +
{
    int len = h->len;
    Hash_Node* cur = NULL;
    for(int i = 0; i < len; i++)
    {
        cur = h->htab[i];
        if(cur)
            Hlist_Free(cur);
    }
    free(h->htab);
    free(h);
    return;
}

void Htable_Insert(Hash* h, Node* data) //
{
    int key = Hash_of_Data(data->data);
    Hash_Node* ptr = h->htab[key]; // указатель на элемент в хэш таблице
    Hash_Node* newElem = (Hash_Node*)calloc(1, sizeof(Hash_Node)); 

    newElem->key = key;
    newElem->node = data; 
    if(!h->htab[key])
    {
        h->htab[key] = newElem;
        return;
    }
    // перевязываем указатели, вставляем вначало
    newElem->next = ptr;
    newElem->prev = NULL;
    h->htab[key]->prev = newElem;
    h->htab[key] = newElem;
    return;
   
}

// стирает пару ключ+значение из хеша по ключу
void Htable_Erase(struct hash_t *h, int backid)
{
    int key = Hash_of_Data(backid);
    Hash_Node* cur = h->htab[key];
    Hash_Node* prev;

    while(cur)
    {
        if(cur->node->data == backid)
            break;
        cur = cur->next;
    }
    // в cur то что надо удалить 
    if(!cur->prev)
    {
        prev = cur;
        if(!cur->next)
        {
            h->htab[key] = NULL;
            free(cur);
            return;
        }
        h->htab[key] = cur->next;
        h->htab[key]->prev = NULL;
        free(prev);
        return;
    }
    if(!cur->next)
    {
        prev = cur;
        cur->prev->next = NULL;
        free(prev);
        return;
    }

    cur->next->prev = cur->prev;
    cur->prev->next = cur->next;
    free(cur);
    return;

}

void Htable_Print(Hash* htable) // +
{
    Hash_Node** ptr_arr = htable->htab;
    int len = htable->len;
    Hash_Node* cur = NULL;
    Hash_Node* ptr_lst = NULL;
    for(int i = 0; i < len; i++)
    {
        cur = ptr_arr[i];
        if(cur)
        {
            printf("h[%d]: ", i);
            ptr_lst = cur;
            while(ptr_lst)
            {
                printf("%d ", ptr_lst->node->data);
                ptr_lst = ptr_lst->next;
            }
            printf("\n");
        }
    }
    return;
}
//...............................................................
//...............................................................
Cache* Cache_Create(int cache_size)
{
    Cache* cache = (Cache*)calloc(1, sizeof(Cache));
    cache->size = cache_size;
    cache->hash = Htable_Create(SIZE);
    cache->lst = List_Create();
    return cache;
}
//...............................................................
//...............................................................
int Cache_Lookup_Update(Cache *c, int request)
{
    Node* pnode = Htable_Find(c->hash, request);
    if(pnode == NULL) // если ничего не нашли 
    {   
        if (List_Size(c->lst) == c->size) // eсли кэш заполнен
        { 
            int backid = c->lst->back->data;
            Htable_Erase(c->hash, backid);
            List_Pop_Back(c->lst);
        }
        
        List_Push_Front(c->lst, request);
        Htable_Insert(c->hash, c->lst->top);
        return 0;
    }
    List_Move_Upfront(c->lst, pnode);
    return 1;
}

void Cache_Free(Cache* cache)
{
    List_Free(cache->lst);
    Htable_Free(cache->hash);
    free(cache);
}
#include "LRU.h"
//...........................................................
// создаёт пустой хеш с заданным количеством бакетов
Hash* Htable_Create(int len) // +
{
    Hash*  htable = calloc(1, sizeof(Hash));
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
    Hash_Node* newElem = calloc(1, sizeof(Hash_Node)); 

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


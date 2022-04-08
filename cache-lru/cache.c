#include "LRU.h"
//...............................................................
//...............................................................
Cache* Cache_Create(int cache_size)
{
    Cache* cache = calloc(1, sizeof(Cache));
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
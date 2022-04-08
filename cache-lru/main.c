#include "LRU.h"

int main()
{
    int size = 0;
    int num_queries = 0;
    scanf("%d", &size);
    scanf("%d", &num_queries);
    Cache* cache = Cache_Create(size);
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
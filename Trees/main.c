#include "Tree.h"

int main()
{
    TreeNode * root = 0;
    int i, a;
    while(scanf("%d", &a) != EOF)
    {
        root = SimpleInsertNode(root, a);
        //PrintTreeLevel(root);
    }
    PrintTreeLevel(root);
    root = Destroy(root);
    return 0;
}
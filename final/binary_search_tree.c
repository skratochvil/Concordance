#include <stdlib.h>
#include <string.h>

#include "binary_search_tree.h"

    struct tree_node *
insert(struct tree_node *root, const char *str)
{
    if (root == NULL) {
        root = (struct tree_node *) malloc(sizeof(struct tree_node));
        root->datum = (char *) malloc(strlen(str) + 1);
        root -> count = 1;
        strcpy(root->datum, str);
        root->left = root->right = NULL;
    } else if (strcmp(str, root->datum) < 0) {
        root->left = insert(root->left, str);
    } else if (strcmp(str, root->datum) > 0) {
        root->right = insert(root->right, str);
    }

    return root;
}

    struct tree_node *
find(struct tree_node *root, const char *str)
{
    int cmp;

    if (root == NULL) {return root;}

    cmp = strcmp(str, root->datum);

    if (cmp == 0) {
        return root;
    } else if (cmp < 0) {
        return find(root->left, str);    
    } else {
        return find(root->right, str);
    }
}    

    int
contains(const struct tree_node *root, const char *str)
{
    int cmp;

    if (root == NULL) {return 0;}

    cmp = strcmp(str, root->datum);

    if (cmp == 0) {
        return 1;
    } else if (cmp < 0) {
        return contains(root->left, str);
    } else {
        return contains(root->right, str);
    } 
} 

void upcount(struct tree_node *root) 
{
    root->count = root->count + 1;
}



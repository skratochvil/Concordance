#ifndef BINARY_SEARCH_TREE_DEFINED
#define BINARY_SEARCH_TREE_DEFINED

struct tree_node
{
    char *datum;
    int count;
    struct tree_node *left;
    struct tree_node *right;
};

struct tree_node *
insert(struct tree_node *, const char *);

struct tree_node *
find(struct tree_node *, const char *);

int contains (const struct tree_node *, const char *);

void upcount(struct tree_node *);

#endif


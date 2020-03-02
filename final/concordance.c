#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "binary_search_tree.h"

#define MAX_LEN 256
#define DELIMS ";:-,.?!\"\t\n "
#define WORD_LEN 80
#define MIN_ARGS 1

void print_all(const struct tree_node *);
struct tree_node* tally(FILE *, struct tree_node *);
void upstring(char *);
struct tree_node * clear(struct tree_node *);


int main(int argc, const char *argv[])
{
    FILE *src;
    struct tree_node *tree = NULL;

    if (argc <= MIN_ARGS) {
        src = stdin;
    } else {
        src = fopen(argv[1], "r");
    }

    if (src == NULL) {
        printf("Unable to open file!");
        return EXIT_FAILURE;
    }

    tree = tally(src,tree);    
    print_all(tree);
    clear(tree);


    if ((src != stdin) && (src != NULL)) {
        fclose(src);
    }

    return EXIT_SUCCESS;    
}

struct tree_node* tally(FILE *src, struct tree_node *root) 
{
    char line[MAX_LEN];
    char *word;
    struct tree_node *node = NULL;

    while (fgets(line,MAX_LEN,src) != NULL) {
        word = strtok(line, DELIMS);
        while (word != NULL) {

          //  upstring(word);
            if (!contains(root, word)) {
               root = insert(root, word);
            } else {
                node = find(root, word);
                upcount(node);
            }         
            
            word = strtok(NULL, DELIMS);
        }
    } 
    return root;
}
   
void upstring(char *ptr)
{    
    while (*ptr != '\0') {
        *ptr = toupper(*ptr);
        ptr++;
    }    
}

void print_all(const struct tree_node *root)
{
    if (root != NULL) {
        print_all(root->left);
        printf("%s:\t%-d\n", root->datum, root->count);
        print_all(root->right);
    }
}    


struct tree_node * clear(struct tree_node *T)
{
    if (T != NULL) {
        T->left = clear(T->left);
        T->left = NULL;  //good to set cleared pointers to NULL so you don't maintain the meaningless address
        T ->right = clear(T->right);
        T ->right = NULL;
        free(T);
        return NULL;
        }

        return NULL; 
}    


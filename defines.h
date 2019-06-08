/*---------------------------------------------------------------------------
 * 
 * defines.h 
 *
 *     06/08/2019 - 
 *
 *
 *---------------------------------------------------------------------------
 */

#ifndef DEFINES_H
#define DEFINES_H

#define SIZE 100
#define INCLUDE_MAIN 0
#define ENABLE_DEBUG 1

#define TREE_DEBUG(args...)\
  if(ENABLE_DEBUG)\
  printf(args);

typedef struct stack_s {
    void *arr[SIZE];
    int top;
}stack_t;

void push(stack_t *s, void *node); 
void *pop(stack_t *s);
void stack_init(stack_t *s);

typedef struct queue_s {
    void  *arr[SIZE];
    int front, tail;
} queue_t;

void enqueue(queue_t *q, void * node);
void *dequeue(queue_t *q);
void queue_init(queue_t *q);

typedef struct node_s {
    struct node_s   *next;
    struct node_s   *prev;
    int             data;
}node;

typedef enum {
    BST,
    AVL,
    TYPE_MAX
}tree_types_t;

// Forward decl.
typedef struct tree_s tree_t;

typedef void    (*tree_insert)  (tree_t *t, node *n);
typedef void    (*tree_delete)  (tree_t *t, node *n);
typedef void    (*tree_print)   (tree_t *t);
typedef node*   (*tree_search)  (tree_t *t, node *n);
typedef int     (*tree_compare) (node *n1, node *n2);

typedef struct tree_func_p {
    tree_insert in;
    tree_delete del;
    tree_print  print;
    tree_search search;
} tree_funcs;

typedef struct tree_s {
    node            *root;
    tree_types_t    type;
    tree_compare    compare;
    tree_funcs      *fp;
}tree_t;

void  bst_tree_insert    (tree_t *t, node *n);
void  bst_tree_delete    (tree_t *t, node *n);
void  bst_tree_print     (tree_t *t);
node* bst_tree_search    (tree_t *t, node *n);


#endif /* DEFINES_H */

/*---------------------------------------------------------------------------
 * 
 * trees.c 
 *
 *     06/08/2019 - 
 *
 *---------------------------------------------------------------------------
 */

#include<stdio.h>
#include"defines.h"
/////////////////////////////////////////////////////////////////////////////
//              STUBS
/////////////////////////////////////////////////////////////////////////////
void tree_stub          (tree_t *t, node *n) {return;}
void tree_stub_print    (tree_t *t){return;}
node * tree_stub_search (tree_t *t, node *n){return NULL;}

/////////////////////////////////////////////////////////////////////////////
//          FUNCTION POINTERS to different  TREE Types
/////////////////////////////////////////////////////////////////////////////
tree_funcs tree_fps[TYPE_MAX] = 
{   // REGULAR
    {
        .in      = bst_tree_insert,
        .del     = bst_tree_delete,
        .print   = bst_tree_print,
        .search  = bst_tree_search
    },
    //AVL
    {
        .in     = tree_stub,
        .del    = tree_stub,
        .print  = tree_stub_print,
        .search = tree_stub_search,
    }
};

/////////////////////////////////////////////////////////////////////////////
//      COMMON TREE FUNCTIONS
/////////////////////////////////////////////////////////////////////////////
void
tree_init (tree_t *t, tree_types_t type, 
           tree_compare compare) {
    t->type = type;
    t->fp = &tree_fps[type]; 
    t->compare = compare;
}
void
tinsert(tree_t *t, node *n) {
    t->fp->in(t, n);
}
void
tdelete(tree_t *t, node *n) {
    t->fp->del(t, n);
}
void
tprint(tree_t *t) {
    t->fp->print(t);
}
void
tsearch(tree_t *t, node *n) {
    t->fp->search(t,n);
}

/////////////////////////////////////////////////////////////////////////////
//          RGULAR TREE DEFINITIONS
/////////////////////////////////////////////////////////////////////////////
void 
bst_tree_insert(tree_t *t, node *n) {
    TREE_DEBUG("[%s]Inserting the node\n", __FUNCTION__);
}

void 
bst_tree_delete(tree_t *t, node *n) {
    TREE_DEBUG("[%s]deleting the node\n", __FUNCTION__);
}

void 
bst_tree_print(tree_t *t) {
    TREE_DEBUG("[%s]printing tree\n", __FUNCTION__);
}

node*
bst_tree_search(tree_t *t, node *n) {
    TREE_DEBUG("[%s]searching the node\n", __FUNCTION__);
}

int
node_compare(node *n1, node *n2) {
    if(n1->data < n2->data) return -1;
    if(n1->data > n2->data) return 1;
    return 0;
}

void main() {
    tree_t t;
    node n;
    tree_init(&t, BST, node_compare);
    tinsert(&t, &n);
    tdelete(&t, &n);
    tsearch(&t, &n);
    tprint(&t);
}


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
node * tree_stub          (tree_t *t, node *n) {return;}
void tree_stub_print    (tree_t *t){return;}
node * tree_stub_search (tree_t *t, node *n){return NULL;}
node * tree_stub_min_max (node *root){return NULL;}

/////////////////////////////////////////////////////////////////////////////
//          FUNCTION POINTERS to different  TREE Types
/////////////////////////////////////////////////////////////////////////////
tree_funcs tree_fps[TYPE_MAX] = 
{   // REGULAR
    {
        .in      = bst_tree_insert,
        .del     = bst_tree_delete,
        .print   = bst_tree_print,
        .search  = bst_tree_search,
        .max     = bst_tree_max,
        .min     = bst_tree_min
    },
    //AVL
    {
        .in     = tree_stub,
        .del    = tree_stub,
        .print  = tree_stub_print,
        .search = tree_stub_search,
        .max    = tree_stub_min_max,
        .min    = tree_stub_min_max,
    }
};

/////////////////////////////////////////////////////////////////////////////
//      COMMON TREE FUNCTIONS
/////////////////////////////////////////////////////////////////////////////
void
tree_init (tree_t *t, tree_types_t type, 
           tree_compare compare) {
    t->root = NULL;
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
node *
tsearch(tree_t *t, node *n) {
    return t->fp->search(t,n);
}

node *
tmax(tree_t *t, node *root) {
    return t->fp->max(root);
}

node *
tmin(tree_t *t, node *root) {
    return t->fp->min(root);
}

/////////////////////////////////////////////////////////////////////////////
//          RGULAR TREE DEFINITIONS
/////////////////////////////////////////////////////////////////////////////
node * 
bst_tree_insert(tree_t *t, node *n) {

    node *tmp = NULL;
    node *prev = NULL;

    TREE_DEBUG("[%s]Inserting the node\n", __FUNCTION__);
    if (!t->root) {
        TREE_DEBUG("First node "); 
        t->root = n;
        return;
    }
    tmp = t->root;
    while(tmp) {
        prev = tmp;
        if(t->compare(tmp, n)>0) {
            tmp = tmp->right;
        } else {
            tmp = tmp->left;
        }
    }
    if(t->compare(prev, n)>0) 
        prev->right = n;
    else
        prev->left = n;

}

node *
bst_tree_delete(tree_t *t, node *n) {
    TREE_DEBUG("[%s]deleting the node\n", __FUNCTION__);
    node *root=t->root;
    node *temp;
    tree_t t1=*t;
    if ( !root  ) {
        TREE_DEBUG("[%s] No data to delete", __FUNCTION__);
        return root;
    }
    if ( t->compare(root,n)<0) {
        t1.root = root->left;
        root->left=bst_tree_delete(&t1, n);
    } else if ( t->compare(root,n)>0 ) {
        t1.root = root->right;
        root->right=bst_tree_delete(&t1, n);
    } else {
        if ( root->left && root->right ) {
            temp = bst_tree_max(root->left);
            root->data = temp->data;
            t1.root = root->left;
            root->left = bst_tree_delete(&t1, root);
        } else {
            temp = root;
            if ( !root->left )
                root=root->right;
            if ( !root->right ) {
                root=root->left;
            }
        }
    }
    return(root);
}

void 
bst_tree_print(tree_t *t) {
    TREE_DEBUG("[%s]printing tree\n", __FUNCTION__);
    tree_t t1;
    if ( !t->root ) {
        return;
    }
    t1.root = t->root->left;
    bst_tree_print(&t1);
    t1.root = t->root->right;
    bst_tree_print(&t1);
    t->root->nprint(t->root);
    return;
}

node*
bst_tree_search(tree_t *t, node *n) {
    TREE_DEBUG("[%s]searching the node\n", __FUNCTION__);
}

node*
bst_tree_max(node *root) {
    if ( !root  ) {
        return NULL;
    }
    while ( root->right!=NULL  ) {
        root = root->right;
    }
    return root;
}

node*
bst_tree_min(node *root) {
    if ( !root  ) {
        return NULL;
    }
    while ( root->left!=NULL  ) {
        root = root->left;
    }
    return root;
}

/////////////////////////////////////////////////////////////////////////////
//          Program spcific code from here.
/////////////////////////////////////////////////////////////////////////////
int
node_compare(node *n1, node *n2) {
    if(n1->data > n2->data) return -1;
    if(n1->data < n2->data) return 1;
    return 0;
}

void
node_print(node *n) {
    printf("%d\n", n->data);
}

void main() {
    tree_t t;
    node n[10];
    int data[10] = {13,3,41,2,72,33,445,5,100,32};
    int i;
    tree_init(&t, BST, node_compare);
    for ( i=0 ;i<10 ;i++ ) {
        n[i].data = data[i];
        n[i].nprint = node_print;
        n[i].left = n[i].right = NULL;
        tinsert(&t, &n[i]);
    }
    tprint(&t);
    printf("delete");
    tdelete(&t, &n[2]);
 //   tsearch(&t, &n[0]);
    tprint(&t);
}


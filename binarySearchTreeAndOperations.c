// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

#define TRUE    1
#define FALSE   0
/* Implementation Of BST and it's associated operations */
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} NODE;

/* The below function pointer can be used to pass the callback function,which we are using
during search, traversal, etc. to print or do additional action */
typedef void(*traversal_cb)(int data);

/* Function declarations used in this program */
static NODE* __bst_new_node(int data, NODE* left, NODE* right);
static void __bst_insert(NODE**, int);
static size_t __bst_size(NODE*);
static void __bst_free(NODE**);
static int __bst_min_value(NODE *);
static int __isbinary_search_tree_util(NODE * node, int min, int max);
static size_t __bst_height(NODE * node);
static void __bst_traverse_given_level(NODE * node, size_t level, traversal_cb cb);

/* Create a node of the BST and use the created Node to insert into the BST */
static NODE* __bst_new_node(int data, NODE* left, NODE* right)
{
	NODE* node = (NODE *)malloc(sizeof(NODE));
	node->data = data;
	node->left = left;
	node->right = right;
	return node;
}

/* A utility function to insert a created new node with given data in BST */
void binary_search_tree_insert(NODE** root, int value)
{
	__bst_insert(root, value);
}

static void __bst_insert(NODE** node, int data)
{
	if(*node == NULL) {
		*node = __bst_new_node(data, NULL, NULL);	
	} else {
		if(data == (*node)->data) {
			return;
		}
		else if(data <= (*node)->data) {
			__bst_insert( &((*node)->left), data);
		} else {
			__bst_insert( &((*node)->right), data);
		}			
	}
}

/* Utility function Computes the number of nodes in a tree */
size_t binary_search_tree_size(NODE * root)
{
	return __bst_size(root);
}

static size_t __bst_size(NODE* node)
{
	if(node == NULL) {
		return 0;
	} else {
		return (__bst_size(node->left) + 1 + __bst_size(node->right));
	}
}


/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
size_t binary_search_tree_height(NODE * root)
{
	return __bst_height(root);
}

static size_t __bst_height(NODE * node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        size_t lheight = __bst_height(node->left);
        size_t rheight = __bst_height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(size_t)(lheight+1);
        else return(size_t)(rheight+1);
    }
}


/* The traversal_cb is a function pointer which need to be passed for the action to be taken
    during traversal. It may be simple print function */
void binary_search_tree_traverse_in_order(NODE * node, traversal_cb cb)
{	
	if(node == NULL) {
		return;
	}
    /* Visit left node fist, then to root and right */
	binary_search_tree_traverse_in_order(node->left, cb);
	cb(node->data);
	binary_search_tree_traverse_in_order(node->right, cb);
}

void binary_search_tree_traverse_preorder(NODE * node, traversal_cb cb)
{	
	if(node == NULL) {
		return;
	}
    /* Visit root node fist, then to left and right */
    cb(node->data);
	binary_search_tree_traverse_preorder(node->left, cb);
	binary_search_tree_traverse_preorder(node->right, cb);
}

void binary_search_tree_traverse_postorder(NODE * node, traversal_cb cb)
{	
	if(node == NULL) {
		return;
	}
    /* Visit left node fist, then to right and lastly root node */
	binary_search_tree_traverse_postorder(node->left, cb);
	binary_search_tree_traverse_postorder(node->right, cb);
    cb(node->data);
}

void binary_search_tree_levle_order_traverse(NODE * node, traversal_cb cb)
{
	if(node == NULL) {
		return;
	}
    size_t treeHeight = __bst_height(node);
    int level = 1;
    /* Visit nodes at each level */
    for(; level <= treeHeight; level++)
        __bst_traverse_given_level(node, level, cb);
}

static void __bst_traverse_given_level(NODE * node, size_t level, traversal_cb cb)
{
	if(node == NULL) {
		return;
	}
    /* Visit left node and right node at each level */
    if (level == 1)
        cb(node->data);
    else if (level > 1) {
        __bst_traverse_given_level(node->left, level-1, cb);
        __bst_traverse_given_level(node->right, level-1, cb);
    }
}

/* Utility function to delete or free a given node in the BST */
void binary_search_tree_free(NODE** node)
{
	__bst_free(node);
}

static void __bst_free(NODE** node)
{
	if(*node == NULL) {
		return;
	}
	__bst_free(&((*node)->left));
	__bst_free(&((*node)->right));
	
	free(*node);
	*node = NULL;
}

/* Utility function to find the minimum value stored in a given BST */
int bst_min_value(NODE * root)
{
	return __bst_min_value(root);
}

static int __bst_min_value(NODE * root)
{
	NODE* node = root->left;
	while(node->left != NULL) {
		node = node->left;
	}
	return node->data;
}


/* Utility function to search a given data in the BST with given root node */
void binary_search_tree_search(NODE * root, int value, int** out)
{
    if(root == NULL) {		
        return;
    } else {
        if(value == root->data) {
            *out = &root->data;
        } 

        if(value <= root->data) {
            binary_search_tree_search(root->left, value, &(*out));
        } else {
            binary_search_tree_search(root->right, value, &(*out));
        }
    }
}

 
/* Returns true if the given tree is a binary search tree 
 (efficient version). */
int isbinary_search_tree(NODE* node) 
{ 
  return(__isbinary_search_tree_util(node, INT_MIN, INT_MAX)); 
} 
 
/* Returns true if the given tree is a BST and its 
   values are >= min and <= max. */
static int __isbinary_search_tree_util(NODE * node, int min, int max) 
{ 
 
  /* An empty tree is a valid BST */
  if (node == NULL) 
     return TRUE;
       
  /* Return FALSE if this node violates the min/max constraint */ 
  if (node->data < min || node->data > max) 
     return FALSE; 
    
  /* otherwise check the subtrees recursively, tightening the min or max constraint */
  return (
    __isbinary_search_tree_util(node->left, min, node->data-1) &&  // Allow only distinct values
    __isbinary_search_tree_util(node->right, node->data+1, max) );  // Allow only distinct values
} 
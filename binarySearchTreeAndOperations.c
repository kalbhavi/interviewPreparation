// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>

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

/* Utility function to find the height of the BST */
size_t binary_search_tree_size(NODE * root)
{
	return __bst_size(root);
}

static size_t __bst_size(NODE* node)
{
	if(node == NULL) {
		return 0;
	} else {
		return __bst_size(node->left) + 1 + __bst_size(node->right);
	}
}



/* The traversal_cb is a function pointer which need to be passed for the action to be taken
    during traversal. It may be simple print function */
void binary_search_tree_traverse_in_order(NODE * node, traversal_cb cb)
{	
	if(node == NULL) {
		return;
	}
	binary_search_tree_traverse_in_order(node->left, cb);
	cb(node->data);
	binary_search_tree_traverse_in_order(node->right, cb);
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
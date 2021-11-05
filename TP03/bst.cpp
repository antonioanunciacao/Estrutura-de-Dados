// C program to demonstrate insert operation in binary search tree 
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct node { 
    char key[64];
	unsigned int frequencia;
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(std::string item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
	strcpy(temp->key, item);
	temp->frequencia = 1; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) { 
    if (root != NULL) {
		inorder(root->left); 
        printf("%s \n", root->key); 
        inorder(root->right); 
    } 
} 
   
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, std::string key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
	if(strcmp(key, node->key) < 0) node->left  = insert(node->left, key); 
    if(strcmp(key, node->key) > 0) node->right = insert(node->right, key);
	else if(strcmp(key, node->key) == 0) node->frequencia += 1;
  
    /* return the (unchanged) node pointer */
    return node; 
} 
   
// Driver Program to test above functions 
int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct node *root = NULL; 
    root = insert(root, "Antonio"); 
    insert(root, "carlos"); 
    insert(root, "da"); 
    insert(root, "Anunciacao"); 
   
    // print inoder traversal of the BST 
    inorder(root); 
   
    return 0; 
} 
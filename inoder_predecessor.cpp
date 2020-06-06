#include<bits/stdc++.h>
using namespace std;

int previous_value = -1;

struct node {
   int Val;
   struct node *Left;
   struct node *Right;
};

// This function is just for creating a new node with Val as value and both the children as NULL
struct node *createNode(int value) {
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->Val = value;
   temp->Left = temp->Right = NULL;
   return temp;
}

void Inorder(struct node *root) {
   if (root == NULL)
	return;    
   Inorder(root->Left);
   cout << root->Val << " ";
   Inorder(root->Right);
}

void swap(struct node *root){
   int temp = root->Val;
   root->Val = previous_value;
   previous_value = temp;
}

void inorder_predecessor(struct node *root) {
   if (root == NULL)
	return;    

   inorder_predecessor(root->Left);
   // We don't need to give previous_value as 1 of our input as it is global variable
   swap(root);
   inorder_predecessor(root->Right);
} 

int main() {
   struct node *root = createNode(2);
   root->Left = createNode(3);
   root->Right = createNode(7);
   root->Left->Left = createNode(1);
   root->Left->Right = createNode(6);
   cout << "Inorder traversal of the given Binary Tree is: ";
   Inorder(root);
   cout << endl;
   inorder_predecessor(root);
   cout << "Inorder traversal of the changed Binary Tree is: ";
   Inorder(root);
   
}

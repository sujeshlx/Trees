#include<bits/stdc++.h>
using namespace std;

// global variable for counting nodes visited until now
int counter = 0;
int N = 3;

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

void modified_Inorder(struct node *root) {
   if (root == NULL)
	return;    
   modified_Inorder(root->Left);

   counter++;
   if(counter == N)
	cout << "N'th node in inorder traversal is: " << root->Val << endl;

   modified_Inorder(root->Right);
} 
Nthnodenorder
int main() {
   struct node *root = createNode(2);
   root->Left = createNode(3);
   root->Right = createNode(7);
   root->Left->Left = createNode(1);
   root->Left->Right = createNode(6);
   modified_Inorder(root);
}

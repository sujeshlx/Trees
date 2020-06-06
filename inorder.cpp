#include<bits/stdc++.h>
using namespace std;
struct node{

   int val;
   struct node *Left;
   struct node *Right;
};

struct node *CreateNode(int val)
{

  struct node *temp = (struct node *) malloc (sizeof(struct node));
  temp -> val = val;
  temp ->Left = NULL;
  temp ->Right = NULL;

  return temp;
}

void inorder(struct node *root)
{
   if(root == NULL)
     return;

  inorder(root->Left);
  cout<<root->val;
  inorder(root->Right);

}
int main()
{
  struct node *root = CreateNode(1);

  root->Left = CreateNode(2);
  root->Right = CreateNode(3);
  root -> Left -> Left = CreateNode(4);
  root -> Right -> Right = CreateNode(5);

 inorder(root);

}

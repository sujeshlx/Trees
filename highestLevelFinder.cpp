#include<bits/stdc++.h>
using namespace std;

int highest_uptil_now = -1;

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

void highest_level_finder(struct node *root, int parent_level) {
   if(root == NULL)
      return;
   
   int present_node_level = 1 + parent_level;
   if(highest_uptil_now < present_node_level)
      highest_uptil_now = present_node_level;

   highest_level_finder(root->Left, present_node_level);
   highest_level_finder(root->Right, present_node_level);

}

int main() {
   struct node *root = createNode(1);
   root->Left = createNode(2);
   root->Right = createNode(3);
   root->Left->Left = createNode(4);
   root->Left->Right = createNode(5);
   highest_level_finder(root, highest_uptil_now);
   cout << "Highest level of a node in the given Binary Tree is: " << highest_uptil_now << endl;
}

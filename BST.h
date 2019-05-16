#include <iostream>
#include <string>

using namespace std;


typedef struct node {
int num;
string str;
struct node *left_child, *right_child;
} tree_node;

class BST{
  public: 
    tree_node* root;
    BST(){
      root=NULL;
    };
   
    tree_node* search(tree_node *tree,int key);
    tree_node* search(int key);
    tree_node* Add(tree_node *tree,int key, string value);
    void Add(int key, string value){
      root=Add(root,key,value);
    }
    void Delete(int key){
      root = Delete(root,key);
    }
    tree_node* Delete(tree_node* tree,int key);
    void Print(){
      Print(root);
    }
    tree_node* findMin(tree_node* tree);
    void Print(tree_node* tree);
};

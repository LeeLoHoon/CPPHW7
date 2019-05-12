#include "BST.h" 
#include <iostream>
#include <string>

using namespace std;

tree_node* BST::search(tree_node *tree,int key){
  if(tree==NULL){
    cout<<"xxx"<<endl;
    return NULL;  
  }
  while(tree!=NULL){
    if(tree->num ==key) return NULL;
    else if (key<tree->num)
      if(tree->left_child == NULL) return tree;
      else tree=tree->left_child;
    else                       
      if (tree->right_child == NULL) return tree; 
      else tree = tree->right_child;
  }
  return NULL;
}
tree_node *BST::search(int key){
  return search(root, key);
}



tree_node* BST::Add(tree_node* tree, int key, string value){
  tree_node *parent = NULL;
  parent = search(key);
  cout<<key<<endl;
  cout<<value<<endl;
  if(tree==NULL){
    tree->num=key;
    tree->str=value;
    cout<<tree->num<<endl;
  }  
  else if(parent==NULL){
    cout<<"already exit"<<endl;
  }
  else{
    if(parent->num<key){
      parent->left_child->num=key;
      parent->left_child->str=value;}
    else if(parent->num>key){
      parent->right_child->num=key;
      parent->right_child->str=value;}
  }
}
void BST::Delete(int key){
  cout<<"hu"<<endl;

}
void BST::Print(){
  cout<<"hu"<<endl;
}

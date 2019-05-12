#include "BST.h" 
#include <iostream>
#include <string>

using namespace std;

tree_node* BST::search(int key){
  tree_node* tree=NULL;
  tree=getRoot();
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
tree_node* BST::getRoot(){
  return root;
}
void BST::setRoot(int key, string value){
  cout<<"bbb"<<endl;
  root->num=key;  //여기가 문젠데..
  cout<<key<<endl;
  root->str=value;
  root->left_child=NULL;
  root->right_child=NULL;
}
void BST::Add(int key, string value){
  tree_node *parent = NULL;
  tree_node *root=getRoot();
  parent = search(key);
  cout<<key<<endl;
  cout<<value<<endl;
  if(root==NULL){
    setRoot(key,value);
    cout<<"zzz"<<endl;
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

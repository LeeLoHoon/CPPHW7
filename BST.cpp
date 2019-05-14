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
  if(tree==NULL){
    tree = new tree_node;
    tree->num = key;
    tree->str = value;
    tree->left_child=NULL;
    tree->right_child=NULL;
  }  
  else if(key==tree->num){
    cout<<"already exit"<<endl;
  }
  else{
    if(key>tree->num){
      tree->right_child = Add(tree->right_child,key,value);}
    else if(key<tree->num){
      tree->left_child=Add(tree->left_child,key,value);
    }
}
  return tree;
}
//가장 쉬운 것 : leaf 지우기 --> child하나인 node지우기 --> child 두개인 node 지우기

tree_node* BST::Delete(tree_node* tree,int key){
  tree_node* temp;
  if(tree->num==key){
    if((tree->left_child==NULL)&&(tree->right_child=NULL)){
      tree=NULL;
      return tree;}
    else if(tree->left_child==NULL&&!(tree->right_child)){
      temp=tree;
      tree=tree->right_child;
      if(!tree->num){
        cout<<"hhh"<<endl;
      }
      delete temp;
      return tree;
    }
    else if(tree->right_child==NULL&&!(tree->left_child)){
      temp=tree;
      tree=tree->left_child;
      delete temp;
      return tree;
    }
    //둘다 NULL이 아니면서 root인 경우 오른쪽에서 제일 작은 값 찾아서 지워야 하는 곳에 넣고 지운 후 연결
    else{
      int a;
      string b;
      temp=findMin(tree->right_child);
      a=temp->num;
      b=temp->str;
      Delete(a);
      tree->num=a;
      tree->str=b;
      return tree;
    }
  }
  else if(key>tree->num){
    if(tree->right_child==NULL){
      cout<<"no"<<endl;
      return tree;}
      //문제점: reculsive funtion에 들어가는 파라미터가 노드 하나만 들어감(그 하위 노드들도 다 들어가져야함......)
    tree->right_child=Delete(tree->right_child,key);
    //cout<<tree->right_child->num<<endl;
  }
  else if(key<tree->num){
    if(tree->left_child==NULL){
      cout<<"no"<<endl;
      return tree;}
  
    tree->left_child=Delete(tree->left_child,key);
    
  }

  return tree;

}
tree_node* BST::findMin(tree_node* tree){
  tree_node* temp=NULL;
  if(tree->left_child==NULL){
    temp=tree;
    return temp;}
  else {
    tree=tree->left_child;
    findMin(tree);
    return tree;
  }
}
void BST::Print(tree_node* tree){
  if(tree == NULL)
    return;
  Print(tree->left_child);
  cout << tree->num <<endl;
  cout << tree->str <<endl;
  Print(tree->right_child);
}

#include <iostream>
#include <string>

using namespace std;

//왼쪽 가지는 
typedef struct node {
int num;
string str;
struct node *left_child, *right_child;
} tree_node;

class BTS{
  private:
    tree_node* root;
  public: 
    BTS(){
    };
    //1. modified Search 함수 콜 ==> key의 parent될 노드 찾아서 return 하기
    //알고리즘: tree= root 되게 한 후 tree의 왼쪽 또는 오른쪽이  NULL이 될 때까지 움직이면서 NULL이 되면 tree return
    //return 받는 tree를 parent로 받고 Add함수에서 parent보다 작으면 왼쪽, 크면 오른쪽에 insert
    //2. Add함수 콜 ==> 1)root가 NULL인 상태이면 들어오는 key와 value를 root의 num과 str에 넣음 2)root가 NULL상태가 아니면 위에 알고리즘 사용
    //3. Delete 경우의 수 3가지 reaf,reaf아니지만 자손 하나,reaf 아니고 자손 둘
    tree_node* search(int key);
    void Add(int key, string value);
    void Delete(int key);
    void print();
}

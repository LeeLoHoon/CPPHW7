#include "BST.h" 
#include <iostream>
#include <fstream>
#include <string>

//command [key[value]] 순으로 받는데 if 문써서 하나씩 입력받음 받은게 a라면 key와 value를 순서대로 받고 d를 받으면 key만 받음 p를 받으면 더 받지 않고 모두 프린트하기 q를 받으면 프로그램 종료 ==>get함수에 넣기
//BST에 구현되어야 할 함수 : search 함수, add 함수, delete함수, print함수, get함수
using namespace std;

int main() {
  //BST myBST;
  ifstream fp;
  string fileName,value;
  char command;
  int key;
  try{
    cin >> fileName;
    fp.open(fileName);
  }catch(const ifstream::failure& e){
   	cerr << "Exception occurred while opening the file." << endl;}
  while(!fp.eof()){
    fp>>command;
    if(command=="a"){
      fp>>key;
      fp>>value;
      BTS.Add(key,value);
    }
    else if(command=="d"){
      fp>>key;
      BTS.Delete(key);
    }
    else if(command=="p"){
      BTS.Print();
    }
    else if(command=="q") break;
  }
  
}

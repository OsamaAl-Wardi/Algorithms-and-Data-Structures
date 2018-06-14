/* This is  a code by Osama Al_Wardi */
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
struct Node{
     int key;
     int value;
};
class HashTable{
 private:
   Node arr[101];
   int maxSize;
   int currentSize;
 public:
   HashTable(){
     maxSize = 101;
     currentSize = 0;
      Node empty = {0, 0};
     for (int i = 0; i < 101; i++) {
       arr[i] = empty;//initialzing to 0
     }
   };
   int hashCode(int key){
     std::cout << "hash function "<< key<<" % "<<maxSize<<" = "<<(key % maxSize)<< '\n';
     return (key % maxSize);
   };
   void insertNode(int key, int value){
     int x = hashCode(key);
     bool empty = isEmpty(x);
     while (empty != 1) {
       x++;
       empty = isEmpty(x);
     }
     Node node = {key, value};
     arr[x] = node;//insert
     std::cout << "inserted at position "<< x << '\n';
   };
   int get(int key){
      int x = hashCode(key);
      if (this->arr[x].key == key){
        std::cout << x << '\n';
        return x;
      }
      else {
        while (this->arr[x].key != key){
          x++;
        }
        std::cout << x << '\n';
        return x;
   };
}
   bool isEmpty(int index);
};

bool HashTable::isEmpty(int index){
  if (this->arr[index].key == 0){
    return 1;
  }
  else{
    return 0;
  }
};

int main() {
  HashTable hash;
  //Testing
  hash.insertNode(50, 8);
  hash.insertNode(50, 9);
  hash.get(50);
  return 0;
}

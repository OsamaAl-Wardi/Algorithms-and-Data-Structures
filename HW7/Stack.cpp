/*
This is a non-generic stack implemented in C++ by Osama Al-Wardi. I did'nt follow the general guide lines given in class but it works. 
*/

#include <cstdlib>
#include<iostream>
using namespace std;

class node
{
 public:
    int data;
    node* next;
};

class Stack
{
public:
Stack(int max)
{
    top = NULL;
    maxnum = max;
    count=0;
}

void push(int element)
{
    if(count == maxnum)
            cout<<"stack is full"<<endl;
    else
    {
        node *newTop = new node;
        if(top == NULL)
        {       
            newTop->data = element;
            newTop->next = NULL;
            top = newTop;
            count++;
        }
        else
        {
            newTop->data = element;
            newTop->next = top;
            top = newTop;
            count++;
        }
    }
}

int pop()
{
    if(top == NULL){
        cout<< "nothing to pop"<<endl;
        return 0;
    }
            
    else
    {
        node * old = top;
        top = top->next;
        count--;
        return old->data;
        delete(old);
    }
}
void print()
{
    node *temp;
    temp = top;
    while(temp!=NULL)
    {
        cout<<temp->data<<",";
        temp=temp->next;
    }
}
private:
    node *top;
    int count;
    int maxnum;
    int stackData;      
};

int main(int argc, char** argv) {   
    Stack *sl = new Stack(5);
    sl->push(1);
    sl->push(2);
    sl->push(3);
    sl->push(4);
    sl->push(5);
    sl->push(6);

    sl->pop();
    cout<<"new stack\n";
    sl->print();

    return 0;
}
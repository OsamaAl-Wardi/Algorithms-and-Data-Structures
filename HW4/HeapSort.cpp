/*
This is an implementation of HeapSort made by Osama Al-Wardi.
*/
#include <iostream>
#include <vector>


using namespace std;

int Parent (int i){
    return i/2;
}

int Right (int i){
    return 2*i+1;
}

int Left (int i){
    return 2*i;
}

void MaxHeapify (vector <int> &A, int i){
    int l = Left(i);
    int r = Right(i);
    int Largest;
    if ((l<=A[0]) && (A[l]>A[i])){
        Largest = l;
    }
    else Largest = i;
    if ((r<=A[0]) && (A[r]>A[Largest])){
        Largest = r;
    }
    if (Largest != i){
        swap(A[i],A[Largest]);
        MaxHeapify(A,Largest);
    }
}

void BuildMaxHeap (vector <int> &A){
    A[0] = A.size()-1;
    for (int i = A[0]/2; i >= 1; i--){
        MaxHeapify(A, i);
    }
}

void HeapSort (vector <int> &A){
    BuildMaxHeap(A);
    for (int i = A.size()-1; i >= 2; i--){
        swap(A[1],A[i]);
        A[0]--;
        MaxHeapify(A, 1);
    //cout<<"Heapsize="<<HeapSize<<endl;
    }
}

int main (){
    int HeapLength=10;
    cout<<"elements= ";
    cin>>HeapLength;
 
    vector <int> A(HeapLength+1);
//     A = {-1,6,9,2,3,5,1,7,8,1,0};
    A[0]=HeapLength;
    for (unsigned int i=1; i<A.size();i++)
    cin>>A[i];
    
    
    HeapSort(A);
    

    for (unsigned int i = 1; i <A.size(); i++){
        cout<<A[i]<< " ";
    }
}
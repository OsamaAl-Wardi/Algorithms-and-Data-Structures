#include <iostream>
#include <algorithm>
#include <vector> 
#include <ctime>

using namespace std;

vector <int> Partition (vector <int> &A, int p, int q);

vector <int> Ramdomized_Partition (vector <int> &A, int p, int r){
    srand((unsigned)time(0));
    int x;
    x = (rand()%(r-p))+p;
    swap(A[p], A[x]);
    x = (rand()%(r-p))+p;
    swap(A[p+1], A[x]);
    return Partition (A, p, r);
}

vector <int> Partition (vector <int> &A, int p, int q)
{
    //if (A[p] > A[p + 1]) swap (A[p], A[p + 1]);
    int x1 = A[p];
    int x2 = A[p + 1];
    int i1 = p;
    int i2 = p + 1;

    for(int j = p + 1; j <= q; j++){
        if (A[j] < x1){
            i1++;
            swap(A[i1], A[j]);
        }
    }

    swap(A[p], A[i1]);

    for (int j = p + 1; j <= q; j++){
        if (A[j] < x2){
            i2++;
            swap(A[i2], A[j]);
        }
    }
    
    swap(A[p + 1], A[i2]);
    
    vector <int> arr (2);
    arr [0] = i1;
    arr [1] = i2;
    //cout<<A[p]<<","<<i1<<" "<<A[p + 1]<<","<<i2<<endl;
    return arr;
}

void QuickSort(vector <int> &A, int p, int r)
{
    if (p < r)
    {
        vector <int> piv (2);
        piv = Ramdomized_Partition (A, p, r);
        QuickSort(A, p, piv[0] - 1);
        QuickSort(A, piv[0] + 1, piv[1] - 1);
        QuickSort(A, piv[1] + 1, r);
    }
}
int main (){
    vector <int> A (7);
    A = {5,4,3,2,1,0,-1};
    QuickSort(A, 0, 6);
    for (int i = 0; i < 7; i++)
        cout<<A[i]<<" ";
    return 0;
}
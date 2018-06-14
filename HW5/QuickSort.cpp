#include <iostream>
#include <vector>  

using namespace std;

int Partition (vector <int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);  
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void QuickSort(vector <int> &A, int p, int r)
{
    if (p < r)
    {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}
int main (){
    vector <int> A (7);
    A = {3,2,6,1,7,9,5};
    QuickSort(A, 0, 6);
    for (int i = 0; i < 7; i++)
        cout<<A[i]<<" ";
    return 0;
}
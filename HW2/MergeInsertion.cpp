/*
this code is made by Osama Al-Wardi.
It implements a varian of merge sort and insertion sort.
It prints the x,y coordinates of the time complexities for best,
worst and average cases.
*/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void insertionSort(int arr[], int l ,int r)
{
   int i, key, j;
   int n= r-l+1;
   for (i = l+1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= l && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void mergeSort(int arr[], int l, int r, int k)
{
    if ((l-r+1)<=k){
       insertionSort(arr, l, r);
    }
    else
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m, k);
        mergeSort(arr, m+1, r, k);
        merge(arr, l, m, r);
    }
}

int main(){
    int n = 10000;
    int arr[n];
    int j=0;
    for(int i=10000; i > 0; i--){  
        arr[j] = i;
        j++;
    }
    j=0;
    cout<<"worst case :"<<endl;
    for (int k = 1; k < 10000; k+=500){//printing reslts for worst case
        auto t1 = chrono::high_resolution_clock::now();
        mergeSort(arr, 0, n-1, k);
        auto t2 = chrono::high_resolution_clock::now();
        printf("%d,%d\n",k, t2 - t1);
        for(int i=10000; i > 0; i--){ 
            arr[j] = i;
            j++;
        }
        j=0;
    }
    cout<<"best case: "<<endl;

    for (int i=0; i<10000; i++){
        arr[i]=i;
    }
    for (int k = 1; k<10000; k+=500){//printing results for best case
       auto t1 = chrono::high_resolution_clock::now();
       mergeSort(arr, 0, n-1, k);
       auto t2 = chrono::high_resolution_clock::now();
       printf("%d,%d\n",k, t2 - t1);
    }
    cout<<"average case: "<<endl;
    srand((unsigned)time(0));//calling the the random function from the <ctime> library
    int input_sequence; 
    for(int i=0; i<10000; i++){ 
        input_sequence = (rand()%10000)+1; 
        arr[i] = input_sequence; 
    }
    for(int k = 1; k < 10000; k+=500){//printing results for average case
       auto t1 = chrono::high_resolution_clock::now();
       mergeSort(arr, 0, n-1, k);
       auto t2 = chrono::high_resolution_clock::now();
       printf("%d,%d\n",k, t2 - t1);
       int input_sequence; 
        for(int i=0; i<10000; i++){ 
            input_sequence = (rand()%10000)+1; 
            arr[i] = input_sequence; 
        }
    }
    return 0;
}
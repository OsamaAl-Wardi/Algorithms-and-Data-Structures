/*
this is a program made by Osama Al-Wardi.
This is an Implementation for selection sort which will be tested against
random, sorted and decending sorted input.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {
    int start_s=clock();
    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for (int i=0; i<n; i++){
        int min=arr[i];
        for (int j=i+1; j<n; j++){
            if (arr[j]<min){
                min=arr[j];
                arr[j]=arr[i];
                arr[i]=min;
            }
        }
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}

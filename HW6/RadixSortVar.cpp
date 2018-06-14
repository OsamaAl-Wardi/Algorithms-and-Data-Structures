/*
this is an implementation of Radix Sort on a String. Made by Osama Al-Wardi
*/
#include <iostream>
#include <vector>

using namespace std;

void CountingSort (vector<string> &A, unsigned int n, unsigned int k, unsigned int l){
    //cout<<"inside function"<<endl;
    vector<string> B(n+1);
    unsigned int C[26];
    for (unsigned int i = 0; i < 26; i++)
        C[i] = 0;

    for (unsigned int j = 0; j < n; j++){
        string s = A[j];
        int x = s[l] - 97;
        C[x]++;
    }
 
    for (unsigned int i = 1; i < 26; i++)
        C[i]+=C[i-1];


    //for (int i=0; i < 26; i++)
        //cout<<C[i]<<" ";
        
    //cout<<endl;
   
    for (unsigned int j = n-1; j >= 0;j--){
        cout<<"inside the for loop"<<endl;
        string s = A[j];
        cout<<s<< endl;
        int x = s[l] - 97;
        //cout<<j<<" "<<s<<" "<<s[l]<<" "<<x<<" "<<C[x]<<endl;  
        unsigned int cx = C[x];    
        B[cx-1] = s;
        cout<<"after B[C[x]]"<<endl;
        C[x]-=1;
    }

   // for (unsigned int i = 0; i< n; i++){
      //  A[i]=B[i];
      //  cout<<A[i]<<" ";
    //}
   // cout<<endl;
}


int main (){
    
    unsigned int n;
    unsigned int k;
    cin>>n;
    vector <string> arr(n);
    //cout<<n<<endl;
    cin>>k;
    //cout<<k<<endl;
    string a;
    for (unsigned int i = 0; i < n; i++){
        cin>>a;
        arr[i] = a;
    }

    for (unsigned int l = 0; l < k; l++){
        //cout<<"Iteration number "<<l<<endl;
        CountingSort(arr, n, k, l);
    }
    for (unsigned int i = 0; i < n; i++)
        cout<<arr[i]<<endl;
}
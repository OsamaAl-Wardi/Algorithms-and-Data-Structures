/*
This is a Source Code for Algorithms and Data Structres made By: Osama Al-Wardi.
It contains 4 implementations of Fibooncacci Sequence the Recusive approach, Iteravtive approach, Closed form and Matrix represesntation. 
*/

#include <iostream>
#include <math.h>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;


vector < vector <unsigned long long int> > PowerMatrix (int n){
    vector < vector <unsigned long long int> > a_1(2,vector<unsigned long long int>(2));
    a_1 = {{1,1},{1,0}}; 
    if (n==1) return a_1;
    else {
        vector < vector <unsigned long long int> > a(2,vector<unsigned long long int>(2));
        a = PowerMatrix(n/2);
        vector < vector <unsigned long long int> > r(2,vector<unsigned long long int>(2));
        r[0][0]=a[0][0] * a[0][0] + a[0][1] * a[1][0];
        r[0][1]=a[0][0] * a[0][1] + a[0][1] * a[1][1];
        r[1][0]=a[1][0] * a[0][0] + a[1][1] * a[1][0];
        r[1][1]=a[1][0] * a[0][1] + a[1][1] * a[1][1];
        if (n%2 == 0) return r;
        else{
            a[0][0]=r[0][0] * a_1[0][0] + r[0][1] * a_1[1][0];
            a[0][1]=r[0][0] * a_1[0][1] + r[0][1] * a_1[1][1];
            a[1][0]=r[1][0] * a_1[0][0] + r[1][1] * a_1[1][0];
            a[1][1]=r[1][0] * a_1[0][1] + r[1][1] * a_1[1][1];
            return a;
        }
    }
}


unsigned long long int FibR (int n){
    if (n<=1){
        return n;
    }
    else {
        return FibR(n-1)+FibR(n-2);
    }
}

unsigned long long int FibI (int n){
    if (n<=1){
        return n;
    }
    else {
        unsigned long long int n1=1;
        unsigned long long int n2=0;
        unsigned long long int Fib = 0;
        for (int i = 2; i <= n; i++){
            Fib = n1 + n2;
            n2 = n1;
            n1 = Fib;
        }
        return Fib;
    }
}

unsigned long long int FibC (int n){
    long double sq5 = 2.2360679775;
    return (unsigned long long int)(pow((1.0+sq5)/2.0, (long double)n)/sq5 + 0.5);
}

unsigned long long int FibM (int n){
    vector < vector <unsigned long long int> > Fib(2,vector<unsigned long long int>(2));
    Fib = PowerMatrix(n);
    return Fib[1][0];
}


int main(){
    cout<<"   Recursive "<<endl;


    for (int n = 1; n < 63; n++){
        int increase = 0;
        if (n>=6) increase++;
        n+=increase;
        auto start = chrono::system_clock::now();
        cout<<n<<", ";
        FibR(n);
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        time_t end_time = chrono::system_clock::to_time_t(end);
        cout << "" << elapsed_seconds.count() << "\n";
        if (elapsed_seconds.count()>5.0) break;
    }


        cout<<"   Iterative "<<endl;


        for (int n = 1; n < 70; n++){
            int increase = 0;
            if (n>=6) increase++;
            n+=increase;
            auto start = chrono::system_clock::now();
            cout<<n<<", ";
            FibI(n);
            auto end = chrono::system_clock::now();
            chrono::duration<double> elapsed_seconds = end-start;
            time_t end_time = chrono::system_clock::to_time_t(end);
            cout << elapsed_seconds.count() << "\n";
            if (elapsed_seconds.count()>5.0) break;
    }

        cout<<"   Closed Form "<<endl;


        for (int n = 1; n < 200; n++){
            int increase = 0;
            if (n>=6) increase++;
            n+=increase;
            auto start = chrono::system_clock::now();
            cout<<n<<", ";
            FibC(n);
            auto end = chrono::system_clock::now();
            chrono::duration<double> elapsed_seconds = end-start;
            time_t end_time = chrono::system_clock::to_time_t(end);
            cout << elapsed_seconds.count() << "\n";
            if (elapsed_seconds.count()>5.0) break;
    }


        cout<<"   Matrix Representation "<<endl;


        for (int n = 1; n < 200; n++){
            int increase = 0;
            if (n>=6) increase++;
            n+=increase;
            auto start = chrono::system_clock::now();
            cout<<n<<", ";
            FibM(n);
            auto end = chrono::system_clock::now();
            chrono::duration<double> elapsed_seconds = end-start;
            time_t end_time = chrono::system_clock::to_time_t(end);
            cout<< elapsed_seconds.count() << "\n";
            if (elapsed_seconds.count()>5.0) break;
    }
    
    return 0;
}
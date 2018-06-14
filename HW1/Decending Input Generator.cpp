/*
this is a program made by Osama Al-Wardi.
It is a decending number generator to test the worst case for sorting algorithms.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin>>n;
  for (int i=n; i>=1; i--){
      cout<<i<<" ,";
  }
}

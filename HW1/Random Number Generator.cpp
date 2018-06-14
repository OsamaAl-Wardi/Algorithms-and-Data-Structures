/*
this is a program made by Osama Al-Wardi.
It is a random number generator to test the average case for sorting algorithms.
*/
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main()
{
    srand((unsigned)time(0));//calling the the random function from the <ctime> library
    int input_sequence;
    int n;//lenght of the sequence
    cin>>n;//length of the sequnces from stdin
    for(int index=0; index<n; index++){
        input_sequence = (rand()%10)+1;
        cout << input_sequence <<" ,";
    }
    return 0;
}

/*
This is the soultion to the Longest Ordered Subsequnce Problem
Programmed by: Osama Al-Wardi
*/
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& arr)
{
	for (int x : arr)//printing the array
		cout << x << " ";
	cout << endl;
}

void LOS(vector <int> arr, int n)
{
	vector<vector<int> > L(n);//vector of vectors
	L[0].push_back(arr[0]);

    //Computing the LOS values in bottom up manner using Tabulation
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((arr[i] > arr[j]) && (L[i].size() < L[j].size() + 1))
				L[i] = L[j];
		}
		L[i].push_back(arr[i]);
	}

	vector<int> max = L[0];
	for (vector<int> x : L)
		if (x.size() > max.size())
			max = x;

	print(max);
}

int main()
{
	vector <int> arr;
    while(1){//reading if the number is negative then Break
        int x;
        cin>>x;
        if(x==-1) break;
        arr.push_back(x);
    }
	int n = arr.size();
	LOS(arr, n);
	return 0;
}

/*
This is the soultion to the Sum in Triangles Problem
Programmed by: Osama Al-Wardi
*/
#include<bits/stdc++.h>
using namespace std;
#define N 3

int maxPathSum(int tri[N][N], int m, int n)
{
	int TRI [N][N];//used for finding the path
    
    for (int i = 0; i < N; i++){//initalization
        for (int j =0; j < N; j++){
            TRI[i][j]=tri[i][j];
        }
    }

	for (int i=m-1; i>=0; i--){
		for (int j=0; j<=i; j++){
			if (TRI[i+1][j] > TRI[i+1][j+1])//finding the path either from top left or top right
				TRI[i][j] += TRI[i+1][j];
			else
				TRI[i][j] += TRI[i+1][j+1];
		}
	}

    int j = 0;
    for (int i = 0; i < N; i++){//tri is only used for printing
        cout<<tri[i][j]<<" ";

		if (TRI[i+1][j] <  TRI[i+1][j+1])
            j++;
    }

    cout<<endl;

	return TRI[0][0];
}

int main()
{
int tri[N][N];
for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
        cin>>tri[i][j];
    }
}
cout << maxPathSum(tri, N-1, N-1);
return 0;
}

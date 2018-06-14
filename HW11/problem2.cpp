/*
This is code is an impleemntation of the Floyd-Warshall Algorithm. Source: Github
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = (1 << 30);//int representing infinity


int find_meetup_city(const std::vector< std::vector<int> >& adj, const int& p, const int& q){
    
    int n = adj.size();
    int dp[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) dp[i][j] = 0;
            else if(adj[i][j] != -1) dp[i][j] = adj[i][j];
            else dp[i][j] = INF;
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int res = INF;
    int city;
    for(int i = 0; i < n; i++){
        if(res > std::max(dp[p][i], dp[q][i])){
            res = std::max(dp[p][i], dp[q][i]);
            city = i;
        }
    }
    return city;
}

int main(){

    int n, m;
    cin >> n >> m;
    vector< vector<int> > adj(n, vector<int>(n, -1));
    while(m--){
        int from, to, val;
        cin >> from >> to >> val;
        adj[from][to] = val;
        adj[to][from] = val;
    }
    int p, q;
    cin >> p >> q;
    cout << find_meetup_city(adj, p, q) << endl;

    return 0;
}
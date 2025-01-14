#include<vector>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define WHITE 1
#define GRAY 2
#define BLACK 3
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &explore){
    explore[node] = GRAY;
    bool  findCycle = false;
    for(int to : adj[node]){
        if(explore[to] == WHITE){
            findCycle = dfs(to, adj, explore);
            if(findCycle) break;
        }
        else if(explore[to] == GRAY) {
            findCycle = true;
            break;
        }
    }
    explore[node] = BLACK;
    return findCycle;
}

int main(void){
    int  node, edge,  t1,t2;
    cin >> node >> edge;
    vector<vector<int>> adj(node+1);
    vector<int> explore(node+1,  WHITE);
    for(int i=0;i<edge;i++){
        cin >> t1  >> t2;
        adj[t1].push_back(t2);
    }
    cout << "hello \n";

    bool findCycle = false;
    for(int i=1;i<node;i++){
        if(explore[i] == WHITE) {
            findCycle = dfs(i, adj, explore);
        }
        if(findCycle)break;
    }
    if(findCycle) cout << "Found Cycle\n";
    else cout <<  "Found No Cycle\n";
}

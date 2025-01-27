#include<vector>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define WHITE 1
#define GRAY 2
#define BLACK 3
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &explore, vector<int> &cycle){
    explore[node] = GRAY;
    cycle.push_back(node);
    bool  findCycle = false;
    for(int to : adj[node]){
        if(explore[to] == WHITE){
            findCycle = dfs(to, adj, explore, cycle);
            if(findCycle) break;
        }
        else if(explore[to] == GRAY) {
            findCycle = true;
            cycle.push_back(to);
            break;
        }
    }
    explore[node] = BLACK;
    if(!findCycle)  cycle.pop_back();
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

    bool findCycle = false;
    vector<int> cycle;
    for(int i=1;i<node;i++){
        if(explore[i] == WHITE) {
            findCycle = dfs(i, adj, explore, cycle);
        }
        if(findCycle)break;
    }
    if(findCycle){
        cout << "Found Cycle\n";
        for(int x: cycle) cout << x << "   ";
        cout << endl;
        bool findStart = false;
        int idx = 0;
        while(idx<cycle.size()){
            if(cycle[idx] == cycle[cycle.size()-1]) break;
            idx++;
        }
        idx++;
        sort(cycle.begin()+idx, cycle.end());
        for(;idx<cycle.size();idx++) cout << cycle[idx] << "  ";
    }
    else cout <<  "Found No Cycle\n";
}

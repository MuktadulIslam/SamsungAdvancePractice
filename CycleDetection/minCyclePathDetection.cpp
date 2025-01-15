#include<vector>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define WHITE 1
#define GRAY 2
#define BLACK 3
using namespace std;

vector<int> minCycle;

void setMinCycle(vector<int> &cycle){
    int idx = 0;
    while(idx<cycle.size()){
        if(cycle[idx] == cycle[cycle.size()-1]) break;
        idx++;
    }
    for(int x: cycle) cout << x << "  ";
    cout << endl;
    cout << "hi  " << minCycle.size() << "   " << cycle.size()-idx-1 << "  " << idx << endl;
    if(minCycle.size()==0 || minCycle.size() > cycle.size()-idx-1){
        minCycle.clear();
        minCycle.assign(cycle.begin()+idx,  cycle.end()-1);
    }
    for(int x: minCycle) cout << x << "  ";
    cout << endl;
}

void dfs(int node, vector<vector<int>> &adj, vector<int> &explore, vector<int> &cycle){
    explore[node] = GRAY;
    cycle.push_back(node);

    for(int to : adj[node]){
        if(explore[to] == WHITE){
            dfs(to, adj, explore, cycle);
        }
        else if(explore[to] == GRAY) {
            // FindCycle
            cout << "hi\n";
            cycle.push_back(to);
            setMinCycle(cycle);
            cycle.pop_back();
        }
    }
    //explore[node] = BLACK;
    cycle.pop_back();
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

    vector<int> cycle;
    for(int i=1;i<node;i++){
        if(explore[i] == WHITE) {
            dfs(i, adj, explore, cycle);
        }
    }
    if(minCycle.size() != 0){
        cout << "Found Cycle\n";
        for(int x: cycle) cout << x << "   ";
        cout << endl;
        for(int x: minCycle) cout << x << "   ";
    }
    else cout <<  "Found No Cycle\n";
}


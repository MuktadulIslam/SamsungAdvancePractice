//Using Dijkastra Algorithm
// time complexity O(n^2)
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct hole{int entryX, entryY, exitX, exitY, cost, temp=INT_MAX;};
int main(void){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<hole> adj(n*2+2);
        // adj[0] = source & adj[1] = destination
        cin>>adj[0].entryX >> adj[0].entryY >> adj[1].entryX >> adj[1].entryY;
        adj[0].exitX = adj[0].entryX;
        adj[0].exitY = adj[0].entryY;
        adj[0].cost = 0;
        adj[1].exitX = adj[1].entryX;
        adj[1].exitY = adj[1].entryY;
        adj[1].cost = 0;

        for(int i=2; i<n*2+2 ; i++) {
            cin >> adj[i].entryX >> adj[i].entryY >> adj[i].exitX >> adj[i].exitY >> adj[i].cost;
            i++;
            adj[i].exitX = adj[i-1].entryX;
            adj[i].exitY = adj[i-1].entryY;
            adj[i].entryX = adj[i-1].exitX;
            adj[i].entryY = adj[i-1].exitY;
            adj[i].cost = adj[i-1].cost;
        }

        //for(hole x: adj) cout << x.entryX << "  " << x.entryY << "  " << x.exitX << "  " << x.exitY << "  " << x.cost << endl;

        //Appliny Dijkastra
        adj[0].temp = 0;
        for(int i=0; i<adj.size(); i++){
            if(i==1) continue;
            for(int j=0; j<adj.size(); j++) {
                if(i == j) continue;
                adj[j].temp = min(adj[j].temp ,
                                adj[i].temp + min(abs(adj[i].exitX-adj[j].entryX)+abs(adj[i].exitY-adj[j].entryY)+adj[j].cost,
                                    abs(adj[i].exitX-adj[j].exitX)+abs(adj[i].exitY-adj[j].exitY)));
            }
        }
        cout << adj[1].temp << endl;
    }
}

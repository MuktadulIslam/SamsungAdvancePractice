#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n = 3;
     vector<vector<int>> memo(n, vector<int>(1 << n, -1));
     for(auto x: memo){
        for(auto y:x) cout << y << "   ";
        cout << endl;
     }
}

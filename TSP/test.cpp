#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>

using namespace std;

int main(void) {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> grid(row, vector<int>(col));
    vector<vector<int>> diffi(row, vector<int>(col, INT_MAX));

    for(int i=0;i<row;i++)for(int j=0; j<col; j++) cin>> grid[i][j];

    if(grid[row-1][0] != 1) {cout << 0; return 0;}

    queue<pair<int, int>> que;
    que.push({row-1, 0});
    diffi[row-1][0] = 0;

    while(!que.empty()){
        int ri = que.front().first, ci = que.front().second;
        que.pop();
        if(grid[ri][ci] == 3) continue;

        if(ci+1 < col && grid[ri][ci+1] != 0 && diffi[ri][ci+1] > diffi[ri][ci]){
            diffi[ri][ci+1] = diffi[ri][ci];
            que.push({ri,ci+1});
        }
        if(ci > 0&& grid[ri][ci-1] != 0 && diffi[ri][ci-1] > diffi[ri][ci]){
            diffi[ri][ci-1] = diffi[ri][ci];
            que.push({ri,ci-1});
        }
        int t1, t2;
        for(t1 = ri-1; t1>=0 && grid[t1][ci] == 0; t1--);
        if(t1>=0){
            t2 = max(abs(t1-ri), diffi[ri][ci]);
            if(diffi[t1][ci] > t2){
                diffi[t1][ci] = t2;
                que.push({t1, ci});
            }
        }
        for(t1 = ri+1; t1<row && grid[t1][ci] == 0; t1++);
        if(t1<row){
            t2 = max(abs(t1-ri), diffi[ri][ci]);
            if(diffi[t1][ci] > t2){
                diffi[t1][ci] = t2;
                que.push({t1, ci});
            }
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            /*if(grid[i][j] == 3){
                cout << diffi[i][j];
                return 0;
            }*/
            cout<< diffi[i][j] << "  ";
        }
        cout << endl;
    }

}

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
        int rowi = que.front().first, coli = que.front().second;
        que.pop();
        if(grid[rowi][coli] == 3) continue;

        if(coli>0 && grid[rowi][coli-1] != 0 && diffi[rowi][coli-1] > diffi[rowi][coli]){
            diffi[rowi][coli-1] = diffi[rowi][coli];
            que.push({rowi, coli-1});
            //cout << "rowi="<<rowi << "  cooli=" << coli << "  rowI=" << rowi << "  coli-1=" << coli-1 << endl;
        }
        if(coli+1<col && grid[rowi][coli+1] != 0 && diffi[rowi][coli+1] > diffi[rowi][coli]){
            diffi[rowi][coli+1] = diffi[rowi][coli];
            que.push({rowi, coli+1});
            //cout << "rowi="<<rowi << "  cooli=" << coli << "  rowI=" << rowi << "  coli+1=" << coli+1 << endl;
        }

        int temp1, temp2;
        for(temp1=rowi-1; temp1>=0 && grid[temp1][coli] == 0; temp1--);
        if(temp1>=0){
            temp2 = max(abs(rowi-temp1), diffi[rowi][coli]);
            if(diffi[temp1][coli] > temp2){
                diffi[temp1][coli] = temp2;
                que.push({temp1,  coli});
                //cout << "rowi="<<rowi << "  cooli=" << coli << "  temp1=" << temp1 << "  coli=" << coli << endl;
            }
        }
        for(temp1=rowi+1; temp1<row && grid[temp1][coli] == 0; temp1++);
        if(temp1<row){
            temp2 = max(abs(rowi-temp1), diffi[rowi][coli]);
            if(diffi[temp1][coli] > temp2){
                diffi[temp1][coli] = temp2;
                que.push({temp1,  coli});
                //cout << "rowi="<<rowi << "  cooli=" << coli << "  temp1=" << temp1 << "  coli=" << coli << endl;
            }
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j] == 3){
                cout << diffi[i][j];
                return 0;
            }
            //cout<< diffi[i][j] << "  ";
        }
        //cout << endl;
    }

}

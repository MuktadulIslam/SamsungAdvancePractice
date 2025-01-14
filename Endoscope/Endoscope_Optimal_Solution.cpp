// Time  complexity O(row*column) "You can print the 48th line"
// Simple BFS

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int row, column, startR, startC, length;
struct point{int rowi, coli, lenght;};

bool haveup(int type) {
    if (type == 1 || type == 2 || type == 4 || type == 7) return true;
    else return false;
}
bool havedown(int type) {
    if (type == 1 || type == 2 || type == 5 || type == 6) return true;
    else return false;
}
bool haveleft(int type) {
    if (type == 1 || type == 3 || type == 6 || type == 7) return true;
    else return false;
}
bool haveright(int type) {
    if (type == 1 || type == 3 || type == 4 || type == 5) return true;
    else return false;
}


int main(void) {
    int t; cin >> t;
    while (t--)
    {
        cin >> row >> column >> startR >> startC >> length;
        vector<vector<int>> grid(row, vector<int>(column));
        vector<vector<bool>> visited(row, vector<bool>(column, false));

        for (int i = 0; i < row; i++) for (int j = 0; j < column; j++) cin >> grid[i][j];

        if(length == 0){cout << 0 << endl; continue;}

        queue<point> que;
        que.push({startR, startC, 1});
        while(!que.empty()){
            int rowi = que.front().rowi, coli = que.front().coli, len = que.front().lenght;
            visited[rowi][coli] = true;
            que.pop();
            //cout << "rowi=" << rowi << "  coli=" << coli << "  len=" << len << "  l="<<length<< endl;

            if(len >= length)  continue;

            if (rowi - 1 >= 0 && haveup(grid[rowi][coli]) && havedown(grid[rowi - 1][coli]) && !visited[rowi-1][coli]) {
                que.push({rowi - 1, coli,len+1});
            }
            if (rowi + 1 < row && havedown(grid[rowi][coli]) && haveup(grid[rowi + 1][coli]) && !visited[rowi+1][coli]) {
                que.push({rowi + 1, coli,len+1});
            }
            if (coli - 1 >= 0 && haveleft(grid[rowi][coli]) && haveright(grid[rowi][coli-1]) && !visited[rowi][coli-1]) {
                que.push({rowi, coli-1,len+1});
            }
            if (coli + 1 < column && haveright(grid[rowi][coli]) && haveleft(grid[rowi][coli+1]) && !visited[rowi][coli+1]) {
                que.push({rowi, coli+1,len+1});
            }
        }

        int temp = 0;
        for (int i = 0; i < row; i++) for (int j = 0; j < column; j++) if (visited[i][j]) temp++;
        cout << temp << endl;
    }
}


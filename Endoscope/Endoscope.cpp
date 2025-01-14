// Time  complexity O(4^length) "You can print the 28th line"

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int row, column, startR, startC, length;

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

void solution(vector<vector<int>>&grid, vector<vector<bool>>&visited, int rowi, int coli, int le) {
    if (length <= le) return;
    //cout << "rowi=" << rowi << "  coli=" << coli << "  le=" << le << "  l="<<length<< endl;

    if (rowi - 1 >= 0 && haveup(grid[rowi][coli]) && havedown(grid[rowi - 1][coli])) {
        visited[rowi-1][coli] = true;
        solution(grid, visited, rowi - 1, coli,le+1);
    }
    if (rowi + 1 < row && havedown(grid[rowi][coli]) && haveup(grid[rowi + 1][coli])) {
        visited[rowi + 1][coli] = true;
        solution(grid, visited, rowi + 1, coli,le+1);
    }
    if (coli - 1 >= 0 && haveleft(grid[rowi][coli]) && haveright(grid[rowi][coli-1])) {
        visited[rowi][coli-1] = true;
        solution(grid, visited, rowi, coli-1,le+1);
    }
    if (coli + 1 < column && haveright(grid[rowi][coli]) && haveleft(grid[rowi][coli+1])) {
        visited[rowi][coli+1] = true;
        solution(grid, visited, rowi, coli+1,le+1);
    }
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

        visited[startR][startC] = true;
        solution(grid,visited, startR,  startC,1);
        int temp = 0;
        for (int i = 0; i < row; i++) for (int j = 0; j < column; j++) if (visited[i][j]) temp++;
        cout << temp << endl;
    }
}

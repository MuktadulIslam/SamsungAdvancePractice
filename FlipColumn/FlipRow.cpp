/* Same problem, but here you need to find out maximum 1's column
after flipping the rows for k-th times */

// Time  complexity O(row*column)

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;
int row, column, k;

int main(void) {
    cin >> row >> column >> k;
    vector<vector<int>> grid(row, vector<int> (column));
    for(int i=0;i<row;i++) for(int j=0;j<column;j++) cin >> grid[i][j];

    // Then nearly same as flipColumns
    map<string, int> mp;
    for (int i = 0; i < column; i++) {      // Changes in this line
        string str = "";
        int temp,z = 0;
        for (int j = 0; j < row; j++) {
            temp = grid[j][i];               // Changes in this line
            str += ('0' + temp);
            if (temp == 0) z++;
        }
        if (k >= z && (k - z) % 2 == 0) mp[str]++;
    }
    int temp = 0;
    for (auto x : mp) {
        temp = max(temp, x.second);
    }
    cout << temp;
}


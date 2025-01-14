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
    map<string, int> mp;
    for (int i = 0; i < row; i++) {
        string str = "";
        int temp,z = 0;
        for (int j = 0; j < column; j++) {
            cin >> temp;
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

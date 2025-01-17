#include<iostream>
#include<string>
using namespace std;

int main(void) {
    int k,  sum=0;
    string str;
    cin >> k;
    cin >> str;

    for(int i=0,temp=-1;str[i];i++){
        if(str[i] == '(') temp++;
        else if(str[i] == ')') temp--;
        else if(temp == k){
            string s="";
            while(str[i]>='0' && str[i]<='9'){
                s+=str[i];
                i++;
            }
            i--;
            sum += stoi(s);
        }
    }
    cout << sum;
}

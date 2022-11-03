/*
Một số được coi là số đẹp nếu nó chỉ bao gồm 2 số là 8 và 0. Bạn được cấp một số nguyên dương X, nhiệm vụ của bạn là tìm bội dương nhỏ nhất của X thỏa mãn bội này là số đẹp.

Input Format

Dòng đầu tiên là số bộ test T. T dòng tiếp theo mỗi dòng là một số nguyên dương N.

Constraints

1<=T<=300; 1<=N<=300;

Output Format

Mỗi test in kết quả trên 1 dòng

Sample Input 0

6
240
19
55
47
287
247
Sample Output 0

8880
88008
880
80088
8088808
8000000008
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

string s ; int ok;
ll res[501];
void sinh()
{
    int i = s.length() - 1; 
    while(i >= 0 && s[i] == '8')
    {
        s[i] = '0';
        --i;
    }
    if(i == -1) ok = 0;
    else
    {
        s[i] = '8';
    }
}

int main()
{
    s = "0000000000000000000";
    ok = 1;
    vector<string>v;
    while(ok)
    {
        v.push_back(s);
        sinh();
    }
    for(int i = 1 ; i <= 500 ; i++)
    {
        for(auto x : v)
        {
            ll tmp = stoll(x);
            if(tmp != 0 && tmp % i == 0)
            {
                res[i] = tmp;
                break;
            }
        }
    }

    int t ; cin >> t;
    while(t--)
    {
        int n ; cin >> n;
        cout << res[n] << endl;
    }
    return 0;
}
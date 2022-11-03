/*Cho một xâu kí tự S chỉ bao gồm các kí tự , hãy in ra các hoán vị của các kí tự khác nhau trong S theo thứ tự từ điển tăng dần.

Input Format

1 dòng chứa xâu S

Constraints

1<=len(S)<=10;

Output Format

In ra các hoán vị của xâu S

Sample Input 0

lqk
Sample Output 0

klq
kql
lkq
lqk
qkl
qlk
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    string s; cin >> s;
    int a[12]; 
    set<char>se;
    for(int i = 0 ; i <s.length() ; i++)
    {
        se.insert(s[i]);
    }
    vector<char>v;
    for(auto x : se) v.push_back(x);
    for(int i = 0 ; i < v.size() ; i++)
    {
        a[i] = i;
    }
    do
    {
        for(int i = 0 ; i < v.size() ; i++)
        {
            cout << v[a[i]];
        }
        cout << endl;
    }while(next_permutation(a , a + v.size()));
    return 0;
}
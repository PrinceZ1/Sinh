/*Có n quả táo với khối lượng đã biết. Nhiệm vụ của bạn là chia táo thành hai nhóm sao cho sự khác biệt giữa trọng lượng của 2 nhóm là nhỏ nhất.

Input Format

Dòng 1 là số nguyên dương N : số lượng quả táo. Dòng thứ 2 là N số nguyên p1,p2,...,pn là trọng lượng tương ứng của các quả táo.

Constraints

1<=N<=20; 1<=pi<=10^9;

Output Format

In ra độ chênh lệch nhỏ nhất giữa 2 nhóm táo.

Sample Input 0

5
3 2 7 4 1
Sample Output 0

1
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

string s ; int ok;
void sinh()
{
    int i = s.length() - 1; 
    while(i >= 0 && s[i] == '1')
    {
        s[i] = '0';
        --i;
    }
    if(i == -1) ok = 0;
    else
    {
        s[i] = '1';
    }
}
int main()
{
    int n ; cin >>  n;
    ll a[n]; for(ll &x : a) cin >> x;
    s = string(n , '0');
    ok = 1; ll res = 1e9;
    while(ok)
    {
        ll sum1 = 0 , sum2 = 0;
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(s[i] == '0')
            {
                sum1 += a[i];
            }
            else sum2 += a[i];
        }
        res = min(abs(sum1 - sum2) , res);
        sinh();
    }
    cout << res;
    return 0;
}
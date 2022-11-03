/*Cho số nguyên dương N, bạn hãy in ra các cách biểu diễn N dưới dạng tổng của các số tự nhiên không vượt quá N.

Input Format

Số nguyên dương N

Constraints

1<=N<=20;

Output Format

Dòng đầu tiên in ra số lượng cách biểu diễn. Các dòng tiếp theo in ra cách biểu diễn được liệt kê theo thứ tự từ từ điển giảm dần.

Sample Input 0

5
Sample Output 0

7
5
4+1
3+2
3+1+1
2+2+1
2+1+1+1
1+1+1+1+1
*/

#include <bits/stdc++.h>
using namespace std;

int a[1001] , n, cnt , ok;

void ktao()
{
    cnt = 1;
    a[1] = n;
}
void sinh()
{
    int i = cnt;
    while(i >= 1 && a[i] == 1)
    {
        --i;
    }
    if(i == 0) ok = 0;
    else
    {
        a[i]--;
        int tong = cnt - i + 1;
        int x = tong / a[i];
        int y = tong % a[i];
        cnt = i;
        while(x--)
        {
            a[cnt + 1] = a[i];
            ++cnt;
        }
        if(y)
        {
            a[cnt + 1] = y;
            ++cnt;
        }
    }
}
int main()
{
    cin >> n;
    ktao();
    ok = 1;
    vector<string>v;
    int ans = 0;
    while(ok)
    {
        string res = "";
        for(int i = 1 ; i <= cnt ; i++)
        {
            res += to_string(a[i]);
            if(i != cnt) res += "+";
        }
        ++ans;
        v.push_back(res);
        sinh();
    }
    cout << ans << endl;
    for(auto x : v)
    {
        cout << x << endl;
    }
    return 0;
}
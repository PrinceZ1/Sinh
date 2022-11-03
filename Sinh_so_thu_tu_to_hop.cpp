/*Cho 2 số nguyên dương N và K và một tổ hợp K phần tử của tập N phần tử các số từ 1 tới N. Bạn hãy xác định xem tổ hợp đã cho có số thứ tự bao nhiêu nếu xếp các tổ hợp chập K của N theo thứ tự ngược. Ví dụ N = 5, K = 3 và tổ hợp đã cho là (2, 3, 4) sẽ là tổ hợp có số thứ tự 4.

Input Format

Dòng đầu gồm 2 số nguyên dương N và K. Dòng thứ 2 gồm K số mô tả tổ hợp đã cho. Dữ liệu đảm bảo tổ hợp đã cho là hợp lệ.

Constraints

1<=K<=N<=15;

Output Format

In ra số thứ tự của tổ hợp

Sample Input 0

12 4
8 9 10 11 
Sample Output 0

5
*/

#include <bits/stdc++.h>
using namespace std;

int a[1001] , n, k, ok;

void ktao()
{
    for(int i = 1; i <= k ; i++)
    {
        a[i] = i;
    }
}
void sinh()
{
    int i = k;
    while(i >= 1 && a[i] == n - k + i)
    {
        --i;
    }
    if(i == 0) ok = 0;
    else
    {
        a[i]++;
        for(int j = i + 1 ; j <= k ; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}
int main()
{
    cin >> n >> k;
    int x[n + 4];
    string s = "";
    for(int i = 1 ; i <= k ; i++)
    {
        cin >> x[i];
        s += to_string(x[i]);
    }
    ktao();
    ok = 1;
    vector<string>v;
    while(ok)
    {
        string res = "";
        for(int i = 1 ; i <= k ; i++)
        {
            res += to_string(a[i]);
        }
        v.push_back(res);
        sinh();
    }
    reverse(v.begin() , v.end());
    int cnt = 0;
    for(string x : v)
    {
        ++cnt;
        if(s == x)
        {
            cout << cnt ;
            return 0;
        }
    }
    return 0;
}
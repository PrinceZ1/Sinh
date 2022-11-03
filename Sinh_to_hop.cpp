/*Cho hai số nguyên dương N và K. Nhiệm vụ của bạn là hãy liệt kê tất cả các tập con K phần tử của các số từ 1 tới N.

Input Format

2 số nguyên dương N và K.

Constraints

1<=K<=N<=15;

Output Format

In ra các tổ hợp trên từng dòng.

Sample Input 0

5 2
Sample Output 0

12
13
14
15
23
24
25
34
35
45
*/

#include <bits/stdc++.h>
using namespace std;

int a[1001] , n , k, ok;

void ktao()
{
    for(int i = 1 ;i <= k ;i++)
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
        for(int j = i + 1 ; j <= n ; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}
int main()
{
    cin  >> n >> k;
    ok = 1;
    ktao();
    while(ok == 1)
    {
        for(int i = 1 ; i <= k ; i++)
        {
            cout << a[i];
        }
        cout << endl;
        sinh();
    }
    return 0;
}
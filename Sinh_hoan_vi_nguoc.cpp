/*Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của các số từ 1 tới N theo thứ tự ngược.

Input Format

Dòng duy nhất chứa số nguyên dương N.

Constraints

1<=N<=10;

Output Format

In ra các hoán vị của N phần tử theo thứ tự ngược

Sample Input 0

3
Sample Output 0

321
312
231
213
132
123
*/

#include <bits/stdc++.h>
using namespace std;

int a[1001] , n , ok;

void ktao()
{
    for(int i = 1;  i <= n ; i++)
    {
        a[i] = n - i + 1;
    }
}
void sinh()
{
    int i = n - 1;
    while(i >= 1 && a[i] < a[i + 1])
    {
        --i;
    }
    if(i == 0) ok = 0;
    else
    {
        int j = n;
        while(a[i] < a[j]) --j;
        swap(a[i] , a[j]);
        reverse(a + i + 1 , a + n + 1);
    }
}
int main()
{
    cin  >> n;
    ok = 1;
    ktao();
    while(ok == 1)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            cout << a[i];
        }
        cout << endl;
        sinh();
    }
    return 0;
}
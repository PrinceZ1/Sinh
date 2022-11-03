/*Cho N bạn học sinh, giáo viên muốn xếp các bạn học sinh này vào một hàng ngang gồm N chiếc ghế. Nhiệm vụ của bạn là liệt kê các cách sắp xếp N bạn học sinh này theo thứ tự tên người tăng dần về thứ tự từ điển.

Input Format

Dòng đầu tiên là số N. Dòng thứ 2 là N tên học sinh, mỗi tên chỉ bao gồm một từ.

Constraints

1<=N<=10;

Output Format

In ra các cách xếp trên từng dòng.

Sample Input 0

3
Lan Ngoc Nhung 
Sample Output 0

Lan Ngoc Nhung 
Lan Nhung Ngoc 
Ngoc Lan Nhung 
Ngoc Nhung Lan 
Nhung Lan Ngoc 
Nhung Ngoc Lan 
*/

#include <bits/stdc++.h>
using namespace std;

int a[1001] , n , ok;

void ktao()
{
    for(int i = 1 ; i <= n ; i++)
    {
        a[i] = i;
    }
}
void sinh()
{
    int i = n;
    while(i >= 1 && a[i] > a[i + 1])
    {
        --i;
    }
    if(i == 0) ok = 0;
    else
    {
        int j = n;
        while(a[i] > a[j]) --j;
        swap(a[i] , a[j]);
        reverse(a + i + 1 , a + n + 1);
    }
}
int main()
{
    cin  >> n;
    string s[n + 3];
    for(int i = 1 ;i <= n ; i++)
    {
        cin >> s[i];
    }
    sort(s + 1 , s + n + 1);
    ktao();
    do
    {
        for(int i = 1 ; i <= n ; i++)
        {
            cout << s[a[i]] << " ";
        }
        cout << endl;
    }while(next_permutation(a + 1 , a + n + 1));
    return 0;
}
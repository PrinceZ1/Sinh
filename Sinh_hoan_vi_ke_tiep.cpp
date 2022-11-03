/*Cho số tự nhiên N, bạn được cung cấp một hoán vị của N phần tử từ 1 tới N. Nhiệm vụ của bạn là sinh ra hoán vị kế tiếp của hoán vị được cho, nếu hoán vị được cho là hoán vị cuối cùng thì yêu cầu in ra hoán vị đầu tiên.

Input Format

Dòng đầu tiên là số tự nhiên N. Dòng thứ 2 là các số tự nhiên trong hoán vị hiện tại.

Constraints

1<=N<=1000;

Output Format

In ra hoán vị kế tiếp trên một dòng.

Sample Input 0

6
3 1 5 6 2 4 
Sample Output 0

3 1 5 6 4 2
*/

#include<bits/stdc++.h>
using namespace std; 

int a[1000] , n , ok;

int main(){
    cin >> n;
    for(int i = 1 ;i <= n ; i++)
    {
        cin >> a[i];
    }
    ok = 0;
    while(next_permutation(a + 1 , a + n + 1))
    {
        for(int i = 1 ; i <= n ; i++)
        {
            cout << a[i] << " ";
        }
        ok = 1;
        break;
    }
    if(!ok) 
    {
        for(int i = 1 ; i <= n ; i++)
        {
            cout << i << " ";
        }
    }
}
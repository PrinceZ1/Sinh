/*Tèo có N thẻ bài, mỗi thẻ ghi một con số từ 1 tới N. Không có 2 thẻ nào ghi hai số trùng nhau. Tèo muốn xếp thứ tự các thẻ bài sao cho không có hai con số nào liền kề nhau ở cạnh nhau.

Input Format

Số nguyên dương N

Constraints

4<=N<=10;

Output Format

In ra các cấu hình thỏa mãn theo thứ tự từ điển tăng dần

Sample Input 0

4
Sample Output 0

2413
3142
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
bool check(int a[] , int n)
{
    for(int i = 1 ; i < n; i++)
    {
        if(abs(a[i] - a[i + 1]) == 1) return false;
    }
    return true;
}
int main()
{
    int n; cin >> n;
    int a[n + 1];
    for(int i = 1 ; i<= n ;i++)
    {
        a[i] = i;
    }
    do
    {
        if(check(a , n))
        {
            for(int i = 1 ; i<= n ; i++)
            {
                cout << a[i];
            }
            cout << endl;
        }
    }while(next_permutation(a + 1 , a + n + 1));
    return 0;
}
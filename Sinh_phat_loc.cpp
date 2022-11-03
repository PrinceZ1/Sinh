/*Một xâu ký tự số chỉ bao gồm các chữ số 6 và 8 sẽ được gọi là “phát lộc” nếu thỏa mãn các điều kiện sau: Chữ số đầu tiên là chữ số 8, chữ số cuối cùng là chữ số 6. Không có 2 chữ số 8 nào ở cạnh nhau. Không có nhiều hơn 3 chữ số 6 ở cạnh nhau. Viết chương trình liệt kê các xâu ký tự phát lộc độ dài N theo thứ tự tăng dần.

Input Format

Số nguyên dương N;

Constraints

2<=N<=15;

Output Format

Các xâu lộc phát thỏa mãn điều kiện

Sample Input 0

7
Sample Output 0

8666866
8668666
8668686
8686686
8686866
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int x[101] , n , ok ;

void ktao()
{
    for(int i = 1 ; i <= n ; i++)
    {
        x[i] = 6;
    }
}
void sinh()
{
    int i = n;
    while(i >= 1 && x[i] == 8)
    {
        x[i] = 6;
        --i;
    }
    if(i == 0) ok = 0;
    else
    {
        x[i] = 8;
    }
}
bool check()
{
    if(x[1] != 8 || x[n] != 6) return false;
    int cnt = 1;
    for(int i = 2 ; i <= n ;i++)
    {
        if(x[i] == 8 && x[i - 1] == 8) return false;
        
        if(i >= 4 && x[i] == 6 && x[i - 1] == 6 && x[i - 2] == 6 && x[i - 3] == 6) return false;
    }
    return true;
}
int main()
{
    cin >> n;
    ok = 1;
    ktao();
    while(ok)
    {
        if(check())
        {
            for(int i = 1 ; i <= n ;i++)
            {
                cout << x[i];
            }
            cout << endl;
        }
        sinh();
    }
    return 0;
}
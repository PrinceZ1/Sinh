/*
Một tên trộm đột nhập vào 28techland và muốn lấy đi 1 số đồ vật có giá trị lớn nhất. Ở 28techland tồn tại n đồ vật, đồ vật thứ i sẽ có trọng lượng w[i] và có giá trị là v[i], tên trộm mang theo cái balo có thể chứa được trọng lượng tối đa là S, nhiệm vụ của bạn là hãy giúp tên trộm lựa chọn các đồ vật sao cho tổng trọng lượng của chúng không vượt quá S và có giá trị lớn nhất. Chú ý tên trộm chỉ có thể chọn hoặc không chọn 1 đồ vật.

Input Format

Dòng đầu tiên là N và S; Dòng thứ 2 là N số tương ứng với trọng lượng của các đồ vật; Dòng thứ 3 là N số tương ứng với giá trị của các đồ vật;

Constraints

1<=N<=15; 1<=S<=800; 1<=w[i]<=200; 1<=v[i]<=200;

Output Format

In ra tổng giá trị của các đồ vật trong balo.

Sample Input 0

12 356
174 153 127 156 156 5 132 161 170 26 181 50 
103 32 102 85 54 166 187 173 137 54 24 91 
Sample Output 0

617
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

struct Balo{
    int kg , gt;
};
int x[1001] , ok , n , m;

void ktao()
{
    for(int i = 1 ; i<= n ; i++)
    {
        x[i] = 0;
    }
}
void sinh()
{
    int i = n;
    while(i >= 1 && x[i] == 1)
    {
        x[i] = 0;
        --i;
    }
    if(i == 0) ok = 0;
    else
    {
        x[i] = 1;
    }
}
int main()
{
    cin >> n >> m;
    Balo a[209];
    for(int i = 1 ; i <= n ;i++)
    {
        cin >> a[i].kg;
    }
    for(int i = 1 ; i <= n ;i++)
    {
        cin >> a[i].gt;
    }
    sort(a + 1 ,a + n + 1 ,[](Balo a , Balo b)->bool
    {
        return float(a.gt / a.kg) > float(b.gt / b.kg);
    });
    ok = 1;
    ll res = 0;
    while(ok)
    {
        ll ans = 0 , sum = 0;
        for(int i = 1 ; i <= n ;i++)
        {
            if(x[i] == 1)
            {
                ans += a[i].gt;
                sum += a[i].kg;
            }
        }
        if(sum <= m)
        {
            res = max(ans , res);
        }
        sinh();
    }
    cout << res;
    return 0;
}
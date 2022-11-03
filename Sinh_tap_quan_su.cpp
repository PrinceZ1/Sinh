/*Tại Malibu(Mai Lĩnh) Resort, vào nửa đêm, cả trung đội nhận lệnh tập trung ở sân. Mỗi chiến sỹ được đánh số từ 1 đến N. Giám thị yêu cầu chọn ra một dãy K chiến sỹ để tập đội ngũ và cứ lần lượt duyệt hết tất cả các khả năng chọn K người như vậy từ nhỏ đến lớn (theo số thứ tự). Bài toán đặt ra là cho một nhóm K chiến sỹ hiện đang phải tập đội ngũ, hãy tính xem trong lượt chọn K người tiếp theo thì mấy người trong nhóm cũ sẽ được nghỉ. Nếu đã là nhóm cuối cùng thì tất cả đều được nghỉ

Input Format

Dòng 1: hai số nguyên dương N và K; Dòng 2 ghi K số thứ tự của các chiến sỹ đang phải tập đội ngũ (viết từ nhỏ đến lớn)

Constraints

1<=K<=N<=1000;

Output Format

In ra số lượng chiến sỹ được nghỉ

Sample Input 0

8 3
4 6 7 
Sample Output 0

1
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int a[1001] , n , k , ok;
set<int>se;
void sinh()
{
    int i = k;
    while( i >= 1 && a[i] == n - k + i)
    {
        --i;
    }
    if(i == 0)
    {
        cout << k;
    }
    else
    {
        a[i]++;
        for(int j = i + 1 ; j <= k ; j++)
        {
            a[j] = a[j - 1] + 1;
        }
        int res = 0;
        for(int i = 1 ; i <= k ; i++)
        {
             if(se.count(a[i]))
             {
                ++res;
             }
         }
        cout << k - res;
    }
}

int main()
{
    cin >> n >>k ;
    for(int i = 1 ; i <= k ; i++)
    {
        cin >> a[i];
        se.insert(a[i]);
    }
    sinh();
    return 0;
}
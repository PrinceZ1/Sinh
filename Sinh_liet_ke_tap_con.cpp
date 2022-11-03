/*Cho một tập gồm N phần tử được đánh số từ 1 đến N. Nhiệm vụ của bạn là liệt kê tất cả các tập con khác rỗng của N theo thứ tự từ điển tăng dần.

Input Format

Dòng duy nhất chứa số nguyên dương N.

Constraints

1<=N<=9;

Output Format

In ra các tập con của N theo thứ tự từ điển tăng dần.

Sample Input 0

4
Sample Output 0

1 
1 2 
1 2 3 
1 2 3 4 
1 2 4 
1 3 
1 3 4 
1 4 
2 
2 3 
2 3 4 
2 4 
3 
3 4 
4 
*/

#include<bits/stdc++.h>
using namespace std; 

int a[100] , n , ok;

void ktao()
{
    for(int i = 1 ; i <= n ;i++)
    {
        a[i] = 0;
    }
}
void sinh()
{
    int i = n;
    while(i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        --i;
    }
    if(i == 0)
    {
        ok = 0;
    }
    else
    {
        a[i] = 1;
    }
}
int main(){
    cin >> n;
    ok = 1;
    vector<string>v;
    ktao();
    sinh(); 
    while(ok)
    {
        string res = "";
        for(int i = 1 ; i <= n ;i++)
        {
            if(a[i] == 1)
            {
                res += to_string(i) + " ";
            }
        }
        v.push_back(res);
        sinh();
    }
    sort(v.begin() , v.end());
    for(string x : v)
    {
        cout << x << endl;
    }
}
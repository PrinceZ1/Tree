/*Cho thự tự duyệt Inorder của một cây nhị phân, hãy xác định xem thứ tự này có phải là thứ tự duyệt inorder của một cây nhị phân tìm kiếm hay không.

Input Format

Dòng đầu tiên là N : số lượng node trên cây; Dòng thứ 2 gồm N node theo thứ tự duyệt inorder

Constraints

1<=N<=1000; 1<=A[i]<=10^6;

Output Format

In ra YES nếu cây nhị phân đã cho là cây nhị phân tìm kiếm, ngược lại in ra NO.

Sample Input 0

8
1 3 5 7 9 11 14 16 
Sample Output 0

YES
*/


#include <bits/stdc++.h>
using namespace std;

bool check(int a[], int n) {
    for (int i=1;i<n;i++) {
        if (a[i] <= a[i-1]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    if (check(a,n)) cout << "YES";
    else cout << "NO";
    return 0;
}
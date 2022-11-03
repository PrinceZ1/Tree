/*Cho phép duyệt câu theo thứ tự giữa (Inorder) và duyệt trước (Preorder), bạn hãy in ra cây dưới dạng dạng duyệt sau (Postorder).

Thứ tự duyệt Preorder : 1 2 4 5 3 6 7. Thứ tự duyệt Inorder : 4 2 5 1 6 3 7. Thứ tự duyệt Postorder : 4 5 2 6 7 3 1.image

Input Format

Dòng đầu tiên là N : số lượng node của cây. Dòng thứ 2 là thứ tự duyệt trước của cây. Dòng thứ 3 là thứ tự duyệt giữa của cây.

Constraints

1<=N<=100;

Output Format

In ra thứ tự duyệt sau của cây.

Sample Input 0

7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 0

4 5 2 6 7 3 1 
*/


#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

void makeNode(Node *root, int u, int v, char c) {
    if (c == 'L') root->left = new Node(v);
    else root->right = new Node(v);
}

void insert(Node *root, int u, int v, char c) {
    if (root == NULL) return;
    if (root->val == u) makeNode(root, u, v, c);
    insert(root->left, u, v, c);
    insert(root->right, u, v, c);
}

int find(int in[], int n, int x) {
    for (int i=0;i<n;i++) {
        if (in[i] == x) return i;
    }
    return -1;
}

void solve(int in[], int pre[], int n) {
    int search = find(in, n, pre[0]);
    if (search != 0) {
        solve(in, pre + 1, search);
    }
    if (search != n-1) {
        solve(in + search + 1, pre + search + 1, n - search - 1);
    }
    cout << pre[0] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int pre[n], in[n];
    for (int i=0;i<n;i++) {
        cin >> pre[i];
    }
    for (int i=0;i<n;i++) {
        cin >> in[i];
    }
    solve(in, pre, n);
    return 0;
}
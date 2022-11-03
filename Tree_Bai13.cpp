/*Cho cây nhị phân hãy đưa ra thứ tự duyệt cây theo thuật toán DFS, khi mở rộng 2 node con bên trái hoặc bên phải, ưu tiên mở rộng node con bên phải trước.

Input Format

Dòng đâu tiên là N : số lượng cạnh của cây. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node con bên phải của x.

Constraints

1<=N<=1000;

Output Format

In ra thứ tự duyệt cây theo thuật toán DFS

Sample Input 0

6
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 
Sample Output 0

1 3 7 6 2 5 4 */


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

void dfs(Node *root) {
    if (root == NULL) return;
    cout << root->val << " ";
    dfs(root->right);
    dfs(root->left);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    Node *root = NULL;
    while (n--) {
        int u,v; char c;
        cin >> u >> v >> c;
        if (root == NULL) {
            root = new Node(u);
            makeNode(root, u, v, c);
        } else {
            insert(root, u, v, c);
        }
    }
    dfs(root);
    return 0;
}
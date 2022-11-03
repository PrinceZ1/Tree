/*Cho cây nhị phân, nhiệm vụ của bạn là xác định chiều cao của từng node trên cây, node gốc được quy định có chiều cao là 0, chiều cao của các node khác được tính bằng số cạnh trên đường đi ngắn nhất từ nó tới gốc.

Input Format

Dòng đâu tiên là N : số lượng cạnh của cây. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node con bên phải của x.

Constraints

1<=N<=1000; 1<=x,y<=10000;

Output Format

In ra chiều cao từng node trên cây theo thứ tự node tăng dần.

Sample Input 0

6
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 
Sample Output 0

0 1 1 2 2 2 2 
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

int d[10001] = {0};

void dfs(Node *root) {
    if (root == NULL) return;
    if (root->left != NULL) d[root->left->val] = d[root->val] + 1;
    if (root->right != NULL) d[root->right->val] = d[root->val] + 1;
    dfs(root->left);
    dfs(root->right);
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
    memset(d, 0, sizeof(d));
    dfs(root);
    for (int i=0;i<10001;i++) {
        if (d[i] != 0 || (i == root->val && d[i] == 0)) {
            cout << d[i] << " ";
        }
    }
    return 0;
}
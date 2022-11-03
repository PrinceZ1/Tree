/*Cho 2 cây nhị phân, nhiệm vụ của bạn là kiểm tra xem 2 cây nhị phân đã cho có giống nhau hoàn toàn hay không ?

Input Format

Dòng đầu tiên là số N1 : Số lượng cạnh của cây nhị phân thứ 1. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node con bên phải của x. Dòng tiếp theo là số N2 : Số lượng cạnh của cây nhị phân thứ 2. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node con bên phải của x.

Constraints

1<=N1,N2<=100;

Output Format

In ra YES hoặc NO.

Sample Input 0

6
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 
6
1 2 L 1 3 R 2 4 L 2 5 R 3 7 R 3 6 L 
Sample Output 0

YES
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

bool check(Node *root1, Node *root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 != NULL && root2 != NULL) {
        return root1->val == root2->val && check(root1->left, root2->left) && check(root1->right, root2->right);
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    Node* root1 = NULL;
    while (n--) {
        int u,v; char c;
        cin >> u >> v >> c;
        if (root1 == NULL) {
            root1 = new Node(u);
            makeNode(root1, u, v, c);
        } else {
            insert(root1, u, v, c);
        }
    }
    cin >> n;
    Node* root2 = NULL;
    while (n--) {
        int u, v; char c;
        cin >> u >> v >> c;
        if (root2 == NULL) {
            root2 = new Node(u);
            makeNode(root2, u, v, c);
        } else {
            insert(root2, u, v, c);
        }
    }
    if (check(root1, root2)) cout << "YES";
    else cout << "NO";
    return 0;
}
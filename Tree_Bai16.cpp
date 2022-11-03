/*Cho mảng số nguyên A[] có N phần tử, lần lượt thêm các phần tử trong mảng vào cây nhị phân sao cho cây nhị phân thu được là cây nhị phân tìm kiếm với gốc cây là A[0]. In ra thứ tự duyệt cây Inorder.

Input Format

Dòng đầu tiên là N : số lượng phần tử trong mảng A[]; Dòng thứ 2 gồm N phần tử trong mảng A[];

Constraints

1<=N<=1000; 1<=A[i]<=10^6;

Output Format

In ra thứ tự duyệt in order của cây nhị phân tìm kiếm tạo được.

Sample Input 0

7
7 3 5 8 6 2 4
Sample Output 0

2 3 4 5 6 7 8 
*/



#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
    Node (int x) {
        val = x;
        left = right = NULL;
    }
};

Node *insertNode(Node *root, int x) {
    if (root == NULL) {
        return new Node(x);
    }
    if (root->val > x) {
        root->left = insertNode(root->left, x);
    } else {
        root->right = insertNode(root->right, x);
    }
    return root;
}

Node* buildTree(int a[], int n) {
    Node *root = NULL;
    for (int i=0;i<n;i++) {
        root = insertNode(root, a[i]);
    }
    return root;
}

void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
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
    Node *root = buildTree(a, n);
    inOrder(root);
    return 0;
}
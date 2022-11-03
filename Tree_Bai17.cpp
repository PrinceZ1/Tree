/*Cho mảng số nguyên A[] có N phần tử, lần lượt thêm các phần tử trong mảng vào cây nhị phân sao cho cây nhị phân thu được là cây nhị phân tìm kiếm với gốc cây là A[0]. In ra thứ tự duyệt cây Preoder.

Input Format

Dòng đầu tiên là N : số lượng phần tử trong mảng A[]; Dòng thứ 2 gồm N phần tử trong mảng A[];

Constraints

1<=N<=1000; 1<=A[i]<=10^6;

Output Format

In ra thứ tự duyệt in Preorder của cây nhị phân tìm kiếm tạo được.

Sample Input 0

7
7 3 5 8 6 2 4
Sample Output 0

7 3 2 5 4 6 8 
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

Node* insertNode(Node *root, int x) {
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

void preOrder(Node *root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
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
    preOrder(root);
    return 0;
}
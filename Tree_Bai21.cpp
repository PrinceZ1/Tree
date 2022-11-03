/*Cho mảng số nguyên A[] có N phần tử, lần lượt thêm các phần tử trong mảng vào cây nhị phân sao cho cây nhị phân thu được là cây nhị phân tìm kiếm với gốc cây là A[0]. Nhiệm vụ của bạn là xóa node có giá trị X trên cây nhị phân tìm kiếm nếu tồn tại node có giá trị X.

Input Format

Dòng đầu tiên là N và X : số lượng phần tử trong mảng A[] và phần tử cần xóa; Dòng thứ 2 gồm N phần tử trong mảng A[];

Constraints

1<=N<=1000; 1<=A[i], X<=10^6;

Output Format

In ra thứ tự duyệt cây Inorder sau khi xóa

Sample Input 0

8
8 7 5 6 2 4 1 3 
8
Sample Output 0

1 2 3 4 5 6 7
*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, b, a) for (int i = b; i >= a; --i)
#define fill(a, b) memset(a, b, sizeof(a))
#define all(v) v.begin(), v.end()
#define ii pair<int, int>
const int MOD = 1e9 + 7;

class node
{
public:
    int val;
    node *left;
    node *right;
    node(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
};
node *insertNode(node *root, int val)
{
    if (root == nullptr)
    {
        return new node(val);
    }
    if (val < root->val)
    {
        root->left = insertNode(root->left, val);
    }
    else
    {
        root->right = insertNode(root->right, val);
    }
    return root;
}
node *minValNode(node *root)
{
    node *curr = root;
    if (curr == nullptr)
        return nullptr;
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr;
}
node *deleteNode(node *root, int key)
{
    if (root == nullptr)
        return nullptr;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return nullptr;
        }
        if (root->left == nullptr)
        {
            node *tmp = root->right;
            delete root;
            return tmp;
        }
        if (root->right == nullptr)
        {
            node *tmp = root->left;
            delete root;
            return tmp;
        }
        node *tmp = minValNode(root->right);
        root->val = tmp->val;
        root->right = deleteNode(root->right, tmp->val);
    }
    return root;
}
void inorder(node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}
int main()
{
    node *root = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insertNode(root, x);
    }
    int key;
    cin >> key;
    root = deleteNode(root, key);
    inorder(root);
}

/*Cho mảng số nguyên A[] có N phần tử, lần lượt thêm các phần tử trong mảng vào cây nhị phân sao cho cây nhị phân thu được là cây nhị phân tìm kiếm với gốc cây là A[0]. Tìm phần tử có giá trị lớn nhất và nhỏ nhất trên cây nhị phân tìm kiếm.

Input Format

Dòng đầu tiên là N : số lượng phần tử trong mảng A[]; Dòng thứ 2 gồm N phần tử trong mảng A[];

Constraints

1<=N<=1000; 1<=A[i]<=10^6;

Output Format

In ra giá trị lớn nhất, nhỏ nhất của cây nhịp phân tìm kiếm

Sample Input 0

8
8 7 5 6 2 4 1 3 
Sample Output 0

8 1
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
void makeRoot(node *root, int v, char c)
{
    if (c == 'L')
        root->left = new node(v);
    else
        root->right = new node(v);
}
void insertNode(node *root, int u, int v, char c)
{
    if (root == nullptr)
        return;
    if (root->val == u)
    {
        makeRoot(root, v, c);
    }
    else
    {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}
bool check(node *root, node *root2)
{
    if (root == NULL && root2 == NULL)
        return true;
    if (root != NULL && root2 != NULL)
    {
        return root->val == root2->val && check(root->left, root2->left) && check(root->right, root2->right);
    }
    return false;
}
void DFS(node *root)
{
    if (root == nullptr)
        return;
    cout << root->val << ' ';
    DFS(root->right);
    DFS(root->left);
}
vector<int> res;
void chieuCao(node *root, int h)
{
    if (root == nullptr)
        return;
    res.push_back(h);
    if (root->left != nullptr)
        chieuCao(root->left, h + 1);
    if (root->right != nullptr)
        chieuCao(root->right, h + 1);
}
node *insertRoot(node *root, int x)
{
    if (root == nullptr)
        return new node(x);
    if (x < root->val)
        root->left = insertRoot(root->left, x);
    else
        root->right = insertRoot(root->right, x);
    return root;
}
int maxVal(node *root)
{
    if (root->right == NULL)
        return root->val;
    return maxVal(root->right);
}
int minVal(node *root)
{
    if (root->left == NULL)
        return root->val;
    return minVal(root->left);
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
        root = insertRoot(root, x);
    }
    cout << maxVal(root) << ' ' << minVal(root) << endl;
}

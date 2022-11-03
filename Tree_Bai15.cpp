/*Cho cây nhị phân, nhiệm vụ của bạn là đếm xem trên cây có bao nhiêu node lá có chiều cao lớn nhất, node gốc được quy định có chiều cao là 0, chiều cao của các node khác được tính bằng số cạnh trên đường đi ngắn nhất từ nó tới gốc.

Input Format

Dòng đâu tiên là N : số lượng cạnh của cây. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node con bên phải của x.

Constraints

1<=N<=1000; 1<=x,y<=10000;

Output Format

In ra số node lá có chiều cao lớn nhất

Sample Input 0

6
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 
Sample Output 0

4
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
int main()
{
    node *root = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (root == nullptr)
        {
            root = new node(u);
            makeRoot(root, v, c);
        }
        else
        {
            insertNode(root, u, v, c);
        }
    }
    chieuCao(root, 0);
    sort(all(res));
    int x = res.back();
    int cnt = 0;
    for (auto &&i : res)
    {
        if (i == x)
            ++cnt;
    }
    cout << cnt << endl;
}

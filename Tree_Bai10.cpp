/*Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân đã cho có phải là cây nhị phân hoàn hảo hay không. Cây nhị phân hoàn hảo nếu mọi node lá của nó có cùng mức và mỗi node trung gian đều có 2 con.

Input Format

Dòng đâu tiên là N : số lượng cạnh của cây. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node con bên phải của x.

Constraints

1<=N<=1000; 1<=x,y<=10^5;

Output Format

In ra YES hoặc NO tùy theo kết quả của bài toán

Sample Input 0

6
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 
Sample Output 0

YES
Sample Input 1

7
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 6 8 L 
Sample Output 1

NO
*/


#include <bits/stdc++.h>
using namespace std;
struct node
{
     int val;
     node *right;
     node *left;
     node(int x)
     {
          val = x;
          right = NULL;
          left = NULL;
     }
};
void makeNode(node *root, int u, int v, char c)
{
     if (c == 'L')
     {
          root->left = new node(v);
     }
     if (c == 'R')
          root->right = new node(v);
}
void InsertNode(node *root, int u, int v, char c)
{
     if (root == NULL)
          return;
     if (root->val == u)
     {
          makeNode(root, u, v, c);
     }
     else
     {
          InsertNode(root->left, u, v, c);
          InsertNode(root->right, u, v, c);
     }
}
void inOrder(node *root)
{
     if (root == NULL)
          return;
     inOrder(root->left);
     cout << root->val << " ";
     inOrder(root->right);
}
int maxH = 0;
bool checkLever(node *root, int h)
{
     if (root == NULL)
          return true;
     if (root->left == NULL && root->right == NULL)
     {
          if (maxH == 0)
          {
               maxH = h;
               return true;
          }
          else
          {
               return h == maxH;
          }
     }
     else
     {
          return checkLever(root->right, h + 1) && checkLever(root->left, h + 1);
     }
}
bool checkLeaf(node *root){
     if(root==NULL)
          return true;
     if(root->left!=NULL && root->right==NULL){
          return false;
     }
     if(root->left==NULL && root->right!=NULL)
          return false;
     return checkLeaf(root->left) && checkLeaf(root->right);
}
int main()
{
     node *root = NULL;
     int n;
     cin >> n;
     for (int i = 0; i < n; i++)
     {
          int u, v;
          char c;
          cin >> u >> v >> c;
          if (root == NULL)
          {
               root = new node(u);
               makeNode(root, u, v, c);
          }
          else
          {
               InsertNode(root, u, v, c);
          }
     }
     
     if (checkLeaf(root) && checkLever(root,0))
     {
          cout << "YES";
     }
     else
          cout << "NO";
}
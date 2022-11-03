/*Cho cây nhị phân, nhiệm vụ của bạn là duyệt cây theo thứ tự Postorder. Thứ tự duyệt Postorder của cây nhị phân bên dưới xuất hiện trong test case mẫu.

image

Input Format

Dòng đâu tiên là N : số lượng cạnh của cây. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node con bên phải của x.

Constraints

1<=N<=1000; 1<=x,y<=10^5;

Output Format

In ra thứ tự duyệt cây Postorder

Sample Input 0

6
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 
Sample Output 0

4 5 2 6 7 3 1 
*/



#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node{
    int val;
    node *left;
    node *right;
    node(int x){
        val = x;
        left = right = NULL;
    }
};

void makeRoot(node *root, int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

//Cho v la node con cua u
void insertNode(node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u){
        makeRoot(root, u, v, c);
    }
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

void inorder(node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

void preorder(node *root){
    if(root == NULL) return;
    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    node *root = NULL;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int u, v; char c;
        cin >> u >> v >> c;
        if(root == NULL){
            root = new node(u);
            makeRoot(root, u, v, c);
        }
        else{
            insertNode(root, u, v, c);
        }
    }
    postorder(root);
}
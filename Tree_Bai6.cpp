/*Cây nhị phân được gọi là đầy đủ nếu mọi node trung gian của nó đều có 2 con trái và phải. Nhiệm vụ của bạn là kiểm tra xem cây nhị phân đã cho có phải là cây nhị phân đầy đủ hay không, có in ra YES, ngược lại in ra NO.

Input Format

Dòng đâu tiên là N : số lượng cạnh của cây. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node con bên phải của x.

Constraints

1<=N<=1000; 1<=x,y<=10^5;

Output Format

In ra đáp án của bài toán

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

using ll = long long;

struct Node{
    int val;
    Node *left, *right;
    Node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

void makeRoot(Node *root, int u, int v, char c){
    if(c == 'L') root->left = new Node(v);
    else root->right = new Node(v);
}

void insertNode(Node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u){
        makeRoot(root, u, v, c);
    }
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

void inorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

void preorder(Node *root){
    if(root == NULL) return;
    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
}

bool check(Node *root){
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return true;
    if(root->left != NULL && root->right != NULL)
        return check(root->left) && check(root->right);
    else
        return false;
}


int main(){
    Node *root = NULL;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int u, v; char c;
        cin >> u >> v >> c;
        if(root == NULL){
            root = new Node(u);
            makeRoot(root, u, v, c);
        }
        else{
            insertNode(root, u, v, c);
        }
    }
    if(check(root)) cout << "YES\n";
    else cout << "NO\n";
}
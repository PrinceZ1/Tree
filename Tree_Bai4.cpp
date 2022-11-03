/*Cho cây nhị phân, nhiệm vụ của bạn là đếm số lượng node trên cây là node lá

Input Format

Dòng đâu tiên là N : số lượng cạnh của cây. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node con bên phải của x.

Constraints

1<=N<=1000; 1<=x,y<=10^5;

Output Format

In ra số lượng node lá trên cây

Sample Input 0

6
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 
Sample Output 0

4
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

int count(Node *root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return count(root->left) + count(root->right);
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
    cout << count(root) << endl;
}
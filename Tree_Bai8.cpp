/*Cho cây nhị phân, nhiệm vụ của bạn là duyệt cây theo mức. Ví dụ cây nhị phân dưới đây sẽ có thứ tự duyệt theo mức như sau : 1 2 3 4 5 6 7

image

Input Format

Dòng đâu tiên là N : số lượng cạnh của cây. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node con bên phải của x.

Constraints

1<=N<=1000; 1<=x,y<=10^5;

Output Format

In ra thứ tự duyệt theo mức

Sample Input 0

6
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 
Sample Output 0

1 2 3 4 5 6 7 
Sample Input 1

7
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 6 8 L 
Sample Output 1

1 2 3 4 5 6 7 8 
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

void levelOrder(node *root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *tmp = q.front(); q.pop();
        cout << tmp->val << ' ';
        if(tmp->left != NULL)
            q.push(tmp->left);
        if(tmp->right != NULL)
            q.push(tmp->right);
    }
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
    levelOrder(root);
}
/*Cho cây nhị phân, nhiệm vụ của bạn là tìm độ cao lớn nhất của 1 node lá trên cây.

Input Format

Dòng đâu tiên là N : số lượng cạnh của cây. Các dòng tiếp theo mô tả cây nhị phân bằng 3 số (x, y, z) : x là node cha, y là node con, z có thể nhận 1 trong 2 giá trị là L và R, tương ứng với y là node con bên trái hoặc node con bên phải của x.

Constraints

1<=N<=1000; 1<=x,y<=10^5;

Output Format

In ra độ cao của cây

Sample Input 0

6
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 
Sample Output 0

2
Sample Input 1

7
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R 6 8 L 
Sample Output 1

3
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void makeRoot(node* root, int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertNode(node* root, int u, int v, char c){
    if(root == NULL) return;
    if(root->data == u){
        makeRoot(root, u, v, c);
        return;
    }
    insertNode(root->left, u, v, c);
    insertNode(root->right, u, v, c);
}

int heightOfTree(node* root){
    if(root == NULL) return -1;
    return max(heightOfTree(root->left), heightOfTree(root->right))+1;
}

int main(){
    node* root = NULL;
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int u,v;
        char c;
        cin >> u >> v >> c;
        if(root == NULL){
            root = new node(u);
            makeRoot(root,u,v,c);
        }
        else insertNode(root,u,v,c);
    }
    cout << heightOfTree(root);
    return 0;
}
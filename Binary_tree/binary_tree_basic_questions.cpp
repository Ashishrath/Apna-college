#include <iostream>
#include <queue>

using namespace std;
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
    
void inorder(Node* root) {
    if(root == nullptr) {
        return;
    }
    
    inorder(root->left);
    cout<< root->data <<' ';
    inorder(root->right);
}

void preorder(Node* root) {
    if(root == nullptr) {
        return;
    }
    
    cout<< root->data <<' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if(root == nullptr) {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<< root->data <<' ';
}

void levelorder(Node* root) {
    if(root == nullptr) {
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        int curr_size = q.size();
        
        for(int i = 0; i < curr_size; i++) {
            Node* curr = q.front();
            
            cout<<curr->data<<' ';
            
            q.pop();
            if(curr->left) {
                q.push(curr->left);
            }
            if(curr->right) {
                q.push(curr->right);
            }
        }
        cout<<endl;
    }
}

int height(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    
    int left = height(root->left);
    int right = height(root->right);
    
    return 1 + max(left, right);
}

int diameter(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    
    int left = height(root->left);
    int right = height(root->right);
    
    return 1 + left + right;
}

int width(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    int ans = 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()) {
        int q_size = q.size();
        int start = 0, end = 0, maxi = 0;
        
        for(int i = 0; i < q_size; i++) {
            auto curr = q.front();
            if(i == 0) {
                start = curr.second;
            } else if(i == q_size-1) {
                end = curr.second;
            }
            
            q.pop();
            if(curr.first->left) {
                q.push({curr.first->left, (curr.second)*2 + 1});
            }
            if(curr.first->right) {
                q.push({curr.first->right, (curr.second)*2 + 2});
            }
        }
        
        maxi = end - start + 1;
        ans = max(ans, maxi);
    }
    
    return ans;
}

int main()
{
    Node *root;
    
    root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    root->right->right->right = new Node(9);
    
    // Node* root = new Node(3);
    // root->left = new Node(5);
    // root->right = new Node(1);
    // root->left->left = new Node(6);
    // root->left->right = new Node(2);
    // root->right->left = new Node(0);
    // root->right->right = new Node(8);
    // root->left->right->left = new Node(7);
    // root->left->right->right = new Node(4);
    
    cout<<"Inorder"<<endl;
    inorder(root);
    cout<<"\nPreorder"<<endl;
    preorder(root);
    cout<<"\nPostorder"<<endl;
    postorder(root);
    cout<<"\nLevelorder"<<endl;
    levelorder(root);
    
    cout<<"Height of tree: " << height(root)<<endl;
    cout<<"Diameter of tree: " << diameter(root)<<endl;
    cout<<"Width of tree: " << width(root)<<endl;
    
    
    return 0;
}

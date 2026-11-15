#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
class node{
    public:
    node *left;
    node *right;
    int data;
    int h;
    node* createNode(int d){
        node* new_node = new node;
        new_node->data = d;
        new_node->left = nullptr;
        new_node->right = nullptr;
        new_node->h = 0;
        return new_node;
    }
};
class AVL{
    public:
    node* root;
    std::stack<node*>s;
    AVL(std::vector<int>v){
        if(v.size()<1){
            root = nullptr;
            return;
        }
        root = root->createNode(v[0]);
        node* top = root;
        s.push(root);
        for(int i = 1 ; i < v.size() ; i++){
            if(v[i] < s.top()->data){
                top->left = top->left->createNode(v[i]);
                top = top->left;
                s.push(top);
            }
            else if(v[i]>s.top()->data){
                while(!s.empty() && v[i] < s.top()->data){
                    top = s.top();
                    s.pop();
                }
                top->right = top->right->createNode(v[i]);
                top = top->right;
                s.push(top);
            }
        }
    }
    node* Rsearch(node* n,int key){
        if(n == nullptr){
            return nullptr;
        }
        if(n->data == key){
            return root;
        }
        else if(key < n->data){
            return Rsearch(n->left,key);
        }
        else{
            return Rsearch(n->right,key);
        }
    }
    int getHeight(node* n){
        return (n->left->h >= n->right->h)? n->left->h : n->right->h;
    }
    node* rightRotate(node* n){
        node* Nleft = n->left;
        node* temp = Nleft->right;
        Nleft->right = n;
        n->left = temp;
        n->h = 1+__max(getHeight(n->left),getHeight(n->right));
        Nleft->h = 1+__max(getHeight(Nleft->left),getHeight(Nleft->right));
        return Nleft;
    }
    node* leftRotate(node* n){
        node* NRight = n->right;
        node* temp = NRight->left;
        NRight->left = n;
        n->right = temp;
        n->h = 1+__max(getHeight(n->left),getHeight(n->right));
        NRight->h = 1+__max(getHeight(NRight->left),getHeight(NRight->right));
        return NRight;
    }
    node* insert(node* n,int d){
        if(n == nullptr){
            n = n->createNode(d);
            return n;
        }
        if(d < n->data){
            n->left =  insert(n->left,d);
        }
        else if(d > n->data){
            n->right = insert(n->right,d);
        }
        return n;
    }
    void traverse_pre(node *temp)
    {
        if (temp != nullptr)
        {
            std::cout << temp->data << " ";
            traverse_pre(temp->left);
            traverse_pre(temp->right);
        }
    }
    void traverse_in(node *temp)
    {
        if (temp != nullptr)
        {
            traverse_in(temp->left);
            std::cout << temp->data << " ";
            traverse_in(temp->right);
        }
    }
    void traverse_post(node *temp)
    {
        if (temp != nullptr)
        {
            traverse_post(temp->left);
            traverse_post(temp->right);
            std::cout << temp->data << " ";
        }
    }
    node* predessor(node* n){
        while(root->right){
            root = root->right;
        }
        return root;
    }
    node* successor(node* n){
        while(root->left){
            root = root->left;
        }
        return root;
    }   
    node* delete_node(node* temp , int key){
        if(temp == nullptr){
            return nullptr;
        }
        if(key < temp->data){
            temp->left = delete_node(temp->left,key);
        }
        else if(key > temp->data){
            temp->right = delete_node(temp->right,key);
        }
        else{
            if(!temp->left && !temp->right){
                delete temp;
                return nullptr;
            }
            if(temp->left == nullptr){
                node* n = temp->right;
                delete temp;
                return n;
            }
            if(temp->right == nullptr){
                node* n = temp->left;
                delete temp;
                return n;
            }
            node* pre = predessor(root->left);
            temp->data = pre->data;
            temp->left = delete_node(temp->left,pre->data);
        }
        return temp;
    }
};
int main(void){
    std::vector<int>vect{20,10,15,40,30,35};
    AVL b(vect);
    b.traverse_in(b.root);
    std::cout<<std::endl;
    b.traverse_pre(b.root);
    std::cout<<std::endl;
    b.traverse_post(b.root);
    b.delete_node(b.root,10);
    std::cout<<std::endl;
    b.traverse_in(b.root);
    return 0;
}
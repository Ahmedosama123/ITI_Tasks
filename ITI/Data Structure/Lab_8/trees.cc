#include <iostream>
#include <deque>
class node
{
public:
    node *l;
    node *r;
    int data;
    node *create_node(int d)
    {
        node *new_node = new node;
        new_node->data = d;
        new_node->l = nullptr;
        new_node->r = nullptr;
        return new_node;
    }
};
class tree
{
public:
    int data;
    node *root;
    node *current;
    node *new_node;
    int i;
    int count_nodes;
    std::deque<node *> d;
    tree(int *arr, int size)
    {
        if (size <= 0)
        {
            root = nullptr;
            current = nullptr;
            new_node = nullptr;
            count_nodes = 0;
            return;
        }
        count_nodes = 0;
        root = root->create_node(arr[0]);
        count_nodes++;
        d.push_back(root);
        i = 0;
        while (i < size)
        {
            i++;
            current = d.front();
            d.pop_front();
            if (i < size)
            {
                new_node = new_node->create_node(arr[i]);
                count_nodes++;
                current->l = new_node;
                d.push_back(new_node);
            }
            i++;
            if (i < size)
            {
                new_node = new_node->create_node(arr[i]);
                count_nodes++;
                current->r = new_node;
                d.push_back(new_node);
            }
        }
    }
    void traverse_pre(node *temp)
    {
        if (temp != nullptr)
        {
            std::cout << temp->data << " ";
            traverse_pre(temp->l);
            traverse_pre(temp->r);
        }
    }
    void traverse_in(node *temp)
    {
        if (temp != nullptr)
        {
            traverse_in(temp->l);
            std::cout << temp->data << " ";
            traverse_in(temp->r);
        }
    }
    void traverse_post(node *temp)
    {
        if (temp != nullptr)
        {
            traverse_post(temp->l);
            traverse_post(temp->r);
            std::cout << temp->data << " ";
        }
    }
    void traverse_level(node *temp)
    {
        node *current;
        std::deque<node *> dd;
        if (temp != nullptr)
        {
            dd.push_back(temp);
            while(!dd.empty()){
                current = dd.front();
                dd.pop_front();
                std::cout<<current->data<<" ";
                if(current->l){
                    dd.push_back(current->l);
                }
                if(current->r){
                    dd.push_back(current->r);
                }
            }
        }
    }
    int count_tree_nodes()
    {
        return count_nodes;
    }
   int count_tree_leefs()
    {
        return ((count_nodes+1)/2);
    }
};
int main(void)
{
    int arr[7] = {10, 20, 30, 40, 50,60,70};
    tree t(arr, 7);
    t.traverse_pre(t.root);
    std::cout << "\n";
    t.traverse_in(t.root);
    std::cout << "\n";
    t.traverse_post(t.root);
    std::cout << "\n";
    std::cout<< t.count_tree_nodes();
    std::cout << "\n";
    t.traverse_level(t.root);
    std::cout << "\n";
    std::cout<<t.count_tree_leefs();
}
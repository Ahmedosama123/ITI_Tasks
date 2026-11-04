#include <iostream>
#include <limits>
class node
{
public:
    node *prev;
    int data;
    node *next;
    /****************************************************** */
    node *create_node(int d)
    {
        node *new_node = new node;
        new_node->prev = nullptr;
        new_node->data = d;
        new_node->next = nullptr;
        return new_node;
    }
};
class stack
{
private:
    node *head;
    node *tail;

public:
    stack(int data)
    {
        head = head->create_node(data);
        tail = head;
    }
    void dispaly(void)
    {
        if (head == nullptr)
        {
            std::cout << "LinkedList is empty\n";
            return;
        }
        node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
    int count(void)
    {
        int c = 0;
        node *temp = head;
        while (temp != nullptr)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }
    bool is_empty(void){
        return (head == nullptr);
    }
    void push(int data)
    {
        if (is_empty())
        {
            head = head->create_node(data);
            tail = head;
            return;
        }
        node *temp = temp->create_node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    int pop(void){
        int data;
        if(head == nullptr){
            std::cout<<"LinkedList is empty\n";
            return -1;
        }
        node *temp = tail;
        tail = temp->prev;
        tail->next = nullptr;
        data = temp->data;
        delete temp;
        return data;
    }
    int peak(void){
        if(head == nullptr){
            std::cout<<"LinkedList is empty\n";
            return -1;
        }
        return tail->data;
    }
};
int main(void)
{
    int data = 0;
    stack s1(10);
    s1.dispaly();
    std::cout << "\nthe count of nodes = " << s1.count();
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    std::cout << "\n";
    s1.dispaly();
    data = s1.pop();
    std::cout << "\n";
    s1.dispaly();
    data = s1.peak();
    std::cout << "\n"<<data;
}
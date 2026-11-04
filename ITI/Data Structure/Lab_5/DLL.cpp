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
class DLL
{
private:
    node *head;
    node *tail;

public:
    DLL(int *arr, int size)
    {
        if (size <= 0)
        {
            head = nullptr;
            tail = nullptr;
            return;
        }
        head = head->create_node(arr[0]);
        tail = head;
        for (int i = 1; i < size; i++)
        {
            tail->next = tail->create_node(arr[i]);
            tail->next->prev = tail;
            tail = tail->next;
        }
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
    int sum(void)
    {
        int s = 0;
        node *temp = head;
        while (temp != nullptr)
        {
            s += temp->data;
            temp = temp->next;
        }
        return s;
    }
    int max(void)
    {
        int m = INT32_MIN;
        node *temp = head;
        while (temp != nullptr)
        {
            m = __max(m, temp->data);
            temp = temp->next;
        }
        return m;
    }
    int min(void)
    {
        int m = INT32_MAX;
        node *temp = head;
        while (temp != nullptr)
        {
            m = __min(m, temp->data);
            temp = temp->next;
        }
        return m;
    }
    void insertAtHead(int data)
    {
        if (head == nullptr)
        {
            head = head->create_node(data);
            tail = head;
            return;
        }
        node *temp = temp->create_node(data);
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    void insertAtTail(int data)
    {
        if (head == nullptr)
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
    void insertAtPos(int data, int pos)
    {
        if (pos < 1)
        {
            std::cout << "Invalid_position\n";
            return;
        }
        else if (pos == 1)
        {
            insertAtHead(data);
            return;
        }
        node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            std::cout << "out of range\n";
            return;
        }
        else if (temp->next == nullptr)
        {
            insertAtTail(data);
            return;
        }
        node *new_node = new_node->create_node(data);
        new_node->next = temp->next;
        temp->next->prev = new_node;
        new_node->prev = temp;
        temp->next = new_node;
    }
    void deleteAtHead(void){
        if(head == nullptr){
            std::cout<<"LinkedList is empty\n";
            return;
        }
        node *temp = head;
        head = temp->next;
        head->prev = nullptr;
        delete temp;
    }
    void deleteAtTail(void){
        if(head == nullptr){
            std::cout<<"LinkedList is empty\n";
            return;
        }
        node *temp = tail;
        tail = temp->prev;
        tail->next = nullptr;
        delete temp;
    }
    void deletaAtPos(int pos){
        if(pos<1){
            std::cout<<"Invalid Position\n";
        }
        else if(pos == 1){
            deleteAtHead();
            return;
        }
        node *temp = head;
        for(int i=1 ; i<pos && temp!=nullptr;i++){
            temp = temp->next;
        }
        if(temp == nullptr){
            std::cout<<"out of range\n";
            return;
        }
        else if(temp->next == nullptr){
            deleteAtTail();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
};
int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};
    DLL d1(arr, 5);
    d1.dispaly();
    std::cout << "\nthe count of nodes = " << d1.count() << std::endl;
    std::cout << "the sum of data = " << d1.sum() << std::endl;
    std::cout << "The max = " << d1.max() << "\nThe min = " << d1.min() << std::endl;
    d1.insertAtHead(5);
    d1.dispaly();
    d1.insertAtTail(60);
    std::cout << "\n";
    d1.dispaly();
    d1.insertAtPos(65, 8);
    std::cout << "\n";
    d1.dispaly();
    d1.deleteAtHead();
    std::cout << "\n";
    d1.dispaly();
    d1.deleteAtTail();
    std::cout << "\n";
    d1.dispaly();
    d1.deletaAtPos(4);
    std::cout << "\n";
    d1.dispaly();
}
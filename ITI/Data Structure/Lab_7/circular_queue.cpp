#include <iostream>
class c_queue
{
private:
    int *arr_ptr;
    int size;
    int capacity;
    int front;
    int rear;

public:
    c_queue(int c)
    {
        arr_ptr = new int[c];
        capacity = c;
        size = 0;
        front = -1;
        rear = -1;
    }
    bool is_empty(void)
    {
        return (size == 0);
    }
    bool is_full(void)
    {
        return (size == capacity);
    }
    void enqueue(int data)
    {
        if (is_empty())
        {
            rear++;
            arr_ptr[rear] = data;
            front++;
            size++;
            return;
        }
        else if (is_full())
        {
            std::cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr_ptr[rear] = data;
        size++;
    }
    int dequeue(void)
    {
        if (is_empty())
        {
            std::cout << "Queue is empty\n";
            return -1;
        }
        int data = arr_ptr[front];
        size--;
        front = (front + 1) % capacity;
        return data;
    }
    void display(void)
    {
        int temp_index = front;
        while (temp_index != (rear+1)%capacity)
        {
            std::cout << arr_ptr[temp_index] << " ";
            temp_index = (temp_index+1)%capacity;
        }
        std::cout << std::endl;
    }
    int get_front(void)
    {
        return arr_ptr[front];
    }
    int get_rear(void)
    {
        return arr_ptr[rear];
    }
    int get_size(void)
    {
        return size;
    }
    ~c_queue()
    {
        delete arr_ptr;
        std::cout << "queue is deleted";
    }
};
int main(void)
{
    int data = 0;
    int c = 10;
    c_queue q(c);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    data = q.dequeue();
    std::cout << data << "\n";
    data = q.dequeue();
    std::cout << data << "\n";
    data = q.dequeue();
    std::cout << data << "\n";
    q.display();
    data = q.get_front();
    std::cout << data << "\n";
    data = q.get_rear();
    std::cout << data << "\n";
    data = q.get_size();
    std::cout << data << "\n";
}
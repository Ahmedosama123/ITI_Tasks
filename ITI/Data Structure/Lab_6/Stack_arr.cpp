#include<iostream>
class stack{
    private:
    int *arr;
    int capacity;
    int top;
    public:
    stack(int c):capacity{c}{
        arr = new int[c];
        top = -1;
    }
    bool is_full(){
        return (top == capacity-1);
    }
    bool is_empty(){
        return (top == -1);
    }
    int size(){
        return top+1;
    }
    void display(void){
        if(is_empty()){
            std::cout<<"stack is empty\n";
        }
        for(int i = 0 ; i < size();i++){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<"\n";
    }
    void push(int data){
        if(is_full()){
            std::cout<<"stack is full\n";
            return;
        }
        arr[++top]=data;
    }
    int pop(){
        int data;
        if(is_empty()){
            std::cout<<"stack is empty\n";
            return -1;
        }
        data = arr[top--];
        return data;
    }
    int peak(){
        return arr[top];
    }
};
int main(void){
    int data = 0;
    stack s1(10);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.display();
    data = s1.pop();
    s1.display();
    std::cout<<data<<std::endl;
    data = s1.peak();
    s1.display();
    std::cout<<data<<std::endl;
}
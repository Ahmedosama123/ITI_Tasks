
#include <iostream>
#include <vector>
#include <algorithm>

class MaxHeap
{
private:
    std::vector<int> heap;

    void heap_up(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (heap[index] > heap[parent])
            {
                std::swap(heap[index], heap[parent]);
                index = parent;
            }
            else
                break;
        }
    }

    void heap_down(int index)
    {
        int size = heap.size();

        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == index)
                break;

            std::swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:

    void insert(int value)
    {
        heap.push_back(value);
        heap_up(heap.size() - 1);
    }
    int get_max() const
    {
        if (heap.empty())
            throw std::runtime_error("Heap is empty");

        return heap[0];
    }
    void delete_element(int value)
    {
        int index = -1;

        for (int i = 0; i < heap.size(); i++)
        {
            if (heap[i] == value)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
            return;

        heap[index] = heap.back();
        heap.pop_back();

        if (index < heap.size())
        {
            int parent = (index - 1) / 2;

            if (index > 0 && heap[index] > heap[parent])
                heap_up(index);
            else
                heap_down(index);
        }
    }
    bool search(int value) const
    {
        for (int element : heap)
        {
            if (element == value)
                return true;
        }

        return false;
    }
    void display() const
    {
        for (int element : heap)
            std::cout << element << " ";

        std::cout << '\n';
    }
    bool empty() const
    {
        return heap.empty();
    }
    int size() const
    {
        return heap.size();
    }
};

int main()
{
    MaxHeap h;

    h.insert(10);
    h.insert(40);
    h.insert(20);
    h.insert(60);
    h.insert(30);
    h.insert(50);

    std::cout << "Heap: ";
    h.display();
    std::cout << "Max: " << h.get_max() << '\n';

    std::cout << "After extraction: ";
    h.display();

    h.delete_element(20);

    std::cout << "After removing 20: ";
    h.display();
    std::cout << "Search 40: "
              << (h.search(40) ? "Found" : "Not Found")
              << '\n';
    std::cout << "Heap size: " << h.size() << '\n';

    return 0;
}

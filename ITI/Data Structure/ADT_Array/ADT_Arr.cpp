#include <iostream>
class Array
{
private:
    int *ptr;
    int size;
    int capacity;

public:
    Array(int *arr, int s, int c)
    {
        ptr = arr;
        size = s;
        capacity = c;
    }
    int *get_ptr()
    {
        return ptr;
    }
    int get_size()
    {
        return size;
    }
    int get_capacity()
    {
        return capacity;
    }
    void display(void)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << ptr[i] << " ";
        }
        std::cout << std::endl;
    }
    void append(int element)
    {
        if (size == capacity)
        {
            int *newptr = new int[capacity * capacity];
            capacity *= 2;
            for (int i = 0; i < size; i++)
            {
                newptr[i] = ptr[i];
            }
            delete (ptr);
            ptr = newptr;
        }
        ptr[size++] = element;
    }
    void insert(int element, int index)
    {
        if (index >= size || index < 0)
        {
            std::cout << "Invalid Index\n";
            return;
        }
        if (size == capacity)
        {
            int *newptr = new int[capacity * capacity];
            capacity *= 2;
            for (int i = 0; i < size; i++)
            {
                newptr[i] = ptr[i];
            }
            delete[] ptr;
            ptr = newptr;
        }
        for (int i = capacity - 2; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = element;
        size++;
    }
    void Delete(int index)
    {
        if (index >= size || index < 0)
        {
            std::cout << "Invalid Index\n";
            return;
        }
        for (int i = index; i < size; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        ptr[--size] = 0;
    }
    void search(int element)
    {
        int is_found = 0;
        for (int i = 0; i < size; i++)
        {
            if (ptr[i] == element)
            {
                std::cout << element << "is found in index:" << i << std::endl;
                is_found = 1;
                break;
            }
        }
        if (is_found == 0)
        {
            std::cout << element << " is not found" << std::endl;
        }
    }
    int get(int index)
    {
        if (index >= size || index < 0)
        {
            std::cout << "Invalid Index\n";
            return 0;
        }
        return ptr[index];
    }
    void set(int index, int element)
    {
        if (index >= size || index < 0)
        {
            std::cout << "Invalid Index\n";
            return;
        }
        ptr[index] = element;
    }
    void maximum(void)
    {
        int max = -1000000;
        for (int i = 0; i < size; i++)
        {
            if (ptr[i] > max)
            {
                max = ptr[i];
            }
        }
        std::cout << "The maximum element = " << max << std::endl;
    }
    void minimum(void)
    {
        int min = 1000000;
        for (int i = 0; i < size; i++)
        {
            if (ptr[i] < min)
            {
                min = ptr[i];
            }
        }
        std::cout << "The minimum element = " << min << std::endl;
    }
    void reverse(void)
    {
        int temp = 0;
        for (int i = 0; i < size / 2; i++)
        {
            temp = ptr[i];
            ptr[i] = ptr[size - i - 1];
            ptr[size - i - 1] = temp;
        }
    }
    void shift_right(int countsOfShifts)
    {
        for (int j = 0; j < countsOfShifts; j++)
        {
            for (int i = size - 2; i >= 0; i--)
            {
                ptr[i + 1] = ptr[i];
            }
        }
        for (int j = 0; j < countsOfShifts; j++)
        {
            ptr[j] = 0;
        }
    }
    void shift_left(int countsOfShifts)
    {
        for (int j = 0; j < countsOfShifts; j++)
        {
            for (int i = 0; i < size - 1; i++)
            {
                ptr[i] = ptr[i + 1];
            }
        }
        for (int j = size - 1; j > size - countsOfShifts - 1; j--)
        {
            ptr[j] = 0;
        }
    }
    void rotate_right(int countsOfRotates)
    {
        int arr[countsOfRotates];
        for (int w = 0; w < countsOfRotates; w++)
        {
            arr[w] = ptr[size - w - 1];
        }
        for (int j = 0; j < countsOfRotates; j++)
        {
            for (int i = size - 2; i >= 0; i--)
            {
                ptr[i + 1] = ptr[i];
            }
        }
        for (int j = 0; j < size - countsOfRotates - 1; j++)
        {
            ptr[countsOfRotates - 1 - j] = arr[j];
        }
    }
    void rotate_left(int countsOfRotates)
    {
        int arr[countsOfRotates];
        for (int w = 0; w < countsOfRotates; w++)
        {
            arr[w] = ptr[w];
        }
        for (int j = 0; j < countsOfRotates; j++)
        {
            for (int i = 0; i < size - 1; i++)
            {
                ptr[i] = ptr[i + 1];
            }
        }
        for (int j = size - countsOfRotates; j < size; j++)
        {
            ptr[j] = arr[j - (size - countsOfRotates)];
        }
    }
    void merge(int *a, int s1)
    {
        if (s1 + size > capacity)
        {
            int *newptr = new int[capacity * capacity];
            capacity *= 2;
            for (int i = 0; i < size; i++)
            {
                newptr[i] = ptr[i];
            }
            delete (ptr);
            ptr = newptr;
        }
        for (int i = size; i < size + s1 ; i++)
        {
            ptr[i] = a[i - size];
        }
        size+=s1;
    }
    int sum(void)
    {
        int summation = 0;
        for (int i = 0; i < size; i++)
        {
            summation += ptr[i];
        }
        return summation;
    }
    float average(void)
    {
        int sumOfElements = this->sum();
        return ((float)sumOfElements / (float)size);
    }
    void replace(int index1, int index2)
    {
        if (index1 >= size || index1 < 0)
        {
            std::cout << "Invalid Index1\n";
            return;
        }
        if (index2 >= size || index2 < 0)
        {
            std::cout << "Invalid Index2\n";
            return;
        }
        int temp = 0;
        temp = ptr[index1];
        ptr[index1] = ptr[index2];
        ptr[index2] = temp;
    }
};
int main(void)
{
    int s1 = 0;
    int a1[s1];
    int element = 0;
    int index = 0;
    int index1 = 0;
    int choise = 0;
    int s = 0;
    int c = 0;
    std::cout << "Enter the size :";
    std::cin >> s;
    std::cout << "Enter the capacity :";
    std::cin >> c;
    int *arr = new int[c];
    std::cout << "Enter the array elements : ";
    for (int i = 0; i < s; i++)
    {
        std::cin >> arr[i];
    }
    Array *array = new Array(arr, s, c);
    while (1)
    {
        std::cout << "          Array Menu\n";
        std::cout << "1-Dispaly Array.\n"
                  << "2-Add Element.\n"
                  << "3-Insert Element.\n"
                  << "4-Delete Element.\n"
                  << "5-Search Element.\n"
                  << "6-Get Element.\n"
                  << "7-Set Element.\n"
                  << "8-Get Maximum.\n"
                  << "9-Get minimum.\n"
                  << "10-Reverse Array.\n"
                  << "11-Shift Right.\n"
                  << "12-Shift Left.\n"
                  << "13-Rotate Right.\n"
                  << "14-Rotate Left.\n"
                  << "15-Merge with An Array.\n"
                  << "16-Sum the Elements.\n"
                  << "17-Get The average of the elements.\n"
                  << "18-Replace two elements.\n"
                  << "0-Exit.\n";
        std::cout << "Enter your choise :";
        std::cin >> choise;
        switch (choise)
        {
        case 1:
            array->display();
            break;
        case 2:
            std::cout << "Enter the element:";
            std::cin >> element;
            array->append(element);
            break;
        case 3:
            std::cout << "Enter the element:";
            std::cin >> element;
            std::cout << "Enter the index:";
            std::cin >> index;
            array->insert(element, index);
            break;
        case 4:
            std::cout << "Enter the index:";
            std::cin >> index;
            array->Delete(index);
            break;
        case 5:
            std::cout << "Enter the element:";
            std::cin >> element;
            array->search(element);
            break;
        case 6:
            std::cout << "Enter the Index:";
            std::cin >> index;
            std::cout << array->get(index) << std::endl;
            break;
        case 7:
            std::cout << "Enter the element:";
            std::cin >> element;
            std::cout << "Enter the index:";
            std::cin >> index;
            array->set(index, element);
            break;
        case 8:
            array->maximum();
            break;
        case 9:
            array->minimum();
            break;
        case 10:
            array->reverse();
            break;
        case 11:
            std::cout << "Enter the index: ";
            std::cin >> index;
            array->shift_right(index);
            break;
        case 12:
            std::cout << "Enter the index: ";
            std::cin >> index;
            array->shift_left(index);
            break;
        case 13:
            std::cout << "Enter the index: ";
            std::cin >> index;
            array->rotate_right(index);
            break;
        case 14:
            std::cout << "Enter the index: ";
            std::cin >> index;
            array->rotate_left(index);
            break;
        case 15:
            std::cout << "Enter the size of the second array : ";
            std::cin >> s1;
            std::cout << "Enter the second array elements : ";
            for (int i = 0; i < s1; i++)
            {
                std::cin >> a1[i];
            }
            array->merge(a1,s1);
            break;
            case 16:
            std::cout << "The summation of the array elements = " << array->sum() << std::endl;
            break;
            case 17:
            std::cout << "The average of the array elements = " << array->average() << std::endl;
            break;
            case 18:
            std::cout<<"Enter Index 1 :";
            std::cin>>index;
            std::cout<<"Enter Index 2 :";
            std::cin>>index1;
            array->replace(index,index1);
            break;
        default:
            return 0;
        }
    }
}
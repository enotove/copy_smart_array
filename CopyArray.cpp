#include <iostream>

class Smart_array {
public:
    Smart_array(int a)
    {
        arr = new int[a];
        size = a;
    }

    void add_element(int value)
    {
        if (arr == nullptr)
        {
            throw std::exception("You're not make the array!");
        }
        else if (counter == size)
        {
            throw std::exception("You fill in the array, that's enough");
        }
        arr[counter] = value;
        counter++;

    }
    int get_element(int index)
    {
        if (index >= counter || index < 0)
        {
            throw std::exception("Going outside the array");
        }
        return arr[index];
    }
    Smart_array& operator = (Smart_array &array)
    {
        
        this->arr = new int[array.size];
        this->size = array.size;
        this->counter = array.counter;
        for (int i = 0; i < array.size; i++)
        {
            arr[i] = *(array.arr + i);
        }
        array.~Smart_array();
        return *this;
    }
    void Print_elements()
    {
        std::cout << "Elements in the array: ";
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << '\n';
    }
    ~Smart_array()
    {
        if (arr != nullptr)
        {
            delete[] arr;
            counter = 0;
            arr = nullptr;
        }
    }


private:
    int* arr{ nullptr };
    int counter = 0;
    int size;

};

int main()
{
    Smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    Smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;
    arr.Print_elements();
}

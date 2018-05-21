#include <iostream>

using namespace std;    

template <class T>
class Vector
{
private:
    T *data_;
    int size_;
    int capacity_;

public:
    Vector()
    {
        size_ = 0;
        capacity_ = 4;
        data_ = new T[capacity_];
    }

    ~Vector() { delete[] data_; }

    bool empty() { return size_ == 0; }

    int size() { return size_; }

    void push_back(T val)
    {
        if (size_ == capacity_)
        {
            T *tmp = new T[capacity_ * 2];
            for (int i = 0; i < size_; i++)
                tmp[i] = data_[i];
            capacity_ *= 2;
            delete[] data_;
            data_ = tmp;
        }
        data_[size_] = val;
        ++size_;
    }

    void pop_back() { --size_; }

    T back() { return data_[size_ - 1]; }

    T get_value(T i) { return data_[i]; }

    void set_value(int i, T val) { data_[i] = val; }

    void swap(int i, int j)
    {
        T tmp = data_[i];
        data_[i] = data_[j];
        data_[j] = tmp;
    }
};

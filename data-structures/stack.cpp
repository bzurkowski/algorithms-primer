template <class T>
class Stack
{
private:
    Vector<T> data_;

public:
    Stack(){};

    void push(T val) { data_.push_back(val); }

    T top() { return data_.back(); }

    void pop() { data_.pop_back(); }

    int size() { return data_.size(); }

    bool empty() { return data_.empty(); }
};

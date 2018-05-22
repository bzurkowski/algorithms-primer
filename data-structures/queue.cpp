template <class T>
class Queue
{
  private:
    Vector<T> data_;
    int front_;

  public:
    Queue() { front_ = 0; }

    bool empty() { return size() == 0; }

    int size() { return data_.size() - front_; }

    void push_back(T val) { data_.push_back(val); }

    void pop_front() { ++front_; }

    T front() { return data_.get_value(front_); }
};

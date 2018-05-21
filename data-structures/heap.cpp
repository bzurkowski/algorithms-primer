template <class T>
class Comparator {
public:
	bool compare(T e1, T e2);
};

class ComparatorInt {
public:
	bool compare(int a, int b) { return a < b; }
};

template <class T, class Comparator>
class Heap
{
private:
    Comparator cmp_;
    Vector<T> data_;

    void heap_up(int id)
    {
        if (id == 1) return;
        int parent_id = id / 2;
        if (cmp_.compare(data_.get_value(parent_id), data_.get_value(id))) return;
        data_.swap(id, parent_id);
        heap_up(parent_id);
    }

    void heap_down(int id)
    {
        // no left son => no sons at all
        int left_son_id = id * 2;
        if (left_son_id > size()) return;
    
        // no right son => left son only
        int right_son_id = id * 2 + 1;
        if (right_son_id > size())
        {
            if (cmp_.compare(data_.get_value(left_son_id), data_.get_value(id))) {
                data_.swap(id, left_son_id);
                return heap_down(left_son_id);
            }
            return;
        }

        // both sons are present
        int better_son_id = left_son_id;
        if (cmp_.compare(data_.get_value(right_son_id), data_.get_value(left_son_id))) {
            better_son_id = right_son_id;
        }
        if (cmp_.compare(data_.get_value(better_son_id), data_.get_value(id))) {
            data_.swap(id, better_son_id);
            return heap_down(better_son_id);
        }
    }

public:
    Heap() { data_.push_back(T()); }

    bool empty() { return data_.empty(); }

    int size() { return data_.size() - 1; }

    void push(T val)
    {
        data_.push_back(val);
        int id = size();
        heap_up(id);
    }

    T top() { return data_.get_value(1); }

    void pop() {
        data_.set_value(1, data_.back());
        data_.pop_back();
        heap_down(1);
    }
};

int main() {
    Heap<int, ComparatorInt> my_heap;

    int sample[10] = { 2, 1, 4, 19, 4, 3, 8, 21, 29, 15 };

    for (int i = 0; i < 10; i++)
        my_heap.push(sample[i]);

    for (int i = 0; i < 10; i++) {
        cout << my_heap.top() << " ";
        my_heap.pop();
    }
    cout << endl;

    return 0;
}
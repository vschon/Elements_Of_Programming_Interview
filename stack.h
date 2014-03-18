//template the header and implementation should be in the same file.
#include <list>

template<typename T>
class Stack {
public:
    Stack(){};
    void clear() {
        stackList.clear();
    }
    bool isEmpty() const {
        return stackList.empty();
    }
    void push(T info_) {
        stackList.push_back(info_);
    }
    T pop() {
        T temp = stackList.back();
        stackList.pop_back();
        return temp;
    }
    T peek() {
        return stackList.back();
    }
private:
    std::list<T> stackList;
};


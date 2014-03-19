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
        if (isEmpty()) {
            pair<T, T> temp(info_, info_);
            stackList.push_back(temp);
        }
        else {
            pair<T, T> temp = stackList.back();
            T runningMax = temp.second;
            runningMax = (info_ > runningMax ? info_ : runningMax);
            pair<T, T> pairInfo(info_, runningMax); 
            stackList.push_back(pairInfo);
        }
    }

    T pop() {
        pair<T, T> temp = stackList.back();
        stackList.pop_back();
        return temp.first;
    }

    T peek() {
        pair<T, T> temp = stackList.back();
        return temp.first;
    }
    
    T max() {
        if(isEmpty())
            throw("Empty");
        pair<T, T> temp = stackList.back();
        T max = temp.second;
        return max;
    }
    
private:
    std::list<pair<T,T> > stackList;
};


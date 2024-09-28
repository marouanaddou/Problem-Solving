

# include <iostream>
# include <vector>

using namespace std;


class MyCircularDeque {
public:
    std::vector<int> deque;
    int k;
    int size;
    MyCircularDeque(int k) {
        this->k = k;
        size = 0;
    }
    
    bool insertFront(int value) {
        if (size == k) return false;
        deque.insert(deque.begin(), value);
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (size == k) return false;
        deque.push_back(value);
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())
            return false;
        deque.erase(deque.begin());
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())
            return false;
        deque.erase(deque.begin() + size);
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty())
            return -1;
        return deque[0];
    }
    
    int getRear() {
        if (isEmpty())
            return -1;
        return deque[size - 1];
    }
    
    bool isEmpty() {
        if (size == 0) return true;
        return false;
    }
    
    bool isFull() {
        if (size == this->k) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
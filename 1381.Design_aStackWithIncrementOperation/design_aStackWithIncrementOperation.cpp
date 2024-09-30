
# include <iostream>
# include <vector>

using namespace std;



class CustomStack {
public:
    int *stack;
    int maxSize;
    int size;
    CustomStack(int maxSize) {
        stack = new int[maxSize];
        this->maxSize = maxSize;
        size = 0;
    }
    
    void push(int x) {
        if (size < maxSize) {
            stack[size] = x;
            size++;
        }
    }
    
    int pop() {
        if (size == 0) return -1;
        int last = stack[size - 1];
        size--;
        return last;
    }
    
    void increment(int k, int val) {
        if (k > size) k = size;
        for (int i = 0; i < k; i++) {
            stack[i] += val;
        }
    }
};

// class CustomStack {
// public:
//     std::vector<int > stack;
//     int maxSize;
//     int size;
//     CustomStack(int maxSize) {
//         this->maxSize = maxSize;
//         size = 0;
//     }
    
//     void push(int x) {
//         if (size < maxSize) {
//             stack.push_back(x);
//             size++;
//         }
//     }
    
//     int pop() {
//         if (size == 0) return -1;
//         int last = stack[size - 1];
//         stack.erase(stack.begin() + size);
//         size--;
//         return last;
//     }
    
//     void increment(int k, int val) {
//         if (k > size) k = size;
//         for (int i = 0; i < k; i++) {
//             stack[i] += val;
//         }
//     }
// };

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
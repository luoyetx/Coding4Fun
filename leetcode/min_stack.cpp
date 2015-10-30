#include <vector>
#include <limits>

class MinStack {
public:
    MinStack() {
        min_.push_back(std::numeric_limits<int>::max());
    }

    void push(int x) {
        stack_.push_back(x);
        if (x <= min_.back()) {
            min_.push_back(x);
        }
    }

    void pop() {
        int x = top();
        stack_.pop_back();
        if (min_.back() == x) {
            min_.pop_back();
        }
    }

    int top() {
        return stack_.back();
    }

    int getMin() {
        return min_.back();
    }

private:
    std::vector<int> stack_;
    std::vector<int> min_;
};

#include <iostream>
#include <vector>
#include <stack>

int main() {
    std::vector<int> arr = {4, 5, 2, 10, 8};
    int size = arr.size();

    std::vector<int> v;
    std::stack<int> s;

    for (int i = size - 1; i >= 0; i--) {
        if (s.size() == 0) {
            v.push_back(-1);
        } else if (s.size() > 0 && s.top() > arr[i]) {
            v.push_back(s.top());
        } else if (s.size() > 0 && s.top() <= arr[i]) {
            while (s.size() > 0 && s.top() <= arr[i]) {
                s.pop();
            } 
            if (s.size() == 0) {
                v.push_back(-1);
            } else {
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }


    for (int i = v.size() - 1; i >= 0; i--) {
        std::cout << v[i] << " ";
    }

    return 0;
}

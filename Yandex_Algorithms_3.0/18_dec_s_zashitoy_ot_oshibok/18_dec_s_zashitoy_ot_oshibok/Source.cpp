#include <vector>
#include <set>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

template <typename T>
class Deque {
private:
    vector<T> head, tail;
public:

    size_t Size() const {
        return head.size() + tail.size();
    }

    T Front() {
        return head.empty() ? tail.front() : head.back();
    }

    T Back() {
        return tail.empty() ? head.front() : tail.back();
    }

    void PushFront(const T& elem) {
        head.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail.push_back(elem);
    }

    T PopFront() {
        T z = 0;
        if (head.empty()) {
            z = tail.front();
            tail.erase(tail.begin());
        }
        else {
            z = head.back();
            head.pop_back();
        }
        return z;
    }

    T PopBack() {
        T z = 0;
        if (tail.empty()) {
            z = head.front();
            head.erase(head.begin());
        }
        else {
            z = tail.back();
            tail.pop_back();
        }
        return z;
    }

    void Clear() {
        head.clear();
        tail.clear();
    }
};

int main() {
    Deque<int> d;
    string command_line;
    while (getline(cin, command_line)) {
        stringstream ss(command_line);

        string command;
        int date_str;
        ss >> command;

        if (command == "push_front") {
            ss >> date_str;
            d.PushFront(date_str);
            cout << "ok" << endl;
        }
        else if (command == "push_back") {
            ss >> date_str;
            d.PushBack(date_str);
            cout << "ok" << endl;
        }
        else if (command == "pop_front") {
            if (d.Size() == 0) {
                cout << "error" << endl;
            }
            else {
                cout << d.PopFront() << endl;
            }
        }
        else if (command == "pop_back") {
            if (d.Size() == 0) {
                cout << "error" << endl;
            }
            else {
                cout << d.PopBack() << endl;
            }
        }
        else if (command == "front") {
            if (d.Size() == 0) {
                cout << "error" << endl;
            }
            else {
                cout << d.Front() << endl;
            }
        }
        else if (command == "back") {
            if (d.Size() == 0) {
                cout << "error" << endl;
            }
            else {
                cout << d.Back() << endl;
            }
        }
        else if (command == "size") {
            cout << d.Size() << endl;
        }
        else if (command == "clear") {
            d.Clear();
            cout << "ok" << endl;
        }
        else if (command == "exit") {
            cout << "bye";
            break;
        }
    }


    return 0;
}

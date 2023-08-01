#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class my_queue {
public:
    // конструктор выбрасывает исключение, если его аргументы некорректны
    my_queue() {

    }

    string push(int& n) {
        queue.push_back(n);
        return "ok";
    }

    int size() {
        return queue.size();
    }

    int pop() {
        int n = *queue.begin();
        queue.erase(queue.begin());
        return n;
    }

    int front() {
        return *queue.begin();
    }

    string clear() {
        queue.clear();
        return "ok";
    }

    string exit() {
        return "bye";
    }

private:
    vector<int> queue;
};


int main() {
    my_queue q;
    string command_line;
    while (getline(cin, command_line)) {
        stringstream ss(command_line);

        string command;
        int date_str;
        ss >> command;

        if (command == "push") {
            ss >> date_str;
            cout << q.push(date_str) << endl;
        }
        else if (command == "pop") {
            if (q.size() == 0) {
                cout << "error" << endl;
            }
            else {
                cout << q.pop() << endl;
            }
        }
        else if (command == "front") {
            if (q.size() == 0) {
                cout << "error" << endl;
            }
            else {
                cout << q.front() << endl;
            }
        }
        else if (command == "size") {
            cout << q.size() << endl;
        }
        else if (command == "clear") {
            cout << q.clear() << endl;
        }
        else if (command == "exit") {
            cout << q.exit();
            break;
        }
        else if (!command.empty()) {

            //throw logic_error("Unknown command: " + command);

        }
    }


    return 0;
}
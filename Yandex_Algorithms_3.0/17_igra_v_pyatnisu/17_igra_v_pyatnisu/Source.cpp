#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int main() {
    queue<int> first;
    queue<int> second;
    int k = 0;
    //ввод данных
    for (int i = 0; i < 10; i++) {
        cin >> k;
        if (i < 5) {
            first.push(k);
        }
        else {
            second.push(k);
        }
    }

    int sec = 0;
    //анализ данных
    while (sec <= 1000000) {
        if ((second.front() == 0 && first.front() == 9) || (first.front() == 0 && second.front() == 9)) {
            if (second.front() == 0) {
                second.push(first.front());
                second.push(second.front());
            }
            else {
                first.push(first.front());
                first.push(second.front());
            }
        }
        else {
            if (second.front() > first.front()) {
                second.push(first.front());
                second.push(second.front());
            }
            else {
                first.push(first.front());
                first.push(second.front());
            }

        }
        second.pop();
        first.pop();
        sec++;

        if (second.size() == 0) {
            cout << "first " << sec;
            return 0;
        }
        if (first.size() == 0) {
            cout << "second " << sec;
            return 0;
        }

    }

    cout << "botva";



    //вывод данных
    /*
    int fs = first.size();
    for (int f = 0; f < fs;f++) {
        cout << first.front();
        first.pop();
    }
    int ss = second.size();
    for (int s = 0; s < ss; s++) {
        cout << second.front();
        second.pop();
    }
    */
    return 0;
}
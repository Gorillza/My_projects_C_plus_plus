#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Date {
public:
    // конструктор выбрасывает исключение, если его аргументы некорректны
    Date(int new_hours, int new_min, int new_sec) {
        hours = new_hours;
        min = new_min;
        sec = new_sec;
        time = hours * 60 * 60 + min * 60 + sec;
    }

    int GetHours() const {
        return hours;
    }
    int GetMin() const {
        return min;
    }
    int GetSec() const {
        return sec;
    }
    int GetTime() const {
        return time;
    }

private:
    int hours;
    int min;
    int sec;
    int time;
};

// определить сравнение для дат необходимо для использования их в качестве ключей словаря
bool operator<(const Date& lhs, const Date& rhs) {
    // воспользуемся тем фактом, что векторы уже можно сравнивать на <:
    // создадим вектор из года, месяца и дня для каждой даты и сравним их
    return vector<int>{lhs.GetHours(), lhs.GetMin(), lhs.GetSec()} <
        vector<int>{rhs.GetHours(), rhs.GetMin(), rhs.GetSec()};
}

// даты будут по умолчанию выводиться в нужном формате
ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(2) << setfill('0') << date.GetHours() <<
        ":" << setw(2) << setfill('0') << date.GetMin() <<
        ":" << setw(2) << setfill('0') << date.GetSec();
    return stream;
}


Date ParseDate(string& date) {
    istringstream date_stream(date);
    bool ok = true;

    int hours;
    ok = ok && (date_stream >> hours);
    ok = ok && (date_stream.peek() == ':');
    date_stream.ignore(1);

    int min;
    ok = ok && (date_stream >> min);
    ok = ok && (date_stream.peek() == ':');
    date_stream.ignore(1);

    int sec;
    ok = ok && (date_stream >> sec);
    ok = ok && date_stream.eof();

    return Date(hours, min, sec);
}

Date ParseSec(int& real_time) {
    while (real_time > 86400) {
        real_time = real_time - 86400;
    }
    int hours = real_time / 3600;
    int ostatok_1 = real_time - hours * 3600;
    int min = ostatok_1/60;
    int sec = ostatok_1 - min * 60;
    return Date(hours, min, sec);
}

int main() {
    string date_str;
    string command_line;
    int one_day = 24 * 60 * 60;
    int spend_time = 0;
    int real_time = 0;
    //ЗАБРАЛИ ПЕРВОЕ ВРЕМЯ А
    getline(cin, command_line);
    stringstream ss(command_line);
    ss >> date_str;
    Date date_A = ParseDate(date_str);

    //ЗАБРАЛИ ПЕРВОЕ ВРЕМЯ B
    getline(cin, command_line);
    stringstream ss1(command_line);
    ss1 >> date_str;
    Date date_B = ParseDate(date_str);
    
    //ЗАБРАЛИ ПЕРВОЕ ВРЕМЯ C
    getline(cin, command_line);
    stringstream ss2(command_line);
    ss2 >> date_str;
    Date date_C = ParseDate(date_str);

    if (date_C < date_A) {
        spend_time = one_day - date_A.GetTime() + date_C.GetTime();
        if (spend_time % 2 == 1) {
            spend_time = spend_time / 2 + 1;
        }
        else {
            spend_time = spend_time / 2;
        }
        real_time = date_B.GetTime() + spend_time;
    }
    else {
        spend_time = date_C.GetTime() - date_A.GetTime();
        if (spend_time % 2 == 1) {
            spend_time = spend_time / 2 + 1;
        }
        else {
            spend_time = spend_time / 2;
        }
        real_time = date_B.GetTime() + spend_time;
    }

    cout << ParseSec(real_time);
    return 0;
}
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

// test 1 : fheriherffazfszkisrrs       answer 2 
// test 2 : rifftratatashe              answer 1
// test 3 : sheriffsheriffsheriff       answer 3
// test 4 : sherifsherifsherif          answer 1
// test 5 : sherifsherifsherifsherif    answer 2

int main() {
    char s;
    
    unordered_map<char, long long>m;
    while (cin>>s) {//записали каждое число вхождений 
        m[s]++;
    }

    long long min_one_char = 2000000000;
    string l = "sheri";
    for (auto i : l) {
        min_one_char = min(min_one_char, m[i]);
    }

    //теперь в переменной мы знаем минимальное количество
    // слов из букв одинарных которые мы собрали

    long long ff = m['f'];
    // теперт в ff записано число символов f

    if (ff <= 1 || min_one_char == 0) {// обработка невозможности составить
        cout << 0;
        return 0;
    }

    if (ff % 2 == 0) {//если число четное делим на два
        ff = ff / 2;
    }
    else {// если число не четное то вычитаем 1 и делим на два
        --ff;
        ff = ff / 2;
    }
    // теперь в ff написано число слов которое мы можем дополнить двумя ff

    cout << min(ff, min_one_char);
    return 0;
}
#include <stdio.h>
#include <iostream> 
#include <stack>
using namespace std;

string command;
int count1 = 0;
int chek = 0;
int kolvo_el = 0;

int main()
{
    stack <int> arr1;
    command = "00";
    while (command != "exit")
    {
        cin >> command;
        if (command == "push")
        {
            cin >> count1;
            arr1.push(count1);
            cout << "ok" << endl;
            kolvo_el++;
            //chek=arr1.top();
            //cout<<"count ="<<chek<<endl;
        }
        if (command == "pop")
        {
            if (kolvo_el > 0)
            {
                chek = arr1.top();
                arr1.pop();
                cout << chek << endl;
                kolvo_el--;
            }
            else
            {
                cout << "error" << endl;
            }
        }
        if (command == "back")
        {
            if (kolvo_el > 0)
            {
                chek = arr1.top();
                cout << chek << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }
        if (command == "size")
        {
            cout << kolvo_el << endl;
        }
        if (command == "clear")
        {
            while (kolvo_el != 0)
            {
                arr1.pop();
                kolvo_el--;
            }
            cout << "ok" << endl;
        }



    }
    cout << "bye" << endl;
}

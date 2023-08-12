#include <stdio.h>
#include <iostream> 
#include <stack>
using namespace std;

int sravn(char s, char chekk)
{
    char a1 = '[';
    char b1 = '(';
    char c1 = '{';
    char a2 = ']';
    char b2 = ')';
    char c2 = '}';
    if ((s == a2) && (chekk == a1))
    {
        return 0;

    }
    else if ((s == b2) && (chekk == b1))
    {
        return 0;
    }
    else if ((s == c2) && (chekk == c1))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

string s1;
int count1 = 0;
//stack string steck;
char a1 = '[';
char b1 = '(';
char c1 = '{';
char a2 = ']';
char b2 = ')';
char c2 = '}';

char chekk;
int fail = 0;

int main()
{
    stack <char> arr1;
    cin >> s1;
    for (int i = 0; i < s1.size(); i++)
    {
        if ((s1[i] == a1) || (s1[i] == b1) || (s1[i] == c1))
        {
            arr1.push(s1[i]);
            count1++;
        }
        if ((s1[i] == a2) || (s1[i] == b2) || (s1[i] == c2))
        {
            count1--;
            if (count1 < 0)
            {
                fail = 1;
                break;
            }
            chekk = arr1.top();
            fail = sravn(s1[i], chekk);
            if (fail == 1)
            {
                break;
            }
            arr1.pop();

        }
    }
    if (count1 != 0)
    {
        fail = 1;
    }
    if (fail == 0)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    //cout<<count; 
}

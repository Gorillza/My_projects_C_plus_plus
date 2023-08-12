#include <stdio.h>
#include <iostream> 
#include <stack>
using namespace std;

string s1="0";
char a='+';
char b='-';
char c='*';
int k=1;
int j=0;

int arg1=0;
int arg2=0;

int chek1=0;
int outlast=0;

int prefics_fc(char s, int a1, int a2)
{
    char a='+';
    char b='-';
    char c='*';
    int out=0;
    if (s==a)
    {
        out=a1+a2;  
    }
    if (s==b)
    {
        out=a2-a1;  
    }
    if (s==c)
    {
        out=a1*a2;  
    }
    return out;
}


int main()
{
    stack <int> arr1;
    getline(cin,s1);
    while (k!=2)
    {
        if ((s1[j]!=a)&&(s1[j]!=b)&&(s1[j]!=c)&&(s1[j]!=' ')&&(s1[j]!='\0'))
        {
            //cout<<"выполнился 1 пункт "<<s1[j]<<endl;
            if (k!=0)
            {
                chek1=int(s1[j])-48;
                while  (s1[j+1]!=' ')
                {
                    chek1=chek1*10+(int(s1[j+1])-48);
                    j++;
                    
                }
                //cout<<"chek1 "<<chek1<<endl;
                arr1.push(chek1);
                k=0;
                
            }
        }
        else if ((s1[j]!=' ')&&(s1[j]!='\0'))
        {
            //cout<<"выполнился 2 пункт "<<s1[j]<<endl;
            arg1=arr1.top();
            arr1.pop();
            arg2=arr1.top();
            arr1.pop();
            //cout<<arg1<<endl;
            //cout<<arg2<<endl;
            chek1=prefics_fc(s1[j], arg1, arg2);
            arr1.push(chek1);
            k=0;
        }
        
        if (s1[j]!=' ')
        {
            k++;
        }
 
        if (j==s1.length())
        {
            outlast=arr1.top();
            break;
        }
        j++;
    }
    
    cout<<outlast;
}

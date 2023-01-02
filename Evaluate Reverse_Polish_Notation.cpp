#include<string>
#include<vector>
using namespace std;
class Solution {
public:
int op(string opp,int a,int b)
{
    if(opp=="+")
    {
        return a+b;
    }
    else if(opp=="-")
    {
        return a-b;
    }
    else if(opp=="/")
    {
       return a/b;
    }
    else if(opp=="*")
    {
       return a*b;
    }
    return 0;
}
    int evalRPN(vector<string>& t) 
    {
        int a[t.size()];
        //printf("%d",t.size());
        int top=-1;
        for(int i=0;i<t.size();i++)
        {
            if((t[i] == "+") || (t[i]== "-")||(t[i] == "/")||(t[i] == "*"))
            {
                int b=a[top];
                top=top-1;
                int c=a[top];
                a[top]=op(t[i],c,b);
            }
            else
            {
                top++;
                a[top] = stoi(t[i]); 
            }
        }
        return (int)(a[top]);
    }
};
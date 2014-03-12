#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

bool solve(string s)
{
    int len = s.size();
    for(int step=0; step<=len-2; step++)
        for(int i=0; i<len-1-step; i++)
            for(int j=i+1; (j+step+1)<len; j++)
                if ( s[j] == s[i] && s[j+step+1] == s[i+step+1] )
                    return false;
    return true;
}

int main(int argc, const char *argv[])
{
    string s;
    while(cin >> s && s != "*")
    {
        if ( solve(s) )
            cout<< s << " is surprising."<< endl;
        else
            cout<< s << " is NOT surprising."<< endl;
    }
    return 0;
}

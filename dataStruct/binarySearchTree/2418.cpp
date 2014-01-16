#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
map<string, int> treeCount;
map<string, int> :: iterator treeIter;
string tree;
int totalNum = 0;
int main(int argc, const char *argv[])
{
    while( getline(cin, tree) )
    {
        treeCount[tree]++;
        totalNum++;
    }
    for( treeIter=treeCount.begin(); treeIter!=treeCount.end(); treeIter++)
    {
        printf("%s %.4f\n", treeIter->first.c_str(), (treeIter->second*100.0)/totalNum);
    }
    return 0;
}

#include<iostream>  
#include<cmath>  
using namespace std;  
int main()  
{
    double n,m;
    while(cin>>n>>m)  
    {  
        n=(double)pow(m,1/n);  
        cout<<n<<endl;  
    }  
    return 0;  
}  

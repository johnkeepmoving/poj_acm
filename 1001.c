#include<iostream>
using namespace std;
int main(              )
{
 char ch[6];
 int power;
 while(cin>>ch>>power)
 {
  int result[125]={0};
  int tail=5,head=0;
  int after=0;
  while(ch[tail]=='0')
   tail--;
  while(ch[head]!='.')
   head++;
  after=tail-head;
  int i=0;
  int base=0;
  int p=1;
  int pow=power;
  while(tail>=0)
  {
   if(ch[tail]!='.')
   { 
    result[i]=ch[tail]-'0';
    base+=(ch[tail]-'0')*p;
    i++;
    p*=10;
   }
   tail--;
  }
  while(power>1)
  {
   tail=0;
   while(tail<i)
   {
    result[tail]=base*result[tail];
    tail++;
   }
   int j=0;
   int before=0;
   int mid=0;
   while(j<i)
   {
    mid=(result[j]+before)%10;
    before=(result[j]+before)/10;
    result[j]=mid;
    j++;
   }
   while(before>0)
   {
    result[i]=before%10;
    before/=10;
    i++;
   }
   power--;
   
  }
  after*=pow;
  /**
        while(i>=0)
        {
                cout<<result[i];
                i--;
        } **/
  if(after>=i)
    {
     int zero=after-i;
      cout<<".";
      while(zero>0)
      {
      cout<<"0";
        zero--;
      }
      i--;
      while(i>=0)
      {
       cout<<result[i];
        i--;
      }
                
  }  
    else if(after<i)
    {
     i--;
      while(i>=0)
      {
       if(after-i==1)
         cout<<"."<<result[i];
        else
          cout<<result[i];
        i--;
   }    
             
  }
  cout<<endl;
 }
}

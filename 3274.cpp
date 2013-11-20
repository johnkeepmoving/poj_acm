 //HASH
//确实想不到HASH可以用在这么地方，需要把问题进行转化，看了别人解题报告才会写的
//题意是求一个最长的范围，在这个范围内各种FEATRUE出现的次数相同
//很直接想到将他们转化成位然后存起来，然后每位从1到N累加，但是规模还是10W，要找这么大规模中2个数相减他们的差是相同的，并且距离最远的，是O(n^2)
//对于SAMPLE的数据的处理
//前导零        000     000
//7---->111---->111---->000
//6---->110---->221---->110(*)
//7---->111---->332---->110
//2---->010---->342---->120
//1---->001---->343---->010
//4---->100---->443---->110(*)
//2---->010---->453---->120
//443 - 221 = 222说明在这个范围内3中特色都有相同的个数2
//看了解题报告才知道最后一步的转化，每个2进制结果所有位减去他们当中的任意位，上面例子取减去最右边那一位
//这样将问题转化为判重,，只要找两位他们是相同的并且距离是最远的即可(加*为答案)，用HASH来解决是O(NK)
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXHASH = 100003;
int n,k,f;
int bit[100003][32];
int head[MAXHASH],next[100003];//拉链法处理冲突，只需维护表头和next指针即可
int hash(int v[])
{
	int h = 0;
	for(int i = 0; i < k; i++)
		h = ((h<<2) + (v[i]>>4)) ^ (v[i]<<10);
	h = h % MAXHASH;
	h = h < 0 ? h + MAXHASH : h;
	return h;
}
int main()
{
	scanf("%d%d",&n,&k);
	memset(bit,0,sizeof(bit));
	memset(head,-1,sizeof(head));
	int ans = 0;
	for(int i = 1;i <= n;++i)
	{
		scanf("%d",&f);
		for(int j = 0;j < k;++j)
		{
			bit[i][j] = f & 1;
			f = f >> 1;
		}
	}
	for(int i = 2;i <= n;++i)
		for(int j = 0;j < k;++j)
			bit[i][j] += bit[i-1][j];
	for(int i = 0;i <= n;++i)
	{
		int temp = bit[i][0];
		for(int j = 0;j < k;++j)	bit[i][j] -= temp;
		int h = hash(bit[i]);
		bool Find = 0;
		for(int e = head[h];e != -1;e = next[e])
		{
			if(memcmp(bit[e],bit[i],sizeof(bit[i])) == 0)
			{
				ans = max(ans,i - e);
				Find = 1;
				break;
			}
		}
		if(!Find)
		{
			next[i] = head[h];
			head[h] = i;
		}
	}	
	printf("%d\n",ans);
	return 0;
}

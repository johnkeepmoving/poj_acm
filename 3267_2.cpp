#include <iostream>
#include <string>
using namespace std;

int min(int a, int b)
{
    return a > b ? b : a;
}

int main()
{
    int W, L;
    string recmsg, str;
    cin >> W >> L;
    cin >> recmsg;
    string *dict = new string[W];
    int *dp = new int[L + 1];
    int i = 0;
    int j = W;
    int k;
    while (j--) {
	cin >> str;
	dict[i++] = str;	//W字典
    }
    dp[L] = 0;
    for (i = L - 1; i >= 0; i--) {
	dp[i] = dp[i + 1] + 1;
	for (j = 0; j < W; j++) {
	    if (dict[j].length() <= L - i && dict[j].at(0) == recmsg[i]) {
		int t = i;
		int m = 0;
		while (t < L) {
		    if (dict[j].at(m) == recmsg[t++])
			m++;
		    if (m == dict[j].length()) {
			dp[i] = min(dp[t] + t - i - m, dp[i]);
			break;
		    }
		}
	    }
	}
    }
    cout << dp[0] << endl;
}

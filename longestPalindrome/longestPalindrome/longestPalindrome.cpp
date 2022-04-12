#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPR(string str) {

	int n = str.size();
	if (n < 2)
	{
		return str;
	}

	int maxLen = 1;
	int begin = 0;

	//dp[i][j]表示str[i][j] 是否为回文串
	vector<vector<int>> dp(n, vector<int>(n));

	//初始化，所有长度为1的皆为回文串
	for (int i = 0; i < n; i++)
	{
		dp[i][i] == true;
	}

	//递推
	//枚举字串长度
	for (int L = 2; L <= n ; L++)
	{//枚举左边界
		
		for (int i = 0; i < n; i++)
		{//确定右边界
			int j = L + i - 1;
			
			if (j >= n)
			{//右边界越界
				break;
			}
			if (str[i] != str[j])
			{
				dp[i][j] = false;
			}
			else
			{
				if (j-i<3)
				{
					dp[i][j] = true;
				}
				else
				{
					dp[i][j] = dp[i + 1][j - 1];
				}
			}
			//dp[i][L] == true,即s[i，，L]符合回文，此时初始为begin,长度为maxLen
			if (dp[i][j] && j - i + 1 > maxLen) 
			{
				maxLen = j - i + 1;
				begin = i;
			}
		}
	}
	return str.substr(begin, maxLen);
}


int main()
{
	string str, newStr;
	cout << "输入待检验的数字串：";
	cin >> str;
	newStr = longestPR(str);
	cout << "最长回文子串为：";
	cout << newStr;
}
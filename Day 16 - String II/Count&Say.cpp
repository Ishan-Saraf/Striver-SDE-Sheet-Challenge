#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	string ans = "1";

	for (int k=1; k<n; k++)	{
		string temp = "";

		int m = ans.size();

		for (int i=0; i<m; i++) {
			int cnt = 1;

			while (i<m && ans[i+1] == ans[i]) {
				cnt++;
				i++;
			}

			char ch = '0' + cnt;

			temp = temp+ch;
			temp = temp+ans[i];
		}

		ans = temp;
	}

	return ans;
}
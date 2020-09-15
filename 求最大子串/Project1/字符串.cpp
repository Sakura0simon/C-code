#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;
int lengthOfLongestSubstring(string s) 
{
	int maxLen = 0;
	unordered_set<char> chars;
	for (int i = 0; i < s.size(); i++) 
	{
		int len = 1;
		chars.clear();
		chars.insert(s[i]);
		for (int j = i + 1; j < s.size(); j++) 
		{
			if (chars.count(s[j])) 
			{
				break;
			}
			else
			{
				chars.insert(s[j]);
				len++;
			}
		}
		cout << len << endl;
		maxLen = max(maxLen, len);
	}
	return maxLen;
}

int main()
{
	string s = "abcabcbb";
	lengthOfLongestSubstring(s);
	system("pause");
}
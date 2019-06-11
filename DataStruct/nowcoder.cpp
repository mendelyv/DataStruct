//输入一个英文句子，把句子中的单词(不区分大小写)按出现次数按从多到少把单词和次数在屏幕上输出来，要求能识别英文句号和逗号，
//即是说单词由空格、句号和逗号隔开。
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		map<string, int> mp;
		string temp;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ' || s[i] == ',' || s[i] == '.')
			{
				if (temp != "")
					mp[temp]++;
				temp = "";
			}
			else
			{
				temp += tolower(s[i]);
			}
		}
		for (auto it = mp.begin(); it != mp.end(); it++)
		{
			cout << it->first << ":" << it->second << endl;
		}
	}
	return 0;
}

///*
//����һ��Ӣ�ľ��ӣ��Ѿ����еĵ���(�����ִ�Сд)�����ִ������Ӷൽ�ٰѵ��ʺʹ�������Ļ���������Ҫ����ʶ��Ӣ�ľ�źͶ��ţ�
//����˵�����ɿո񡢾�źͶ��Ÿ�����
//*/
//#include <iostream>
//#include <map>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s;
//	while (getline(cin, s))
//	{
//		map<string, int> mp;
//		string temp;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] == ' ' || s[i] == ',' || s[i] == '.')
//			{
//				if (temp != "")
//					mp[temp]++;
//				temp = "";
//			}
//			else
//			{
//				temp += tolower(s[i]);
//			}
//		}
//		for (auto it = mp.begin(); it != mp.end(); it++)
//		{
//			cout << it->first << ":" << it->second << endl;
//		}
//	}
//	return 0;
//}
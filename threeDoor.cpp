//#include <iostream>
//using namespace std;
//
//int* RemoveByIndex(int arr[], int index, int len)
//{
//	int ret[2] = {};
//	for (int i = 0, j = 0; i < len; i++)
//	{
//		if (i == index) continue;
//		ret[j] = arr[i];
//		j++;
//	}
//	return ret;
//}
//
//int main()
//{
//	//�������н��Ĵ���
//	int changeWinCount = 0;
//	//�������н��Ĵ���
//	int unChangeWinCount = 0;
//
//	for (int i = 0; i < 10000; i++)
//	{
//		int arr[] = { 0, 1, 2 };
//		int* p = arr;
//
//		int bounsDoor = rand() % 3;
//		int selectDoor = rand() % 3;
//
//		for (int j = 0; j < 3; j++)
//		{
//			if (p[j] != bounsDoor && p[j] != selectDoor)
//			{
//				p = RemoveByIndex(p, j, 3);
//				break;
//			}
//		}
//
//		int changeDoor = p[0];
//		if (changeDoor == selectDoor)
//			changeDoor = p[1];
//
//		//�������н�
//		if (selectDoor == bounsDoor) unChangeWinCount++;
//		else if (changeDoor == bounsDoor) changeWinCount++;
//	}
//
//	cout << "�������н�������" << unChangeWinCount << endl;
//	cout << "�����н�������" << changeWinCount << endl;
//
//	system("pause");
//}
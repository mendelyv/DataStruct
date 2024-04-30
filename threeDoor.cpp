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
//	//换门能中奖的次数
//	int changeWinCount = 0;
//	//不换门中奖的次数
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
//		//不换门中奖
//		if (selectDoor == bounsDoor) unChangeWinCount++;
//		else if (changeDoor == bounsDoor) changeWinCount++;
//	}
//
//	cout << "不换门中奖次数：" << unChangeWinCount << endl;
//	cout << "换门中奖次数：" << changeWinCount << endl;
//
//	system("pause");
//}
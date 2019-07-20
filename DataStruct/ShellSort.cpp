
#include <iostream>
using namespace std;

void ShellSort(int arr[], int len)
{
	//按照步长分组，每次减半
	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		//循环每个组，组的个数就为步长
		for (int i = 0; i < gap; i++)
		{
			//对每个组进行插入排序
			for (int j = i + gap; j < len; j += gap)
			{
				if (arr[j] < arr[j - gap])
				{
					int tmp = arr[j];
					int k = j - gap;
					while (k >= 0 && arr[k] > tmp)
					{
						arr[k + gap] = arr[k];
						k -= gap;
					}
					arr[k + gap] = tmp;
				}
			}
		}
	}
}


int main()
{
	int arr[] = { 12,25,11,8,34,1,99,54,111,2,33,19,20 };
	int len = 13;
	ShellSort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << ",";

	system("pause");

	return 0;
}
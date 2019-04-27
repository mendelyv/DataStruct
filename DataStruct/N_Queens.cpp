
//使用位运算处理n皇后问题

#include <iostream>
using namespace std;

//sum用来记录不同的情况个数
//upperlim用来标记所有列已经放置好了皇后
long sum = 0, upperlim = 1;

//row, ld, rd, 表示当前行的列，左斜，右斜的冲突
void Find(long row, long ld, long rd)
{
	if (row != upperlim)
	{
		//row, ld, rd进行或计算，求的可以防皇后的位置对应的位值为0
		//然后再取反，与上一个全1的数，求得可以放皇后的位置，对应的位值为1
		long pos = ~(row | ld | rd) & upperlim;
		while (pos) //如果pos的所有位中没有1，即为0，皇后没有位置可以放
		{
			//寻找可以放皇后的位置(默认从右到左)，eg：p=000100，表示该行右数第3列可以放
			//p表示该行的某个可以放皇后的位置，把皇后放在这个位置之后，就把它从pos中移除并递归调用Find的过程
			long p = pos & (~pos + 1);

			//把皇后放在这个位置
			//eg: pos = 111100，p=000100，放上后变成 111100 - 000100 = 111000
			pos -= p;

			//row + p 即在该列上放了一个皇后了，即把该列的位值改为1，传给下一行的寻找使用，eg：第三行011100 + 100000 = 111100
			//(ld + q) << 1, 标记下一行该列的左边相邻的位值为1，
			//(rd + 1) >> 1, 同上
			Find(row + p, (ld + p) << 1, (rd + p) >> 1);
		}
	}
	else
	{
		sum++;
	}
}

int main()
{
	int n = 8;
	upperlim = (upperlim << n) - 1;

	Find(0, 0, 0);
	cout << n << "个皇后共有" << sum << "种摆放方式" << endl;

	system("pause");
}
#include <iostream>

//6(1)
int main6_1() //O(1)  循环次数固定的
{
	int x = 90, y = 100;
	while (y>0)
	{
		if (x>100)
		{
			x = x - 10;
			y--;
		}
		else
		{
			 x ++;
		}
	}
	return 0;
}

//6(4）如果n不是常数，则时间复杂度为O(log 3 n)    3 9 27 81 243
int main6_4()
{
	int	i = 1;
	int n = 100;
	while (i < n)
	{
		i = i * 3;
	}	
	return 0;
}

#include<iostream>
using namespace std;
//找出数组中重复的数字
class Solution {
public:
	bool duplicate(int num[], int n, int* out)
	{
		for (int i = 1; i < n; i++)
		{
			while (num[i] != i)
			{
				if (num[i] == num[num[i]])
				{
					out[0] == num[i];
					cout << "找到了"<<num[i];
						return true;
						
						

				}
				else
				{
					swap(num[i], num[num[i]]);
				}
			}
		}
		return false;

	}
};
int main()
{
	Solution S;
	int num[] = { 1,2,3,4,5,2,3,2 };
	int n = sizeof(num) / sizeof(num[0]);
	int out[] = {0};
	S.duplicate(num, n, out);

	return 0;

}
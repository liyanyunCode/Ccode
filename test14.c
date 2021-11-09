//将单数转化为1，双数转化为1
//例如 2222222输出是0 123输出是101
#include<stdio.h>
int main()
{
	int n = 0;
	int i = 0;
	int sum = 0;
	scanf("%d", &n);
	while (n)
	{
		int m = n % 10;
		if (m % 2 == 1)
		{
			m = 1;
		}
		else
			m = 0;
		sum+=m* pow(10, i);
		i++;
		n /= 10;
	}
	printf("%d", sum);
		return 0;
}
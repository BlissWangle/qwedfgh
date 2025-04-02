//求高精度阶乘
#include <stdio.h>

void Print_Factorial(const int N);

int main()
{
	int N;

	scanf("%d", &N);
	Print_Factorial(N);
	return 0;
}
void Print_Factorial(const int N)
{
	int arr[3000] = { 0 };
	arr[0] = 1;
	int index = 0;
	if (N == 0)
	{
		printf("1");
		return;
	}
	if (N < 0)
	{
		printf("Invalid input\n");
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		int go = 0;
		int temp = 0;
		//计算阶乘
		for (int j = 0; j < 3000; j++)
		{
			temp = arr[j] * i + go;
			arr[j] = temp % 10;
			go = temp / 10;
		}
	}
	//计算位数
	for (int i = 2999; i >= 0; i--)
	{
		if (arr[i] != 0)
		{
			index = i;
			break;
		}
	}
	//打印
	for (int i = index; i >= 0; i--)
	{
		printf("%d", arr[i]);
	}
}
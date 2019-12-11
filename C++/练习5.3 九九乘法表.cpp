//将习题4.9打印乘法九九表改用函数调用的方式，适当取函数名，分别调用三种函数以输出不同格式。
#include <iostream.h>
#include <iomanip.h>

void wanzheng(int n);
void xia(int n);
void shang(int n);

int main(void)
{
	int m,n;
	int i,j,k;

	for(i = 3 ; i > 0 ; i--)
	{
		do{											//避免非法输入
			cout << "1:完整九九乘法表" << endl
				 << "2:下九九乘法表" << endl
				 << "3:上九九乘法表" << endl
				 << "Enter your choice:" << endl;
			cin >> m;
		}while((m != 1) && (m != 2) && (m != 3));
		
		cout << "输入阶数：";
		cin >> n;

		cout << "*";								//输出第一行
		for( j = 1 ; j <= n ; j++)
			cout << setw(4) << j;
		cout << endl;

		for( k = 1 ; k <= n+1 ; k++)				//输出第二行
			cout << setw(4) << "....";
		cout << endl;

		switch(m)
		{
			case 1 : wanzheng(n) ; break;
			case 2 : xia(n) ; break;
			case 3 : shang(n) ; break;
			default : break;
		}
	}	 	
}

//输出完整九九乘法表
void wanzheng(int n)
{
	int i,j;

	for(i = 1 ; i <= n ; i++)
	{
		cout << i;

		for(j = 1 ; j <= n ; j++)
			cout << setw(4) << i*j;

		cout << endl;
	}
}

//输出下九九乘法表
void xia(int n)
{
	int i,j;

	for(i = 1 ; i <= n ; i++)
	{
		cout << i;

		for(j = 1 ; j <= i ; j++)
			cout << setw(4) << i*j;

		cout << endl;
	}
}

//输出上九九乘法表
void shang(int n)
{
	int i , j , k;

	for(i = 1 ; i <= n ; i++)
	{
		cout << i;

		for(k = 0 ; k < i - 1 ; k++)
			cout << setw(4) <<" ";

		for(j = i ; j <= n ; j++)
			cout << setw(4) << i*j;

		cout << endl;
	}
}
//��ϰ��4.9��ӡ�˷��žű���ú������õķ�ʽ���ʵ�ȡ���������ֱ�������ֺ����������ͬ��ʽ��
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
		do{											//����Ƿ�����
			cout << "1:�����žų˷���" << endl
				 << "2:�¾žų˷���" << endl
				 << "3:�Ͼžų˷���" << endl
				 << "Enter your choice:" << endl;
			cin >> m;
		}while((m != 1) && (m != 2) && (m != 3));
		
		cout << "���������";
		cin >> n;

		cout << "*";								//�����һ��
		for( j = 1 ; j <= n ; j++)
			cout << setw(4) << j;
		cout << endl;

		for( k = 1 ; k <= n+1 ; k++)				//����ڶ���
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

//��������žų˷���
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

//����¾žų˷���
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

//����Ͼžų˷���
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
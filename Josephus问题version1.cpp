/*
Josephus���⣺
    һȺС��Χ��һȦ������ٶ�һ����m���ӵ�һ��С����˳ʱ�뷽������ÿ
������m��С��ʱ����С�����뿪��С�������뿪��Ȧ�Ӳ�����С�����ʣ�µ�
һ��С������ʤ���ߡ�
*/

#include<iostream.h>

int main()
{
	//����С������
	const int num = 10; //С����
	int interval; //ÿ����interval��С�������ø�С���뿪
	int a[num]; //С������

	//��С�����
	for(int i = 1;i < num;i++)
		a[i] = i + 1; //С���ı��ֻ��С�����й�

	//������С�����
	cout << "please input the interval:"; //����һ����С������
	cin >> interval;

	//��ȫ��μӵ�С�����
	for(int i = 0;i < num;i++)
		cout << a[i] << ","; //˳�������ʼʱ��С�����
	cout << endl;

}
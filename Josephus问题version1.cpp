/*
Josephus问题：
    一群小孩围成一圈，任意假定一个数m，从第一个小孩起，顺时针方向数，每
数到第m个小孩时，该小孩便离开，小孩不断离开，圈子不断缩小，最后，剩下的
一个小孩便是胜利者。
*/

#include<iostream.h>

int main()
{
	//建立小孩数组
	const int num = 10; //小孩数
	int interval; //每次数interval个小孩，便让该小孩离开
	int a[num]; //小孩数组

	//给小孩编号
	for(int i = 1;i < num;i++)
		a[i] = i + 1; //小孩的编号只与小孩数有关

	//输入数小孩间隔
	cout << "please input the interval:"; //输入一个数小孩个数
	cin >> interval;

	//将全体参加的小孩输出
	for(int i = 0;i < num;i++)
		cout << a[i] << ","; //顺序输出开始时的小孩编号
	cout << endl;

}
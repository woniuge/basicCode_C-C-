#include <iostream.h>
#include <stdio.h>
#include <process.h>

const int M = 15;
const int N = 15;

void main()
{

int a[M][N];
int b[M][N];//数组b用来存放机器人走每一步所花费的时间
int i,j;
int num,len;   //num，len分别表示机器人个数，每个机器人最多可走距离
int dis;             //机器人所需行进的路程距离
int sum=0;

FILE *fp1;
FILE *fp2;


if ((fp1 = fopen("input.txt","r")) == NULL)		/* 打开文件input.txt */
{	
	printf("File open error !\n");
	exit(0);
}

fscanf(fp1,"%d%d%d",&num,&len,&dis);

while(!feof(fp1))
	for (i = 0; i <= num; i++)
		for (j = 0; j <= len; j++)
				fscanf(fp1,"%d",&a[i][j]);
fclose(fp1);

struct robot//step[]分别记录num个机器人的行进信息
{
int step[N];
}robot[M];


for(i=0;i<num;i++)//将step全部初始化为
	for(j=0;j<len;j++)
		robot[i].step[j]=0;

for(i=0;i<num;i++)//计算b[][]中的数值
{
b[i][0]=a[i][0];
}


for(i=0;i<num;i++)//同上
{
	for(j=1;j<len;j++)
	{
	b[i][j]=a[i][j]-a[i][j-1];
	}
}
/*
for(i=0;i<5;i++)
{
	for(j=0;j<10;j++)
	{
	cout<<b[i][j]<<"\t";
	if(j==9)
	cout<<endl;
	}
}
*/




int *p[M];
for(i=0;i<num;i++)//定义一指针数组p[]，指向每一行中未被选中的数值中的第一个
{
p[i]=&b[i][0];
}


int temp;
int index = 0;
int count = 1;
//总共需要循环次
while (1)
{
	for(i=0;i<num;i++)//通过p[]的移动选出*p[]中的最小值，记录该值，指向该值的p[]后移
	{
		if(*p[i]<=*p[index])
		{

		index=i;
		temp=*p[index];
		}
	}
	p[index]++;
	sum=sum+temp;
	for(j=0;j<len;j++)
	{
		if(robot[index].step[j]==0)
		{
		robot[index].step[j]=temp;
		break;
		}
	}
	if (count == dis)
		break;
	count++;
}


//输出语句
cout<<"---------------------------------------------------"<<endl<<endl;
cout<<"The shortest time is "<<sum<<" seconds"<<endl<<endl;
cout<<"---------------------------------------------------"<<endl<<endl;
cout<<"The details of every robot(the time they spend on taking every step):"<<endl;

for(i=0;i<num;i++)
{
cout<<"robot"<<i+1<<": "<<"step";
for(j=0;j<len;j++)
{
if(robot[i].step[j]!=0)
{
cout<<"("<<j+1<<")"<<robot[i].step[j]<<"s  ";
}
}
cout<<endl;
}

if ((fp2 = fopen("output.txt","w")) == NULL){	/* 打开output.txt文件*/
	printf("File open error !\n");
	exit(0);
}
fprintf(fp2,"%d",sum);

fclose(fp2);										/* 关闭output.txt文件*/

}
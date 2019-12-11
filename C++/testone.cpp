#include <iostream.h>
#include <stdio.h>
#include <process.h>

const int M = 15;
const int N = 15;

void main()
{

int a[M][N];
int b[M][N];//����b������Ż�������ÿһ�������ѵ�ʱ��
int i,j;
int num,len;   //num��len�ֱ��ʾ�����˸�����ÿ�������������߾���
int dis;             //�����������н���·�̾���
int sum=0;

FILE *fp1;
FILE *fp2;


if ((fp1 = fopen("input.txt","r")) == NULL)		/* ���ļ�input.txt */
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

struct robot//step[]�ֱ��¼num�������˵��н���Ϣ
{
int step[N];
}robot[M];


for(i=0;i<num;i++)//��stepȫ����ʼ��Ϊ
	for(j=0;j<len;j++)
		robot[i].step[j]=0;

for(i=0;i<num;i++)//����b[][]�е���ֵ
{
b[i][0]=a[i][0];
}


for(i=0;i<num;i++)//ͬ��
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
for(i=0;i<num;i++)//����һָ������p[]��ָ��ÿһ����δ��ѡ�е���ֵ�еĵ�һ��
{
p[i]=&b[i][0];
}


int temp;
int index = 0;
int count = 1;
//�ܹ���Ҫѭ����
while (1)
{
	for(i=0;i<num;i++)//ͨ��p[]���ƶ�ѡ��*p[]�е���Сֵ����¼��ֵ��ָ���ֵ��p[]����
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


//������
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

if ((fp2 = fopen("output.txt","w")) == NULL){	/* ��output.txt�ļ�*/
	printf("File open error !\n");
	exit(0);
}
fprintf(fp2,"%d",sum);

fclose(fp2);										/* �ر�output.txt�ļ�*/

}
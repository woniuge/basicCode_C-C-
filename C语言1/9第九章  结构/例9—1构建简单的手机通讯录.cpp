/* �����򵥵��ֻ�ͨѶ¼��ʵ����򵥹��� */
#include <stdio.h>
#include <string.h>
/* �ֻ�ͨѶ¼�ṹ���� */
struct friends_list
{
	char name[10];
	int age;
	char telephone[13];
};

int Count=0;								/* ����ȫ�ֱ���Count����¼��ǰ��ϵ������ */
void new_friend(struct friends_list friends[]);
void search_friend(struct friends_list friends[],char *name);

int main(void)
{
	int choice;
	char name[10];
	struct friends_list friends[50];		/* ����50���˵�ͨѶ¼ */

	do
	{
		printf("�ֻ�ͨѶ¼����ѡ��:\n1:�½�\n2:��ѯ\n0:�˳�\n");
		printf("��ѡ����:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				new_friend(friends);
				break;
			case 2:
				printf("������Ҫ���ҵ���ϵ������:");
				scanf("%s",name);
				search_friend(friends,name);
				break;
			case 0:
				break;
		}
	}while(choice!=0);

	printf("ллʹ��ͨѶ¼����!\n");

	return 0;
}

void new_friend(struct friends_list friends[])
{
	struct friends_list f;

	if(Count==50)
	{
		printf("ͨѶ¼����!\n");
		return;
	}
	printf("����������ϵ�˵�����:");
	scanf("%s",f.name);
	printf("����������ϵ�˵�����:");
	scanf("%d",&f.age);
	printf("����������ϵ�˵���ϵ�绰:");
	scanf("%s",f.telephone);
	friends[Count]=f;
	Count++;
}

void search_friend(struct friends_list friends[],char *name)
{
	int i,flag=0;
	if(Count==0)
	{
		printf("ͨѶ¼�ǿյ�!\n");
		return;
	}
	for(i=0;i<Count;i++)
		if(strcmp(name,friends[i].name)==0)
		{
			flag=1;
			break;
		}
	if(flag)
	{
		printf("����:%s\t",friends[i].name);
		printf("����:%d\t",friends[i].age);
		printf("�绰:%s\n",friends[i].telephone);
	}

	else
		printf("�޴���ϵ��!");
}
 /* �����ֻ��򵥵�ͨѶ¼ */
#include <stdio.h>
#include <string.h>

struct address
{
	char city[10];
	char street[20];
	int code;
	int zip;
};
struct birthday
{
	int year;
	int month;
	int day;
};
struct friends_list
{
	char name[10];
	int age;
	struct birthday birth;
	char telephone[13];
	struct address addr;
};

int Count=0;								/* ����ȫ�ֱ���Count����¼��ǰ��ϵ������ */
void new_friend(struct friends_list friends[]);
void xiugai_friend(struct friends_list friends[],char *name);
void delete_friend(struct friends_list *p,char *name);
void search_friend(struct friends_list friends[],char *name);

int main(void)
{
	int choice;
	char name[10];
	struct friends_list friends[50],*pf;		/* ����50���˵�ͨѶ¼ */

	pf=friends;
	do
	{
		printf("�ֻ�ͨѶ¼����ѡ��:\n1:�½�\n2:�޸�\n3:ɾ��\n4:��ѯ\n0:�˳�\n");
		printf("��ѡ����:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				new_friend(friends);
				break;
			case 2:
				printf("������Ҫ�޸ĵ���ϵ������:");
				scanf("%s",name);
				xiugai_friend(friends,name);
				break;
			case 3:
				printf("������Ҫɾ������ϵ������:");
				scanf("%s",name);
				delete_friend(pf,name);
				break;
			case 4:
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
	printf("����������ϵ�˵����գ��꣬�£��գ�:");
	scanf("%d%d%d",&f.birth.year,&f.birth.month,&f.birth.day);
	printf("����������ϵ�˵���ϵ�绰:");
	scanf("%s",f.telephone);
	printf("����������ϵ�˵ĵ�ַ�����У��ֵ������ƺţ��ʱࣩ:");
	scanf("%s%s%d%d",f.addr.city,f.addr.street,&f.addr.code,&f.addr.zip);
	friends[Count]=f;
	Count++;
}

void xiugai_friend(struct friends_list friends[],char *name)
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
		printf("���������ϵ�˵�����Ϣ");
		printf("���������ϵ�˵�����:");
		scanf("%d",&friends[i].age);
		printf("���������ϵ�˵����գ��꣬�£��գ�:");
		scanf("%d%d%d",&friends[i].birth.year,&friends[i].birth.month,&friends[i].birth.day);
		printf("����������ϵ�˵���ϵ�绰:");
		scanf("%s",friends[i].telephone);
		printf("����������ϵ�˵ĵ�ַ�����У��ֵ������ƺţ��ʱࣩ:");
		scanf("%s%s%d%d",friends[i].addr.city,friends[i].addr.street,&friends[i].addr.code,&friends[i].addr.zip);
	}

	else
		printf("�޴���ϵ��!");
}

void delete_friend(struct friends_list *p,char *name)
{
	int i,flag=0;
	struct friends_list t={""},*pt;

	pt=&t;
	if(Count==0)
	{
		printf("ͨѶ¼�ǿյ�!\n");
		return;
	}
	for(i=0;i<Count;i++)
		if(strcmp(name,p->name)==0)
		{
			flag=1;
			break;
		}
	if(flag)
		strcpy(p->name,pt->name);
	else
		printf("�޴���ϵ��!");
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
		printf("����:%s ",friends[i].name);
		printf("����:%d ",friends[i].age);
		printf("����:%d-%d-%d ",friends[i].birth.year,friends[i].birth.month,friends[i].birth.day);
		printf("�绰:%s\n",friends[i].telephone);
		printf("��ַ:%s-%s-%d-%d\n",friends[i].addr.city,friends[i].addr.street,friends[i].addr.code,friends[i].addr.zip);
	}
	else
		printf("�޴���ϵ��!\n");
}
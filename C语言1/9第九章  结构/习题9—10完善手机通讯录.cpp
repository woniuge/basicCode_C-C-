 /* 完善手机简单的通讯录 */
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

int Count=0;								/* 定义全局变量Count，记录当前联系人总数 */
void new_friend(struct friends_list friends[]);
void xiugai_friend(struct friends_list friends[],char *name);
void delete_friend(struct friends_list *p,char *name);
void search_friend(struct friends_list friends[],char *name);

int main(void)
{
	int choice;
	char name[10];
	struct friends_list friends[50],*pf;		/* 包含50个人的通讯录 */

	pf=friends;
	do
	{
		printf("手机通讯录功能选项:\n1:新建\n2:修改\n3:删除\n4:查询\n0:退出\n");
		printf("请选择功能:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				new_friend(friends);
				break;
			case 2:
				printf("请输入要修改的联系人姓名:");
				scanf("%s",name);
				xiugai_friend(friends,name);
				break;
			case 3:
				printf("请输入要删除的联系人姓名:");
				scanf("%s",name);
				delete_friend(pf,name);
				break;
			case 4:
				printf("请输入要查找的联系人姓名:");
				scanf("%s",name);
				search_friend(friends,name);
				break;
			case 0:
				break;
		}
	}while(choice!=0);

	printf("谢谢使用通讯录功能!\n");

	return 0;
}

void new_friend(struct friends_list friends[])
{
	struct friends_list f;

	if(Count==50)
	{
		printf("通讯录已满!\n");
		return;
	}
	printf("请输入新联系人的名字:");
	scanf("%s",f.name);
	printf("请输入新联系人的年龄:");
	scanf("%d",&f.age);
	printf("请输入新联系人的生日（年，月，日）:");
	scanf("%d%d%d",&f.birth.year,&f.birth.month,&f.birth.day);
	printf("请输入新联系人的联系电话:");
	scanf("%s",f.telephone);
	printf("请输入新联系人的地址（城市，街道，门牌号，邮编）:");
	scanf("%s%s%d%d",f.addr.city,f.addr.street,&f.addr.code,&f.addr.zip);
	friends[Count]=f;
	Count++;
}

void xiugai_friend(struct friends_list friends[],char *name)
{
	int i,flag=0;

	if(Count==0)
	{
		printf("通讯录是空的!\n");
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
		printf("请输入该联系人的新信息");
		printf("请输入该联系人的年龄:");
		scanf("%d",&friends[i].age);
		printf("请输入该联系人的生日（年，月，日）:");
		scanf("%d%d%d",&friends[i].birth.year,&friends[i].birth.month,&friends[i].birth.day);
		printf("请输入新联系人的联系电话:");
		scanf("%s",friends[i].telephone);
		printf("请输入新联系人的地址（城市，街道，门牌号，邮编）:");
		scanf("%s%s%d%d",friends[i].addr.city,friends[i].addr.street,&friends[i].addr.code,&friends[i].addr.zip);
	}

	else
		printf("无此联系人!");
}

void delete_friend(struct friends_list *p,char *name)
{
	int i,flag=0;
	struct friends_list t={""},*pt;

	pt=&t;
	if(Count==0)
	{
		printf("通讯录是空的!\n");
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
		printf("无此联系人!");
}

void search_friend(struct friends_list friends[],char *name)
{
	int i,flag=0;
	if(Count==0)
	{
		printf("通讯录是空的!\n");
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
		printf("姓名:%s ",friends[i].name);
		printf("年龄:%d ",friends[i].age);
		printf("生日:%d-%d-%d ",friends[i].birth.year,friends[i].birth.month,friends[i].birth.day);
		printf("电话:%s\n",friends[i].telephone);
		printf("地址:%s-%s-%d-%d\n",friends[i].addr.city,friends[i].addr.street,friends[i].addr.code,friends[i].addr.zip);
	}
	else
		printf("无此联系人!\n");
}
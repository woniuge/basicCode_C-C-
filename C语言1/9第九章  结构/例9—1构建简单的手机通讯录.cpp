/* 构建简单的手机通讯录，实现其简单功能 */
#include <stdio.h>
#include <string.h>
/* 手机通讯录结构定义 */
struct friends_list
{
	char name[10];
	int age;
	char telephone[13];
};

int Count=0;								/* 定义全局变量Count，记录当前联系人总数 */
void new_friend(struct friends_list friends[]);
void search_friend(struct friends_list friends[],char *name);

int main(void)
{
	int choice;
	char name[10];
	struct friends_list friends[50];		/* 包含50个人的通讯录 */

	do
	{
		printf("手机通讯录功能选项:\n1:新建\n2:查询\n0:退出\n");
		printf("请选择功能:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				new_friend(friends);
				break;
			case 2:
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
	printf("请输入新联系人的联系电话:");
	scanf("%s",f.telephone);
	friends[Count]=f;
	Count++;
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
		printf("姓名:%s\t",friends[i].name);
		printf("年龄:%d\t",friends[i].age);
		printf("电话:%s\n",friends[i].telephone);
	}

	else
		printf("无此联系人!");
}
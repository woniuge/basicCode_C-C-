

//设当前考察的正则表达式为s,当前考察的文件为f。
//用match(i,j)表示s[1..i]与f[1..j]的匹配情况。
//当s[1..i]能匹配f[1..i]时，match(i,j)=1，否则match(i,j)=0。

#include<iostream>
#include<string>
using namespace std;

int maxmat; //最优正则表达式所能匹配到的操作文件数
int minlen;  //最优正则表达式的长度
int currmat;  //当前最优正则表达式所能匹配的操作文件数
char minmat[10];
char s[10];
int p[10];
struct cf
{
	char c;
	int f;
}cha[10][10];
int n[2];
string f[10]; //f[10]用来存储输入的文件名称
int match[10][10][10];  //match[len][i][j]表示s[1..lenth]与f[i][1..j]的匹配情况。

void readin(); //读入数据并初始化
void save(char c,int len); //save对操作文件名中出现的字符按出现频率排序储存，以加快搜索进程
bool check(int len); //计算当前匹配情况
bool ok(int len); //用于判定是否匹配非操作文件
void search(int len); 


int main()
{
	readin();
	search(0);
    for(int i=1;i<=minlen;i++)
		cout<<minmat[i];
	cout<<endl;
	return 0;
}

void readin() //读入数据并初始化
{

	int m;
	cout<<"输入文件数目："<<endl;
	cin>>m;
    
	string k[10],str;
	char chr;
	n[0]=0;n[1]=0;p[0]=0;
	cout<<"输入文件名："<<endl;
	while(m>0)
	{
	    cin>>str>>chr;
		if(chr=='+')
		{
			f[++n[0]]=str;
			save(str[0],0);
		}
		else k[++n[1]]=str;
		m--;
	}
	for(int i=1;i<=n[1];i++)
		f[n[0]+i]=k[i];
	memset(match,0,sizeof(match));
	for(i=1;i<=n[0]+n[1];i++)
		match[0][i][0]=1;
	maxmat=0;
	minlen=255;
	
}

void save(char c,int len) //save对操作文件名中出现的字符按出现频率排序储存，以加快搜索进程
{
	for(int i=1;i<=p[len];i++) //p[i]表示操作文件名中出现的不同的字符的个数
    	if(cha[len][i].c==c)  //cha[len][i]表示当前考察的正则表达式长度为len时，操作文件名字出现频率第i高的字符。
		{
			cha[len][i].f++;
			cha[len][0]=cha[len][i];
			int j=i;
			while(cha[len][j-1].f<cha[len][0].f)
			{
				cha[len][j]=cha[len][j-1];
				j--;
			}
			cha[len][j]=cha[len][0];
			return;	
		}
		cha[len][++p[len]].c=c;
		cha[len][p[len]].f=1;	
}

bool check(int len) //计算当前匹配情况
{
	int i,j,t,k=0;
	currmat=0;
	for(i=1;i<=n[0];i++)
	{
		memset(&match[len][i],0,sizeof(match[len][i])); //m[len][i]数组全部赋初值0

		if(len==1&&s[1]=='*')
			match[len][i][0]=1;

		for(j=1;j<=f[i].length();j++)
			switch(s[len]){
			case'*':
				for(t=0;t<=j;t++)
					if(match[len-1][i][t]==1)
					{
						match[len][i][j]=1; 
						break;
					}
				break;
            case'?':
	        	match[len][i][j]=match[len-1][i][j-1];
			    break;
			default:
				if(s[len]==f[i][j-1])
					match[len][i][j]=match[len-1][i][j-1];
				break;}

		for(j=f[i].length();j>=1;j--)
			if(match[len][i][j]==1)
			{
				k++;
				if(j==f[i].length())
					currmat++;
				break;
			}
	}
	if(k<maxmat||k==maxmat&&len>=minlen)
		return 0;
	p[len]=0;
	for(i=1;i<=n[0];i++)
		for(j=1;j<=f[i].length()-1;j++)
			if(match[len][i][j]==1)
				save(f[i][j],len);
		return 1;
}

bool ok(int len) //用于判定是否匹配非操作文件
{
	int i,j,t,k;

	for(k=1;k<=len;k++)
		for(i=n[0]+1;i<=n[0]+n[1];i++)
		{
		    memset(&match[k][i],0,sizeof(match[k][i]));//m[len][i]数组全部赋初值0
		    if(s[1]=='*'&&k==1)
		     	match[k][i][0]=1;
		    for(j=1;j<=f[i].length();j++)
			    switch(s[k]){
			    case'*':
			    	for(t=0;t<=j;t++)
				    	if(match[k-1][i][t]==1)
						{
					    	match[k][i][j]=1;
					    	break;
						}
			    	break;
                case'?':
	            	match[k][i][j]=match[k-1][i][j-1];
			        break;
		    	default:
			    	if(s[k]==f[i][j-1])
					    match[k][i][j]=match[k-1][i][j-1];
			    	break;}
		}

	for(i=n[0]+1;i<=n[0]+n[1];i++)
		if(match[len][i][f[i].length()]==1)	
			return 0;
	return 1;
}
void search(int len) 
{
	if((currmat>maxmat||currmat==maxmat&&len<minlen)&&ok(len))
	{
		maxmat=currmat;
		minlen=len;
		for(int i=1;i<=minlen;i++)
			minmat[i]=s[i];
	}
	len++;
	if(len==1||s[len-1]!='*')
	{
		s[len]='?';
	    if(check(len))
	     	search(len);
	    s[len]='*';
    	if(check(len))
		    search(len);
	}
	for(int i=1;i<=p[len-1];i++)
	{
		s[len]=cha[len-1][i].c;
		if(check(len))
			search(len);
	}
}






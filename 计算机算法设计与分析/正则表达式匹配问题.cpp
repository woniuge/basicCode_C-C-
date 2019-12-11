

//�赱ǰ�����������ʽΪs,��ǰ������ļ�Ϊf��
//��match(i,j)��ʾs[1..i]��f[1..j]��ƥ�������
//��s[1..i]��ƥ��f[1..i]ʱ��match(i,j)=1������match(i,j)=0��

#include<iostream>
#include<string>
using namespace std;

int maxmat; //����������ʽ����ƥ�䵽�Ĳ����ļ���
int minlen;  //����������ʽ�ĳ���
int currmat;  //��ǰ����������ʽ����ƥ��Ĳ����ļ���
char minmat[10];
char s[10];
int p[10];
struct cf
{
	char c;
	int f;
}cha[10][10];
int n[2];
string f[10]; //f[10]�����洢������ļ�����
int match[10][10][10];  //match[len][i][j]��ʾs[1..lenth]��f[i][1..j]��ƥ�������

void readin(); //�������ݲ���ʼ��
void save(char c,int len); //save�Բ����ļ����г��ֵ��ַ�������Ƶ�����򴢴棬�Լӿ���������
bool check(int len); //���㵱ǰƥ�����
bool ok(int len); //�����ж��Ƿ�ƥ��ǲ����ļ�
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

void readin() //�������ݲ���ʼ��
{

	int m;
	cout<<"�����ļ���Ŀ��"<<endl;
	cin>>m;
    
	string k[10],str;
	char chr;
	n[0]=0;n[1]=0;p[0]=0;
	cout<<"�����ļ�����"<<endl;
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

void save(char c,int len) //save�Բ����ļ����г��ֵ��ַ�������Ƶ�����򴢴棬�Լӿ���������
{
	for(int i=1;i<=p[len];i++) //p[i]��ʾ�����ļ����г��ֵĲ�ͬ���ַ��ĸ���
    	if(cha[len][i].c==c)  //cha[len][i]��ʾ��ǰ�����������ʽ����Ϊlenʱ�������ļ����ֳ���Ƶ�ʵ�i�ߵ��ַ���
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

bool check(int len) //���㵱ǰƥ�����
{
	int i,j,t,k=0;
	currmat=0;
	for(i=1;i<=n[0];i++)
	{
		memset(&match[len][i],0,sizeof(match[len][i])); //m[len][i]����ȫ������ֵ0

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

bool ok(int len) //�����ж��Ƿ�ƥ��ǲ����ļ�
{
	int i,j,t,k;

	for(k=1;k<=len;k++)
		for(i=n[0]+1;i<=n[0]+n[1];i++)
		{
		    memset(&match[k][i],0,sizeof(match[k][i]));//m[len][i]����ȫ������ֵ0
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






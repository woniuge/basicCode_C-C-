#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int x,int y){	//�����������
	return x>y;
}

int main(){
	int n;
	int i;
	int buf[100];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",&buf[i]);
		}
		sort(buf,buf+n,cmp);	//ʹ�ø�������ʽ�����Ǳ�����Ҫʹ���Լ���������й���
		for(i=0;i<n;i++){
			printf("%d ",buf[i]);
		}
		printf("\n");
	}
	return 0;
}

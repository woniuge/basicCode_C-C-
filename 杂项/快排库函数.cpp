#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int i;
	int buf[100];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",&buf[i]);
		}
		sort(buf,buf+n);	//ʹ�ø�������ʽ��������Ҫʹ���Լ���������й���
		for(i=0;i<n;i++){
			printf("%d ",buf[i]);
		}
		printf("\n");
	}
	return 0;
}
#include <stdio.h>

int main(){
	int n;
	int i,j;
	int buf[100];
	int tmp;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",&buf[i]);
		}
		for(i=0;i<n;i++){
			for(j=0;j<n-i-1;j++){
				if(buf[j]>buf[j+1]){
					tmp=buf[j];
					buf[j]=buf[j+1];
					buf[j+1]=tmp;
				}	
			}
		}
		for(i=0;i<n;i++){
			printf("%d ",buf[i]);
		}
		printf("\n");
	}
	return 0;
}

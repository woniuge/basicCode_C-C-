#include <stdio.h>
#define OFFSET 500000
int hash[1000001]={0};

int main(){
	int m,n;
	int i;
	int x;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			hash[x+OFFSET]=1;
		}
		for(i=500000;i>=-500000;i--){
			if(hash[i+OFFSET]==1){
				printf("%d",i);
				m--;
				if(m!=0) printf(" ");
				else{
					printf("\n");
					break;
				}
			}
		}
	}
	return 0;
}
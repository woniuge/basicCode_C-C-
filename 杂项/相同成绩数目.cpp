#include <stdio.h>

int main(){
	int n;
	int hash[101]={0};
	int i;
    int x;
	while(scanf("%d",&n)!=EOF && n!=0){
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			hash[x]++;
		}
		scanf("%d",&x);
		printf("%d",hash[x]);
	}
	return 0;
}
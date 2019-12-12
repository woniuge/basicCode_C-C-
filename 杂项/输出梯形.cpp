#include <stdio.h>

int main(){
	int h;
	int maxLine;
	int i,j;
	while(scanf("%d",&h)!=EOF){
		maxLine=h+(h-1)*2;
		for(i=1;i<=h;i++){
			for(j=1;j<=maxLine;j++){
				if(j<maxLine-h-(i-1)*2+1)
					printf(" ");
				else
					printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
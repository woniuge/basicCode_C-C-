// arrary.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"array.h"
#include<iomanip>
#include<iostream>
using namespace std;
int *A;
void main()
{
      
  /* inittriplet<int,int,int>(A,12,5,34,4,67);
   int *p = A;
   int max;
   for (int i = 0; i < 4; i++)
   {
	   
	   max = bijiao(p[i],p[i+1]);

   }
   cout<< max <<endl;

   for ( int i = 0; i < 5; i++ )
   {
	   int zonghe = 0 ;
	   zonghe = zonghe + *A;
	   A++;
   }
   cout<< "zonghe" <<endl;*/
	int N;
	cin>>N;
	int **a;
	a=new int*[N];
	for(int i=0;i<N;i++){
		a[i]=new int[N];
	}
	int k=1;
	for(int i=0;i<(N+1)/2;i++){
		int j,m;
		j=i;m=i;
		for(;j<N-i;j++){
			a[m][j]=k;
			k++;
		}
		j--;
		m++;
		for(;m<N-i;m++){
			a[m][j]=k;
			k++;
		}
		m--;
		j--;
		for(;j>=i;j--){
			a[m][j]=k;
			k++;
		}
		j++;
		m--;
		for(;m>i;m--){
			a[m][j]=k;
			k++;
		}
		m++;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<setw(6)<<a[i][j];
		}
		cout<<endl;
	}
	/*char word[100];
	cin>>word;
	int len = strlen(word);
	for(int i = 1; i <= len; i++)
   {
	   if(len % i == 0)
	   {
		   int ok = 1; 
		   for(int j = i; j < len; j++)
		   {
			   if(word[j] != word[j%i])
			   {
				   ok = 0; break;
			   }
		   }
		   if(ok)
		   {
			   cout<<i<<endl;
			   break;
		   }
	   }
	}*/

}

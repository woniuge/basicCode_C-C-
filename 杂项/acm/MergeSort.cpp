// MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include<ctime>

typedef int DataType;



void MSort(DataType [],DataType [],int ,int);
void Merge(DataType [],DataType [],int ,int ,int);


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	int n;
	DataType *a,*b;
	cin>>n;
	a=new DataType[n];
	b=new DataType[n];
	for(int i=0;i<n;i++){
		a[i]=rand()%10000;
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<"    ";
	}
	cout<<endl;
	MSort(a,b,0,n-1);
	for(int i=0;i<n;i++){
		cout<<b[i]<<"    ";
	}
	cout<<endl;
	return 0;
}

void Merge(DataType a[],DataType b[],int s,int m,int t){
	int i,j,k;
	for(i=s,j=m+1,k=s;i<=m&&j<=t;k++){
		if(a[i]<=a[j]){
			b[k]=a[i++];
		}
		else{
			b[k]=a[j++];
		}
	}
	if(i>m){
		for(int l=k;l<=t;l++){
			b[l]=a[j++];
		}
	}
	else{
		for(int l=k;l<=t;l++){
			b[l]=a[i++];
		}
	}

}

void MSort(DataType a[],DataType b[],int s,int t){
	DataType *c;
	c=new DataType [t+1];
	if(s==t){
		b[s]=a[s];
	}
	else{
		int m=(s+t)/2;
		MSort(a,c,s,m);
		MSort(a,c,m+1,t);
		Merge(c,b,s,m,t);
	}
}





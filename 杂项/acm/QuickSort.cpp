// QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include<ctime>
#include<string.h>

typedef int DataType;



void swap(DataType &,DataType &);
int partition(DataType [],int,int);
void QuickSort(DataType [],int,int);


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	int n;
	DataType *a;
	cin>>n;
	a=new DataType[n];
	//DataType a[10];
	for(int i=0;i<n;i++){
		a[i]=rand()%10000;
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<"    ";
	}
	cout<<endl;
	QuickSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<"    ";
	}
	cout<<endl;
	return 0;
}

/*void swap(DataType &a,DataType &b){
	DataType temp;
	temp=a;
	a=b;
	b=temp;
}*/

int partition(DataType arr[],int low,int high){
	DataType povit=arr[low];
	while(low<high){
		while(low<high && arr[high]>=povit){
			high--;
		}
		arr[low]=arr[high];
		while(low<high && arr[low]<=povit){
			low++;
		}
		arr[high]=arr[low];
		//swap(arr[high],arr[low]);
	}
	arr[low]=povit;
	return low;
}

void QuickSort(DataType arr[],int low,int high){
	if(low<high){
		int mid=partition(arr,low,high);
	    QuickSort(arr,low,mid-1);
	    QuickSort(arr,mid+1,high);
	}
}

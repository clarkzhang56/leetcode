/*
输入：
第一行是未排序的一组非负整数,数目不超过10000。以-1作为结束标志。
第二行是要插入的数。
第三行是要删除的数。
输出：
第一行输出自小到大排好序的数。如果没有元素，输出“No elements.”（不包括引号）。
第二行输出插入后自小到大排好序的数，以“,”隔开。
第三行输出删除后自小到大排好序的数，以“,”隔开。如果这个数组是空的了，输出“No elements.”（不包括引号）。
*/
#include "stdio.h"
#define MAX 10000
void quick_sort(int *a,int left,int right){
	 if(left>=right) return ;
	 int bl=left;
	 int br=right;
	 int base=a[left];
	 while(bl<br){
		 while( bl<br && base<a[br]) br--;
		 a[bl] = a[br];
		 while( bl<br && base>=a[bl]) bl++;
		 a[br] = a[bl];
	 }
	 a[bl] = base;
	 quick_sort(a, left, bl-1);
	 quick_sort(a, bl+1, right);
}
int main(){
	int a[MAX];
	int count=0;
	int i;
	while((scanf("%d",&i)) && i!=-1){
		a[count++]=i;
	}
	int m,n;
	scanf("%d %d",&m,&n);
	int j;
	if(count==0)
		printf("No elements.\n");
	else{
		quick_sort(a,0,count-1);
		for(j=0;j<count-1;j++){
			printf("%d,",a[j]);
		}
		printf("%d\n",a[count-1]);
	}
	a[count++]=m;
	quick_sort(a,0,count-1);
	for(j=0;j<count-1;j++){
		printf("%d,",a[j]);
	}
	printf("%d\n",a[count-1]);
	int b[count];
	int k;
	for(j=0,k=0;k<count;k++){
		if(a[k]==n) continue;
		b[j++]=a[k];
	}
	if(j<1){
		printf("No elements.\n");
	}else{
		for(i=0;i<j-1;i++){
			printf("%d,",b[i]);
		}
		printf("%d\n",b[j-1]);
	}
	return 0;
}
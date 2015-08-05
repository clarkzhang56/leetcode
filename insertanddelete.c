/*
���룺
��һ����δ�����һ��Ǹ�����,��Ŀ������10000����-1��Ϊ������־��
�ڶ�����Ҫ���������
��������Ҫɾ��������
�����
��һ�������С�����ź�����������û��Ԫ�أ������No elements.�������������ţ���
�ڶ�������������С�����ź���������ԡ�,��������
���������ɾ������С�����ź���������ԡ�,�������������������ǿյ��ˣ������No elements.�������������ţ���
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
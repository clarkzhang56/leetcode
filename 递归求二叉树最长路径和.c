#include<stdio.h>
int max_path(int a[],int i,int n)
{
	int l,r,m;
	if(i>(n-2)/2)
	{
		return a[i];
	}
	if(2*i+1<n) l=max_path(a,2*i+1,n);
	if(2*i+2<n) r=max_path(a,2*i+2,n);
	if(l>r) m=l; 
	else m=r;
	return m+a[i];
}
int main()
{
	int a[]={55,45,56,44,49};
	printf("%d\n",max_path(a,0,5));
	return 0;
}

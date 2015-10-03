/*
*输入n和m，n表示人数，m表示输入m组2个数，每两个数表示二者是朋友，朋友的朋友
也是自己的朋友，问人员1最后有多少个朋友
*/
#include<stdio.h>
#define MAX 1001
int set[MAX];
int find(int x)
{
	return set[x];//set[x]表示元素x所在集合
    
}
void merge(int a,int b,int n)
{
	int i,x,y,temp;//始终用编号最小的元素标记所在集合
	x=find(a);
	y=find(b);
	if(x==y) return;
	if(x>y){temp=x;x=y;y=temp;}//x表示较小编号的集合
    	for(i=1;i<=n;i++)
		if(set[i]==y) set[i]=x;//我们把所有集合编号为y的全部元素所在集合改为x
}
void main()
{
    int n,m,a,b,i,count;
    while(1){
        scanf("%d%d",&n,&m);
        if(n==0&&m==0) break; 
	for(i=1;i<=n;i++)
        {
            set[i]=i;            
        }
	while(m--)
	{     
            scanf("%d%d",&a,&b);
            merge(a,b,n);
	}
        count=0;
	for(i=1;i<=n;i++)
          if(set[i]==1) count++;
        printf("%d\n",count-1);
    
    }
}
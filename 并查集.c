/*
*����n��m��n��ʾ������m��ʾ����m��2������ÿ��������ʾ���������ѣ����ѵ�����
Ҳ���Լ������ѣ�����Ա1����ж��ٸ�����
*/
#include<stdio.h>
#define MAX 1001
int set[MAX];
int find(int x)
{
	return set[x];//set[x]��ʾԪ��x���ڼ���
    
}
void merge(int a,int b,int n)
{
	int i,x,y,temp;//ʼ���ñ����С��Ԫ�ر�����ڼ���
	x=find(a);
	y=find(b);
	if(x==y) return;
	if(x>y){temp=x;x=y;y=temp;}//x��ʾ��С��ŵļ���
    	for(i=1;i<=n;i++)
		if(set[i]==y) set[i]=x;//���ǰ����м��ϱ��Ϊy��ȫ��Ԫ�����ڼ��ϸ�Ϊx
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
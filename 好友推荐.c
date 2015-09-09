/*
��Ŀ������
��n���ˣ�ÿ���˶��и��Եĺ����б�����һ����ֵp����A��B�Ĺ�ͬ����������p���Ƽ�A��BΪ���ѡ���ʵ���Զ��Ƽ�ֱ��û�к��ѿ����Ƽ���ÿ���Ƽ�Ĭ��ͬ�⣬��һ����Ϊ���ѣ���Ȼ�����һЩ��ѯ�� 
��ѯ1��A�ĺ������м��������A������n�����棬���-1����������������� 
��ѯ2��A��B�Ǻ���������������0���������-1�� 
���룺p n m x y 
pΪ��ֵ��nΪ������mΪ��ʼʱ�ĺ��ѣ�xΪ��ѯ1�ĸ�����yΪ��ѯ2�ĸ���
ע�� 
- ���A��B�ĺ��ѣ�Bһ����A�ĺ��ѣ� 
- ÿ���˵������ò�����20���ַ����ַ�����ʾ��û���������ˣ� 
- ����������100.
����ʾ���� 
2 3 3 3 3 
A 
B 
C 
A B 
B C 
A C 
A 
B 
C 
A B 
C A 
B C 
Ӧ����� 
2 
2 
2 
0 
0 
0
*/
#include <iostream>
#include <cstring>
#define MAX 100
#define name 20
using namespace std;
typedef struct{
	int rs;//���1��ʾ����������
}gh[MAX][MAX];
typedef struct{
	char n[MAX][name];//ÿ���˵�����
	int vexn;			//����
	int arcm;			//�ʼ�Ĺ�ϵ������m
	gh gg;
}Graph;
int locate(Graph g,char *ch){//Ѱ��ĳ����ͼ�е�λ��
	for(int i=0;i<g.vexn;i++){
		if(strcmp(g.n[i],ch)==0)	return i;
	}
	return -1;
}
int main(){
	int p,n,m,x,y;
	Graph g;
	cin>>p>>n>>m>>x>>y;
	g.vexn=n,g.arcm=m;
	for(int i=0;i<n;i++){
		cin>>g.n[i];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			g.gg[i][j].rs=0;
	for(int i=0;i<m;i++){
		int tp1,tp2;
		char t1[name],t2[name];
		cin>>t1>>t2;
		tp1=locate(g,t1);
		tp2=locate(g,t2);
		if(tp1!=-1 && tp2!=-1){
			g.gg[tp1][tp2].rs=g.gg[tp2][tp1].rs=1;
		}
	}
	int count=1;
	while(count!=0){//�������û�����������ӣ���ֹͣ
		count=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int f=0;
				if(g.gg[i][j].rs!=1){
					for(int k=0;k<n;k++){
						if(g.gg[i][k].rs==1 && g.gg[j][k].rs==1)
							f++;
					}
					if(f>=p){
						count++;
						g.gg[i][j].rs=g.gg[j][i].rs=1;
					}
				}
			}
		}
	}
	int *result1=new int[x];//�������1�Ľ��
	int *result2=new int[y];//�������2�Ľ��
	for(int i=0;i<x;i++){
		int tmpnum=0;
		char tmpx[name];
		cin>>tmpx;
		int lo=locate(g,tmpx);
		if(lo!=-1){
			for(int j=0;j<n;j++){
				if(g.gg[lo][j].rs==1)
					tmpnum++;
			}
			result1[i]=tmpnum;
		}else{
			result1[i]=-1;
		}
	}
	for(int i=0;i<y;i++){
		char ty1[name];
		char ty2[name];
		cin>>ty1>>ty2;
		int t1=locate(g,ty1);
		int t2=locate(g,ty2);
		if(t1!=-1 && t2!=-1){
			result2[i]=g.gg[t1][t2].rs;
		}
	}
	for(int i=0;i<x;i++)
		cout<<result1[i]<<endl;
	for(int i=0;i<y;i++){
		if(result2[i]==1){
			cout<<0<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	delete[] result1;
	delete[] result2;

	return 0;
}

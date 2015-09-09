/*
题目描述：
有n个人，每个人都有各自的好友列表。给定一个阈值p，当A和B的共同好友数超过p则推荐A和B为好友。请实现自动推荐直到没有好友可以推荐（每次推荐默认同意，即一定成为好友），然后进行一些查询。 
查询1：A的好友数有几个？如果A不在这n个里面，输出-1，否则输出好友数； 
查询2：A和B是好友吗？如果是则输出0，否则输出-1。 
输入：p n m x y 
p为阈值，n为人数，m为初始时的好友，x为查询1的个数，y为查询2的个数
注： 
- 如果A是B的好友，B一定是A的好友； 
- 每个人的人名用不超过20个字符的字符串表示，没有重名的人； 
- 人数不超过100.
输入示例： 
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
应输出： 
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
	int rs;//存放1表示二者是朋友
}gh[MAX][MAX];
typedef struct{
	char n[MAX][name];//每个人的名字
	int vexn;			//人数
	int arcm;			//最开始的关系数，即m
	gh gg;
}Graph;
int locate(Graph g,char *ch){//寻找某人在图中的位置
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
	while(count!=0){//如果总体没有朋友数增加，就停止
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
	int *result1=new int[x];//存放问题1的结果
	int *result2=new int[y];//存放问题2的结果
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

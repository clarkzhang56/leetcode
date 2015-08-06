/*
	求R的n次幂(0.0<r<99.999,0<n<=25)

	输入

	每行输入两个数R和n

	R值占1-6列，n占8-9列

	输出

	对应于每一行输入，输出R的n次幂

	前导的0不要输出

	无意义的0不要输出

	如果结果是一个整数，不要输出小数点

	最后一行是空行
*/
#include<iostream>
#include<cstring>
#define NUM 150
#define len 8
using namespace std;

int main(){
	int N;
	char arr[NUM];
	int a[len],b[NUM],index;
	while(cin>>arr>>N){
		for(int i=0;i<NUM;i++)
			b[i]=0;
		for(int i=0;i<len;i++)
			a[i]=0;
		if(strlen(arr)!=6 || N<=0 || N>25)
			return -1;
		for(int i=0;i<6;i++){
			if((arr[i]>='0' && arr[i]<='9')||(arr[i]=='.'))
				;
			else
				return -1;
		}
		int x=0;
		for(int i=strlen(arr)-1;i>=0;i--){
			if(arr[i]=='.'){
				index=i;
				continue;
			}else{
				a[x]=(int)(arr[i]-'0');
				b[x]=(int)(arr[i]-'0');
				x++;
			}
		}
		for(int i=1;i<N;i++){
			int c[NUM*2];
			for(int i=0;i<NUM*2;i++){
				c[i]=0;
			}
			for(int j=0;j<len;j++){
				for(int k=0;k<NUM;k++){
					c[j+k] +=(b[k]*a[j]);
				}
			}
			for(int i=0;i<NUM*2;i++){
				if(c[i]>9){
					c[i+1] +=(c[i]/10);
					c[i] %=10;
				}
			}
			for(int i=0;i<NUM;i++){
				b[i]=c[i];
			}
		}
		index =(5-index)*N;
		for(int j=0;j<index;j++){
			if(b[j]!=0){
				if(j!=0){
				b[--j]=10;
				}
				break;
			}
			if(j+1==index)
				b[j]=10;
		}
		int i;
		for(i=NUM-1;i>0;i--){
			if(b[i]!=0)
				break;
			if(i==index){
				i--;
				break;
			}
		}
		for(;i>=0;i--){
			if(b[i]>9){
				break;
			}
			if(i==index-1)
				cout<<"."<<b[i];
			else
				cout<<b[i];
		}
		cout<<endl;
	}
	return 0;
}
/*
����Ŀ��
���������ַ���str1��str2�����������ַ�����������Ӵ���
��������
str1=��1AB2345CD����str2=��12345EF�������ء�2345����
��Ҫ��
���str1����ΪM��str2����ΪN��ʵ��ʱ�临�Ӷ�ΪO(M*N)������ռ临�Ӷ�ΪO(1)�ķ�����

���¸��������ַ���������1��ͨ����ά����dp��ʵ�ֵģ����ŵ��ǹ����Ӵ��ĳ��ȣ�������ֻ��
���ռ临�ӶȽ�ΪO��1�����ѣ�����������˻�ͼ��ԭ��ʱ�临�Ӷ���һ����
*/
#include<iostream>
#include <string.h>
using namespace std;

int main(){
	string str1="1AB2345CDefg";
	string str2="123451CDefgEF";
	int len1=str1.length();
	int len2=str2.length();
	//method 1
	int dp[len1][len2];
	for(int i=0;i<len1;i++){
		if(str1[i]==str2[0])	dp[i][0]=1;
		else					dp[i][0]=0;
	}
	for(int j=0;j<len2;j++){
		if(str2[j]==str1[0])	dp[0][j]=1;
		else					dp[0][j]=0;
	}
	int x=0,max=0;
	for(int i=1;i<len1;i++){
		for(int j=1;j<len2;j++){
			if(str1[i]==str2[j]) dp[i][j]=dp[i-1][j-1]+1;
			else				 dp[i][j]=0;
			if(dp[i][j]>max){
				max=dp[i][j];
				x=i;
			}
		}
	}
	for(int i=x-max+1;i<=x;i++){
		cout<<str1[i];
	}
	//method 2
	cout<<endl;
	int row=0;
	int col=len2-1;
	int maxlen=0,xp=0;
	while(row<len1){
		int i=row;
		int j=col;
		int tmplen=0;
		while(i<len1 && j<len2){
			if(str1[i]==str2[j]){
				tmplen++;
			}else{
				tmplen=0;
			}
			if(tmplen>maxlen){
				maxlen=tmplen;
				xp=i;
			}
			i++;
			j++;
		}
		if(col>0)	col--;
		else		row++;
	}
	for(int i=xp-maxlen+1;i<=xp;i++)
		cout<<str1[i];
	return 0;
}
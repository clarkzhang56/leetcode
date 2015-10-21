/*
���������������
����Ŀ��
���������ַ���str1��str2�����������ַ���������������С�
��������
str1=��1A2C3D4B56����str2=��B1D23CA45B6A����
��123456�����ߡ�12C4B6����������������У�������һ�����С�
�ⷨ��
��һ����ά����dp[i][j]���������str1��0��i��str2��0��j�Ĺ���������
�ĳ��ȣ����������΢�鷳��
*/
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string str1="1A2C3D4B56";
	string str2="B1D23CA45B6A";
	//cin>>str1>>str2;
	int len1=str1.length();
	int len2=str2.length();
	//int **dp=new int[len1][len2];
	int dp[len1][len2];
	for(int i=0;i<len1;i++)
		for(int j=0;j<len2;j++)	
			dp[i][j]=0;
	//��ʼ����1��
	for(int j=0;j<len2;j++){
		if(j>0 && dp[0][j-1]!=0){
			dp[0][j]=1;
			continue;
		} 
		if(str1[0]==str2[j]) dp[0][j]=1;
		else				 dp[0][j]=0;
	}
	//��ʼ����һ��
	for(int i=0;i<len1;i++){
		if(i>0 && dp[i-1][0]!=0){
			dp[i][0]=1;
			continue;
		}
		if(str1[i]==str2[0]) dp[i][0]=1;
		else				 dp[i][0]=0;
	}
	for(int i=1;i<len1;i++){
		for(int j=1;j<len2;j++){
			if(str1[i]==str2[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else if(dp[i][j-1]>dp[i-1][j]){
				dp[i][j]=dp[i][j-1];
			}else dp[i][j]=dp[i-1][j];
		}
	}
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++)	{
			cout<<dp[i][j]<<" ";	
		}
		cout<<endl;
	}
	cout<<"***"<<endl;
	int lr=dp[len1-1][len2-1];
	int tmp1=len1-1;
	int tmp2=len2-1;
	for(int i=tmp1;i>0;i--){
		for(int j=tmp2;j>0;j--){
			while(dp[i][j-1]==lr){
				j--;
			}
			while(dp[i-1][j]==lr) i--;
			cout<<str1[i];
			lr--;
			tmp1=i;
			tmp2=j;
			break;
		}
	}
	if(lr>0){
		int tt=0;
		while(dp[tt][0]==0) tt++;
		cout<<dp[tt][0];
	}
	return 0;
}

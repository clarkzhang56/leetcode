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
	int count=0;
	for(int i=len1;i>=0;i--){
		for(int j=len2-count;j>=i;j--){
			if(i!=0 && dp[i][j]==dp[i-1][j-1]+1 && str1[i]==str2[j]){
				cout<<str2[j];
				count=len2-j;
				break;
			}else if(i==0){
				while(dp[i][j]==1) j--;
				cout<<str2[j+1];
				break;
			}
		}
	}
	cout<<endl<<"*****"<<endl;
	//��Ҫ�������ң������ҳ����Ӻ��濪ʼ�ұȽ����ף����������ǲ��Ե�
	int c2=0;
	for(int i=0;i<len1;i++){
		for(int j=c2;j<len2;j++){
			if(i!=0 && dp[i][j]==dp[i-1][j-1]+1 && str1[i]==str2[j]){
				cout<<str2[j];
				c2=j;
				break;
			}else if(i==0){
				while(dp[i][j]==0) j++;
				cout<<str2[j];
				c2=j;
				break;
			}
		}
	}
	return 0;
}

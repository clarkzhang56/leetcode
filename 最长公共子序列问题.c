/*
最长公共子序列问题
【题目】
给定两个字符串str1和str2，返回两个字符串的最长公共子序列。
【举例】
str1=“1A2C3D4B56”，str2=“B1D23CA45B6A”。
“123456”或者“12C4B6”都是最长公共子序列，返回哪一个都行。
解法：
用一个二维数组dp[i][j]，用来存放str1的0到i和str2的0到j的公共子序列
的长度，输出倒是稍微麻烦点
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
	//初始化第1行
	for(int j=0;j<len2;j++){
		if(j>0 && dp[0][j-1]!=0){
			dp[0][j]=1;
			continue;
		} 
		if(str1[0]==str2[j]) dp[0][j]=1;
		else				 dp[0][j]=0;
	}
	//初始化第一列
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
	//不要从正面找，不能找出，从后面开始找比较容易，所以下面是不对的
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

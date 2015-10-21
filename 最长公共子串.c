/*
【题目】
给定两个字符串str1和str2，返回两个字符串的最长公共子串。
【举例】
str1=“1AB2345CD”，str2=“12345EF”。返回“2345”。
【要求】
如果str1长度为M，str2长度为N，实现时间复杂度为O(M*N)，额外空间复杂度为O(1)的方法。

如下给出了两种方法，方法1是通过二维数组dp来实现的，其存放的是公共子串的长度，方法二只是
将空间复杂度降为O（1）而已，巧妙的利用了画图法原理，时间复杂度是一样的
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
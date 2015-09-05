/*
最长递增子序列
【题目】
给定数组arr，返回arr的最长递增子序列。
【举例】
arr=[2,1,5,3,6,4,8,9,7]，返回的最长递增子序列为[1,3,4,8,9]。
【要求】
如果arr长度为N，请实现时间复杂度为O(N*logN)的方法。
下面程序的解释：
dp存放到第i个数时最长递增子序列的长度，hp是辅助数组，存放到i时最长递增子序列
最后一位放的数值，last为最后输出结果的倒序。
*/
#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int a[9]={2,1,5,3,6,4,8,9,7};
	int hp[9];
	int dp[9];
	for(int i=0;i<9;i++){
		hp[i]=0;
		dp[i]=0;
	}
	int count=0;
	for(int i=0;i<9;i++){
		int flag=-1;
		for(int j=0;j<count;j++){
			if(hp[j]>a[i]){
				flag=j;
				break;
			}
		}
		if(flag<0){
			hp[count]=a[i];
			count++;
			dp[i]=count;
		}else{
			for(int tmp=0;tmp<i;tmp++){
				if(a[tmp]==hp[flag]){
					dp[i]=dp[tmp];
					break;
				}
			}
			hp[flag]=a[i];
		}
	}
	for(int i=0;i<9;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl<<"***"<<endl;
	for(int i=0;i<9;i++){
		cout<<hp[i]<<" ";
	}
	int *last=new int[count];
	for(int i=0;i<count;i++){
		last[i]=0;
	}
	int tt=0;
	for(int i=8;i>=0 && count>0;i--){
		if(dp[i]==count){
			last[tt++]=a[i];
			count--;
		}
	}
	cout<<endl<<"***"<<endl;
	for(int i=tt-1;i>=0;i--){
		cout<<last[i]<<" ";
	}
	delete last;
	return 0;
}
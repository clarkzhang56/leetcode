#include <stdio.h>
/*
*	given a num, do as belows:
*	1. add a num at its left, but the num can't be larger than the source num's half
*	2. after add the num, do it as 1 until there is no num to add
* such as: 6, count the num
* the ideal num is : 6,16,26,126,36,136
*/
static int tmp[1000]={0};
int num(int a){
	if(a==0) return 1;
	if(a==1) return 1;
	int i;
	int count=0;
	for(i=0;i<=a/2;i++){
		if(tmp[i]==0){
			count=count+num(i);
		}else{
			count+=tmp[i];
		}		
	}
	tmp[a]=count;
	return count;
}
int main(){	
	int N;
	scanf("%d",&N);
	if(N<0 && N >1000)
		return -1;
	int count=0;
	count+=num(N);
	printf("%d",count);
	return 0;
}

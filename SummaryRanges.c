#include <stdio.h>
#include <malloc.h>

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
	int len=0,size=8,i,j;
	char** result=(char**)malloc(sizeof(char*)*size);
	for(i=0;i<numsSize;i++){
		//result[len]=(char*)malloc(sizeof(char)*4);
		result[len]=(char*)calloc(24,sizeof(char));
		j=i+1;
		int n1=nums[i],n2=nums[i];
		while(j<numsSize && ((nums[i]+1)==nums[j])){
			n2=nums[j];
			i++;
			j++;
		}
		if(n2!=n1){
			sprintf(result[len],"%d->%d",n1,n2);
		}else{
			sprintf(result[len],"%d",n1);
		}
		len++;
		if(len>=size){
			size*=2;
			result=(char**)realloc(result,sizeof(char*)*size);
		}
	}
	*returnSize=len;
	return result;
}

int main(){
	int i;
	int a[]={0,1,3,5,6,8,9,13,14,15,23,24,44,45,46,89};
//	int a[]={-2147483648,-2147483647,2147483647};
	int n=sizeof(a)/sizeof(int);
	int *num=(int*)malloc(sizeof(int));
	char **b=summaryRanges(a,n,num);
	for(i=0;i<*num;i++){
		printf("%d:%s\n",i,b[i]);
	}

	return 0;
}

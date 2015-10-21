#include <iostream>
using namespace std;
void jose(int a[],int n,int m,int leave){
	int t=n;
	int count=0;
	int i=0;
	while(t>leave){
		if(i==n)	i=0;
		if(a[i]==1){
			count++;
		}
		if(count==m){
			a[i]=0;
			count=0;
			t--;
		}
		i++;
	}
}
int main(){
	cout<<"***"<<endl;
	int nn;
	cin>>nn;
	int *a=new int[nn];
	int i;
	for(i=0;i<nn;i++)
		a[i]=1;
	jose(a,nn,3,1);
	for(i=0;i<nn;i++){
		if(a[i]!=0)	cout<<i+1<<" ";
	}
	delete a;
//method 2
	int f=0;
	for(i=1;i<=nn;i++)
		f=(f+3)%i;
	cout<<endl<<f+1<<endl;
	cout<<endl<<"***"<<endl;
}

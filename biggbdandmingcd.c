/*
	print the greatest common divisor and the least common multiple
*/
#include<iostream>
using namespace std;

int gcd(int x,int y){
	if(x<y)
		return gcd(y,x);
	if(y==0)
			return x;
	else{
		if(x%2==0){
			if(y%2==0){
				return (gcd(x>>1,y>>1)<<1);
			}else{
				return gcd(x>>1,y);
			}
		}else{
			if(y%2==0)
				return gcd(x,y>>1);
			else
				return gcd(y,x-y);
		}
	}
}

int main(){
	int num0,num1;
	cin>>num0>>num1;
	int big_gcd=gcd(num0,num1);
	int min_gbd=(num0/big_gcd)*num1;
	cout<<big_gcd<<" "<<min_gbd<<endl;
	return 0;
}

#include <iostream>
using namespace std;
int getNum(int m,int n){
	if(m<n)	return getNum(n,m);
	if(n==0)	return m;
	return getNum(n,m%n);
}
int main(){
	int m,n;
	while(cin>>m>>n){
		cout<<getNum(m,n)<<endl;
	}
	return 0;
}

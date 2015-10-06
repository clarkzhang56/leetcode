/*
一个32位的unsigned int,两位两位一组，两头互换，最后返回结果（C、C++）实现高效的算法
*/
#include <iostream>
using namespace std;
//此方法是很好的思路
union a{
	unsigned int b;
	struct {
		unsigned int c1:2;
		unsigned int c2:2;
		unsigned int c3:2;
		unsigned int c4:2;
		unsigned int c5:2;
		unsigned int c6:2;
		unsigned int c7:2;
		unsigned int c8:2;
		unsigned int c9:2;
		unsigned int c10:2;
		unsigned int c11:2;
		unsigned int c12:2;
		unsigned int c13:2;
		unsigned int c14:2;
		unsigned int c15:2;
		unsigned int c16:2;
	};
};
unsigned int reverse2(unsigned int u){
	unsigned int r=0;
	unsigned int t[16]={0};
	for(int i=0;i<16;i++){
		t[i]=(u>>2*i)%4;
		t[i]<<=((15-i)*2);
	}
	for(int i=0;i<16;i++){
		r=r|t[i];
	}
	return r;
}
//此方法比较经典，要牢记
unsigned int reverse(unsigned int u)
{
	unsigned int ret=0;
	int count=15;
	while(count)
	{
		ret=ret|(u%4);
		u>>=2;
		ret<<=2;
		count--;
	}
	ret=ret|u%4;
	return ret;
}
int main(){
	unsigned int t=2;
	a aa;
	aa.b=t;
	cout<<aa.b<<endl;
	//交换二者的位置，切记，在VS中下面的写法是错误的，codelite是可以的，可以定义一个unsigned int来当tmp替换
	//unsigned int tmpt=aa.c1;
	//aa.c1=aa.c16;
	//aa.c16=tmpt;
	aa.c1=(aa.c1)^(aa.c16)^(aa.c16=aa.c1);
	aa.c2=(aa.c2)^(aa.c15)^(aa.c15=aa.c2);
	aa.c3=(aa.c3)^(aa.c14)^(aa.c14=aa.c3);
	aa.c4=(aa.c4)^(aa.c13)^(aa.c13=aa.c4);
	aa.c5=(aa.c5)^(aa.c12)^(aa.c12=aa.c5);
	aa.c6=(aa.c6)^(aa.c11)^(aa.c11=aa.c6);
	aa.c7=(aa.c7)^(aa.c10)^(aa.c10=aa.c7);
	aa.c8=(aa.c8)^(aa.c9)^(aa.c9=aa.c8);
	cout<<aa.b<<endl;
	cout<<"*****"<<endl<<t<<endl<<reverse(t)<<endl<<reverse2(t)<<endl;
	return 0;
}

/*
һ��32λ��unsigned int,��λ��λһ�飬��ͷ��������󷵻ؽ����C��C++��ʵ�ָ�Ч���㷨
*/
#include <iostream>
using namespace std;
//�˷����Ǻܺõ�˼·
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
//�˷����ȽϾ��䣬Ҫ�μ�
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
	//�������ߵ�λ�ã��мǣ���VS�������д���Ǵ���ģ�codelite�ǿ��Եģ����Զ���һ��unsigned int����tmp�滻
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

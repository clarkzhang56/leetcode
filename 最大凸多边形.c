/*
��Ŀ������
����һЩ�㣬�����������͹���Ρ������ʼ��Ϊx������ߵĵ㣬����˳ʱ�뷽�������ÿ���������͹���εĶ��㣨��������ϻ�͹�����ڵĵ㣩��
���������� 
3;1,2;2,2;3,3 
��������� 
1,2;3,3;2,2
ע�� 
- �������ݵĵ�һ����Ϊ�����Ŀ��Ȼ���Ƿֺţ��ٺ�������Էֺż���ĵ㣻 
- �����Ŀ����Ϊ3�������Ϊ65535�� 
- ����Ŀ��б����ء�
������Ϊ��������Ҫ���ѵ����ڱ��ϵ���������б����90�ȵ�ʱ���������������Ҫ���ǣ�һ�������ֱ�Ӹ���б�ʾͿ����ҵ��ˡ�
��ͨ��������ߵĵ�A�������A��ֱ���е㣬�����Ϸ��ĵ㣩��ʼ�������ұ�б�����ĵ㣬�Ѹõ���룬ֱ���������ұ����±ߵĵ�B��
���ߵ�ĳ���ʱ�򣬴����������ĵ㲻���ڣ���Ҳֹͣ���ҡ�Ȼ���B�������ң�������������б�����ĵ㣬ֱ���ҵ�A���ҵ�ĳһ�������û��Ϊֹ�������Ǿ���ĳ������
*/
#include <iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int **pt=new int*[N];
	for(int i=0;i<N;i++)
		pt[i]=new int[2];
	for(int i=0;i<N;i++){
		int tN1,tN2;
		cin>>tN1>>tN2;
		pt[i][0]=tN1;
		pt[i][1]=tN2;
	}
	int min=pt[0][0];
	int pmin=0;
	for(int i=1;i<N;i++){
		if(pt[i][0]<min){
			min=pt[i][0];
			pmin=i;
		}else if(pt[i][0]==min){
			if(pt[i][1]>pt[pmin][1])
				pmin=i;
		}
	}
	int max=pt[0][0];
	int pmax=0;
	for(int i=1;i<N;i++){
		if(pt[i][0]>max){
			max=pt[i][0];
			pmax=i;
		}else if(pt[i][0]==max){
			if(pt[i][1]<pt[pmax][1])
				pmax=i;
		}
	}
	int result[100];
	int s=0;
	int tmpmin=pmin;
	while(tmpmin!=pmax){
		result[s++]=tmpmin;
		int temp=tmpmin;
		double tmpangle=-10000;
		for(int i=0;i<N;i++){
			if(i==tmpmin) continue;
			double ttt;
			if(pt[i][0]>pt[tmpmin][0]){
				ttt=(double)(pt[i][1]-pt[tmpmin][1])/(pt[i][0]-pt[tmpmin][0]);
				if(ttt>tmpangle){
					tmpangle=ttt;
					temp=i;
				}
			}
		}
		if(temp==tmpmin){
			tmpmin=pmax;
		}else{
			tmpmin=temp;
		}
	}
	int tmpmax=tmpmin;
	while(tmpmax!=pmin){
		result[s++]=tmpmax;
		int temp=tmpmax;
		double tmpangle=-10000;
		for(int i=0;i<N;i++){
			if(i==tmpmax) continue;
			if((pt[i][0]<pt[tmpmax][0]) && (double)(pt[i][1]-pt[tmpmax][1])/(pt[i][0]-pt[tmpmax][0])>tmpangle){
				tmpangle=(double)(pt[i][1]-pt[tmpmax][1])/(pt[i][0]-pt[tmpmax][0]);
				temp=i;
			}
		}
		if(temp==tmpmax){
			tmpmax=pmin;
		}else{
			tmpmax=temp;
		}
	}
	for(int i=0;i<s;i++){
		cout<<pt[result[i]][0]<<" "<<pt[result[i]][1]<<endl;
	}
	for(int i=0;i<N;i++)
		delete pt[i];
	delete[] pt;
	return 0;
}
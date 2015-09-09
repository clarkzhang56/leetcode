/*
题目描述：
给定一些点，输出最大面积的凸边形。输出起始点为x轴最左边的点，按照顺时针方向输出，每个点必须是凸边形的顶点（不输出边上或凸边形内的点）。
输入样例： 
3;1,2;2,2;3,3 
输出样例： 
1,2;3,3;2,2
注： 
- 输入数据的第一个数为点的数目，然后是分号；再后面就是以分号间隔的点； 
- 点的数目最少为3个，最多为65535； 
- 该题目和斜率相关。
个人认为，本题主要的难点在于边上的两个点倾斜角是90度的时候，这种特殊情况需要考虑，一般情况下直接根据斜率就可以找到了。
我通过从最左边的点A（如果和A垂直的有点，从最上方的点）开始，找其右边斜率最大的点，把该点加入，直到遇到最右边最下边的点B，
或者到某点的时候，大于其横坐标的点不存在，那也停止查找。然后从B点往回找，找其坐标与其斜率最大的点，直到找到A或找到某一点其左边没点为止。下面是具体的程序代码
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
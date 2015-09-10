/*
 * 计算字符串表达式的值，主要考虑优先级，括号和结尾符号
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int fuhao(char c){
	int num;
	switch(c){
	case '+':
	case '-':
		num=1;break;
	case '*':
	case '/':
		num=2;break;
	case '(':
	case ')':
		num=0;break;
	case '#':
		num=-1;break;
	default:
		num=-2;break;
	}
	return num;
}
int getValue(string str){
	stack<int> num;
	stack<char> fh;
	str=str+"#$";
	if(str[0]=='-') str="0"+str;
	int i=0;
	while(str[i]!='$'){
		if(str[i]>='0' && str[i]<='9'){
			int ntmp=str[i]-'0';
			i++;
			while(str[i]>='0' && str[i]<='9'){
				ntmp=ntmp*10+(str[i]-'0');
				i++;
			}
			i--;
			num.push(ntmp);
		}
		else if(fh.size()==0 || str[i]=='(' || fuhao(str[i])>fuhao(fh.top())){
			fh.push(str[i]);
		}
		else if(str[i]==')'){
			for(;fh.top()!='(';fh.pop()){
				int b=num.top();
				num.pop();
				int a=num.top();
				num.pop();
				char ctmp=fh.top();
				switch(ctmp){
				case '+':
					a=a+b;break;
				case '-':
					a=a-b;break;
				case '*':
					a=a*b;break;
				case '/':
					a=a/b;break;
				default:
					break;
				}
				num.push(a);
			}
			fh.pop();
		}
		else{
			for(;fh.size()!=0 && fuhao(fh.top())>=fuhao(str[i]);fh.pop()){
				int b=num.top();
				num.pop();
				int a=num.top();
				num.pop();
				char ctmp=fh.top();
				switch(ctmp){
				case '+':
					a=a+b;break;
				case '-':
					a=a-b;break;
				case '*':
					a=a*b;break;
				case '/':
					a=a/b;break;
				default:
					break;
				}
				num.push(a);
			}
			fh.push(str[i]);
		}
		i++;
	}
	return num.top();
}
int main(){
	string str;
	cin>>str;
	cout<<getValue(str)<<endl;
	cout<<"true"<<endl;

	return 0;
}
#include <iostream>
using namespace std;
void Rorder(char *pF, char *pE)
{
    char temp;
    while (pF <= pE)
    {
        temp = *pF;
        *pF = *pE;
        *pE = temp;
		pF++;
		pE--;
    }
}
void *pszStringRotate(char *pszString, int nCharsRotate)
{
    char *pR = pszString;
    int n = strlen(pszString);
    //while (pszString+(n++)!='\n'); //�õ��ַ�������
    if (n < nCharsRotate) return pR; //��ڲ������
 
    Rorder(pszString, pszString + nCharsRotate-1 ); //C B A
    pszString = pR;//��λ
    Rorder( pszString + nCharsRotate, pszString + n - 1); //GFED
    pszString = pR;
    Rorder(pszString, pszString + n - 1); //DEFGABC
    return pR;
}
int main(){
	char t[10]="abcedfg";
	int n=3;
	pszStringRotate(t,n);
	cout<<t<<endl;
	return 0;
}
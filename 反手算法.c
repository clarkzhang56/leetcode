/*
�ַ�������:
void *pszStringRotate(char *pszString, intnCharsRotate)
����ABCDEFG����3λ��DEFGABC��Ҫ��ռ临�Ӷ�O��1����ʱ�临�Ӷ�O��n��
*/
void Rorder(char *pF, char *pE)
{
    char temp;
    while (pF <= pE)
    {
        temp = *pF;
        *pF = *pE;
        *pE = temp;
    }
}
 
void *pszStringRotate(char *pszString, int nCharsRotate)
{
    char *pR = pszString;
    int n = 0;
    while (pszString + n++ �� = ��\n��); //�õ��ַ�������
    if (n < nCharsRotate) return pR; //��ڲ������
 
    Rorder(pszString, pszString + nCharsRotate ); //C B A
    pszString = pR;//��λ
    Rorder( pszString + nCharsRotate, pszString + n - 1); //GFED
    pszString = pR;
    Rorder(pszString, pszString + n - 1); //DEFGABC
    return pR;
}
/*
字符串左移:
void *pszStringRotate(char *pszString, intnCharsRotate)
比如ABCDEFG，移3位变DEFGABC，要求空间复杂度O（1），时间复杂度O（n）
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
    while (pszString + n++ ！ = ‘\n’); //得到字符串长度
    if (n < nCharsRotate) return pR; //入口参数检测
 
    Rorder(pszString, pszString + nCharsRotate ); //C B A
    pszString = pR;//归位
    Rorder( pszString + nCharsRotate, pszString + n - 1); //GFED
    pszString = pR;
    Rorder(pszString, pszString + n - 1); //DEFGABC
    return pR;
}
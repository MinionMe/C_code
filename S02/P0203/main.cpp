#include<stdio.h>  
int main()
{
    int n1=0,n2=0,n3=0;
    char ch;
    while(1)
    {
        scanf("%c",&ch);
        if(ch==32)     n1++;
        else if(ch==10)n2++;
        else if(ch==35)break;
        else           n3++;
    }
    printf("%d %d %d",n1,n2,n3);
    return 0;
}
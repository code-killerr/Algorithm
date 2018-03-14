#include <stdio.h>
#include <string.h>

char a[2000],b[2000];
int hash[2000],i;

int main()
{
    scanf("%s%s",a,b);
    int len = strlen(a);
    for(i = 0; i<len; i++)
        if(a[i] == b[i])
            hash[i] = 0;
        else
            hash[i] = 1;
    int ans = 0,flag = -1;
    for(i = 0; i<len; i++)
    {
        if(hash[i])
        {
            if(flag == -1)
                flag = i;
            else
            {
                ans+=i-flag;
                flag = -1;
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}

#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);

        long long int mul = 1;
        int temp;
        int countz = 0;
        int min = 9999999999, mininx=-1;

        int a[n], ia=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &temp);
            if(temp==0)
            {
                countz+=1;
                continue;
            }
            mul *= temp;
            if(min>temp)
            {
                min=temp;
                mininx = ia;
            }
            a[ia++] = temp;
        }

        if(countz==1)
            printf("%lld\n", mul);
        else if(countz>1)
            printf("0\n");
        else
        {
            if(mininx==-1)
                mininx=0;
            a[mininx]+=1;
            mul=1;
            for(int i=0; i<ia; i++)
                mul*=a[i];
            printf("%lld\n", mul);
        }
    }
    return 0;
}

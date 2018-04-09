#include<stdio.h>

int party[26];
char name[26];

int  top, topidx, second,secondidx;

void find()
{
    for(int j = 0 ; j< N ; j++ )
    {
        checker(j);
    }
}

void checker(int j)
{
    if(top< party[j])
    {
        if(second < top)
        {
            second = top;
            secondidx = topidx;
        }
        top = party[j];
        topidx = j;
    }
    else
    {
        if(second < party[j])
        {
            second = party[j];
            secondidx = j;
        }
    }
}
int main()
{
    int half,N,T,sum;

    scanf("%d\n",&T);

    for( int i = 1 ; i <= T ; i++ )
    {
        scanf("%d\n",&N);
        sum = 0;
        top = 0;
        second = 0;
        topidx = 0;
        secondidx = 0;
        for(int j = 0 ; j< N ; j++ )
        {
            scanf("%d",party + j);
            name[j] = 'A' + j;
            sum += party[j];
            checker(j);
        }

        printf("Case #%d:",T);

        while(sum>0)
        {
            if(sum)
            half = sum/2;

            if(second >= half)
            {
                find();
                continue;
            }
            else if(top > 1)
            {
                printf(" %c%c",'A'+topidx,'A'+topidx);
                party[topidx] -= 2;
                top -= 2;
                sum -= 2;
            }else if( top > 0 )
            {
                printf(" %c",'A'+topidx);
                party[topidx] --;
                top --;
                sum --;
            }
            else
            {
                find();
            }
        }
    }
    return 0;
}

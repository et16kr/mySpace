#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int N;
int    top_odr[1001];
int    side_odr[1001];
double side[1001];
double top[1001];

void quickSort( double * size, int * odr, int left, int right )
{
    int     i = left;
    int     j = right;
    int     tmpIdx;
    int     pivot = odr[(left + right) / 2];

    while (i <= j)
    {
        while (size[odr[i]] > size[pivot])
        {
            i++;
        }

        while (size[odr[j]] < size[pivot])
        {
            j--;
        }

        if (i <= j)
        {
            tmpIdx = odr[i];
            odr[i] = odr[j];
            odr[j] = tmpIdx;

            i++;
            j--;
        }
    };

    if (left < j)
    {
        quickSort(size,odr, left, j);
    }

    if (i < right)
    {
        quickSort( size,odr, i, right);
    }
}

int main()
{
    FILE * sFileIn;
    FILE * sFileOut;
    int T,K,R,H,KCnt;
    int sTestCnt;
    double sum, max;

    sFileIn  = fopen( "A-large-practice.in", "r");
    sFileOut = fopen( "a.out", "w+");

    fscanf( sFileIn, "%d\n", &sTestCnt );

    for( int i = 1 ; i <= sTestCnt ; i++ )
    {
        fscanf( sFileIn, "%d %d\n", &N, &K );

        for( int j = 0 ; j < N ; j++ )
        {
            fscanf( sFileIn, "%d %d\n", &R, &H );

            side[j]     = 2 * M_PI * R * H;
            side_odr[j] = j;
            top[j]      = M_PI * R * R ;
            top_odr[j]  = j;
        }

        quickSort(top,top_odr,0,N-1);
        quickSort(side,side_odr,0,N-1);

        max = 0;
        for( int j = 0 ; j < (N - K + 1) ; j++ )
        {
            sum = top[top_odr[j]] + side[top_odr[j]];

            KCnt = 1;
            for(int k = 0 ; k < N ; k++ )
            {
                if( KCnt >= K )
                {
                    break;
                }

                if(top_odr[j] == side_odr[k] )
                {
                    continue;
                }

                if( top[top_odr[j]] < top[side_odr[k]] )
                {
                    continue;
                }
                sum += side[side_odr[k]];
                KCnt++;
            }

            if( KCnt < K )
            {
                continue;
            }

            if( max < sum )
            {
                max = sum;
            }
        }
        fprintf(sFileOut,"Case #%d: %.8lf\n",i,max);
    }
    fclose(sFileIn);
    fclose(sFileOut);

    return 0;
}

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

int main ()
{
    int T, N,P;
    int tmp;
    int H;
    int W;
    double min,max;

    cout.precision(8);

    cin >> T;

    for( int Case = 1 ; Case <= T ; Case ++ )
    {
        cin >> N >> P ;

        min = 0.0;
        max = 0.0;
        for( int i = 0 ; i < N ; i++ )
        {
            cin >> H >> W;
            min += H + H + W + W;
            tmp = (H*H) + (W*W);
            max += sqrt(tmp)*2;
        }

        max += min;

        if( max < (double)P )
        {
            cout << "Case #" << Case << ": " << max << "\n";
            continue;
        }
        else
        {
            cout << "Case #" << Case << ": " << (double)P << "\n";
        }
    }
    return 0;
}

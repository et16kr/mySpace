#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

int main ()
{
    int T, N,P0, P1;
    int tmp;
    int H, W;
    double min[101];
    double max[101];

    cout.precision(8);

    cin >> T;

    for( int Case = 1 ; Case <= T ; Case ++ )
    {
        cin >> N >> P0 ;
        P1 = P0;

        for( int i = 0 ; i < N ; i++ )
        {
            cin >> H >> W;
            P1 -= H + H + W + W;
            min[i] = ( H > W ? W : H )*2;
            max[i] = sqrt( (H*H) + (W*W) )*2 ;
        }

        
        // ...
        
        
        if( .. )
        {
            cout << "Case #" << Case << ": " << max << "\n";
            continue;
        }
        else
        {
            cout << "Case #" << Case << ": " << P0 << "\n";
        }
    }
    return 0;
}

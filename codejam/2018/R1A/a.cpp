#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main ()
{
    int T, R,C,H,V,total;
    char waf[101][101];
    int Rcnt [101];
    int Ccnt [101];
    int Hpos [102];
    int Vpos [102];
    bool sResult = true;
    int part, target ,i,j;

    cin >> T;

    for( int Case = 1 ; Case <= T ; Case ++ )
    {
        cin >> R >> C >> H >> V ;

        memset( Rcnt, 0 , R * sizeof(int));
        memset( Ccnt, 0 , C * sizeof(int));

        total = 0;

        for( i = 0 ; i < R ; i++ )
        {
            cin >> waf[i];
            for( j = 0 ; j < C ; j++ )
            {
                if( waf[i][j] == '@')
                {
                    Rcnt[i]++;
                    Ccnt[j]++;
                    total++;
                }
            }
        }

        if( total == 0 )
        {
            cout << "Case #" << Case << ": POSSIBLE\n";
            continue;
        }

        if(( total % (( H+1 ) * (V+1))) != 0 )
        {
            cout << "Case #" << Case << ": IMPOSSIBLE\n";
            continue;
        }

        part = 0;
        j    = 1;
        Hpos[0] = 0;
        target = total / (H+1);

        for( i = 0 ; i < R ; i++ )
        {
            part += Rcnt[i];

            if( part == target )
            {
                Hpos[j] = i+1;
                j++;
                part = 0;
            }
            else if( part > target )
            {
                break;
            }
        }

        if(( i != R ) || (part != 0 ))
        {
            cout << "Case #" << Case << ": IMPOSSIBLE\n";
            continue;
        }

        part = 0;
        j    = 1;
        Vpos[0] = 0;
        target = total / (V+1);
        for( i = 0 ; i < C ; i++ )
        {
            part += Ccnt[i];

            if( part == target )
            {
                Vpos[j] = i+1;
                j++;
                part = 0;
            }
            else if( part > target )
            {
                break;
            }
        }

        if(( i != C ) || (part != 0 ))
        {
            cout << "Case #" << Case << ": IMPOSSIBLE\n";
            continue;
        }
        Hpos[H+1] = R;
        Vpos[V+1] = C;

        part = 0;
        target = total / ((H+1)*(V+1));
        sResult = true;

        for( i = 0 ; i <= H ; i++ )
        {
            for( j = 0 ; j <= V ; j++ )
            {
                // Hpos[i] ~ ( Hpos[i+1] -1 )
                // Vpos[j] ~ ( Vpos[j+1] -1 )
                // part == target
                part = 0;
                for( int k = Hpos[i] ; k < Hpos[i+1] ; k++ )
                {
                    for( int l = Vpos[j] ; l < Vpos[j+1] ; l++ )
                    {
                        if( waf[k][l] == '@' )
                        {
                            part++;
                        }
                    }
                }
                if( part != target )
                {
                    sResult = false;
                    break;
                }
            }
            if( sResult == false )
            {
                break;
            }
        }

        if( sResult == true )
        {
            cout << "Case #" << Case << ": POSSIBLE\n";
        }
        else
        {
            cout << "Case #" << Case << ": IMPOSSIBLE\n";
        }
    }

    return 0;
}

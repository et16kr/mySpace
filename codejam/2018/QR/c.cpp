#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main ()
{
    int T, A, sum, leftX, x, y;
    char ground[200][5];

    cin >> T;

    for( int Case = 0 ; Case < T ; Case ++ )
    {
        cin >> A ;
        memset( ground, 0 , 200*5);

        // y = 2; x = 2 ~ 49
        leftX = 1;
        sum = 0;

        while( sum < ( A - 6 ) )
        {
            if (( ground[leftX][1] + ground[leftX][2] + ground[leftX][3] ) == 3 )
            {
                leftX ++;
                sum += 3;
            }
            else
            {
                do
                {
                    cout << leftX+1 << " " << 2 << '\n';
                    cin >> x >> y ;

                    if( x == -1 )
                    {
                        return 0;
                    }
                    if( x == 0 )
                    {
                        break;
                    }

                    ground[x][y] = 1;

                } while( leftX != x );

                if( x == 0 )
                {
                    break;
                }
            }
        }
        while( x != 0 )
        {
            cout << leftX << ' ' << 2 << '\n';
            cin >> x >> y ;
            if( x == -1 )
            {
                return 0;
            }
            ground[x][y] = 1;
        }
    }
    return 0;
}

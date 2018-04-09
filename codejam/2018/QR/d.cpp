#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

using namespace std;

int main ()
{
    int T;
    double area,a,b,res1,res2,sq, temp;

    cout.precision(15);
    cin.precision(15);

    cin >> T;

    for( int Case = 1 ; Case <= T ; Case ++ )
    {
          cin >> area ;
         // area = 1.2;
        // b1+ b2 = area
        // x^2 + bx + c = 0
        // b = - area
        // c = (area^2 - 1 )/2
        // x = (area +- R (2 - area^2))/2

        temp = 2 - ( area * area );
        temp = abs(temp);
        sq = sqrt( temp );
        a = (area - sq)/2;
        b = (area + sq)/2;
        res1 = (area-a)/2;
        res2 = (area-b)/2;

        cout << "Case #"<< Case<<":\n";
        cout << res1 << ' ' << res2 <<' ' << 0 <<"\n" ;
        cout << res2 * -1 << ' ' << res1 <<' ' << 0 <<"\n" ;
        cout << 0 << ' ' << 0 <<' ' << 0.5 <<"\n" ;
    }
    return 0;
}

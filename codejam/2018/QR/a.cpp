#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main ()
{
    int T, length, change;
    long long int D, attack,power;
    long long int shoot[30];
    char robot[31];

    cin >> T;

    for( int Case = 1 ; Case <= T ; Case ++ )
    {
        cin >> D >> robot ;
        length = strlen(robot);

        power = 1;
        attack = 0;

        for( int i = 0 ; i < length ; i++ )
        {
            if( robot[i] == 'C' )
            {
                power *= 2;
            }
            else if( robot[i] == 'S')
            {
                attack += power;
                shoot[i] = power;
            }
            else
            {
                cout << "error\n";
            }
        }

        change = 0;

        for( int i = length - 1 ; i >= 0 ; i-- )
        {
            if( attack <= D )
            {
                break;
            }
            if( robot[i] == 'S' )
            {
                if(( i > 0 ) &&
                   ( robot[ i -1 ] == 'C' ))
                {
                    robot[i-1] = 'S';
                    robot[i]   = 'C';
                    shoot[i-1] = shoot[i]/2;
                    shoot[i]   = 0;
                    attack    -= shoot[i-1];
                    change++;
                    i         += 2;
                    //       cout << "[ " << change << "] "  << robot << " : " << attack << '\n';
                    continue;
                }
            }
        }
        cout << "Case #" << Case << ": " ;
        if( attack <= D )
        {
            cout << change << '\n';
        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}

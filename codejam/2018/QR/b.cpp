#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int value[100000];
int idx[100000];


void quickSort( int left, int right) {

    int i = left, j = right;
    int tmpValue;
    int tmpIdx;
    int pivot = value[(left + right) / 2];

    while (i <= j)
    {
        while (value[i] < pivot)
        {
            i++;
        }

        while (value[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            tmpValue = value[i];
            value[i] = value[j];
            value[j] = tmpValue;

            tmpIdx = idx[i];
            idx[i] = idx[j];
            idx[j] = tmpIdx;

            i++;
            j--;
        }
    };

    if (left < j)
    {
        quickSort( left, j);
    }

    if (i < right)
    {
        quickSort( i, right);
    }
}

int main ()
{
    int T, N, i;
    int res0, res1;
    int start;
    int count[2];

    cin >> T;

    for( int Case = 1 ; Case <= T ; Case ++ )
    {
        cin >> N  ;
        for( i = 0 ; i < N ; i++ )
        {
            cin >> value[i];
            idx[i] = i;
        }

        quickSort(0,N-1);

        for( i = 0 ; i < N ; i++ )
        {
            if( idx[i]%2 != i%2 )
            {
                if( ( i > 0 ) &&
                    ( value[i-1] == value[i] ))
                {
                    continue;
                }

                if( ( i < N - 1 ) &&
                    ( value[i] == value[i+1] ))
                {
                    continue;
                }

                break;
            }
        }
        res0 = i;

        res1 = N;
        start = -1;
        count[0] = 0;
        count[1] = 0;

        for( i = 0 ; i < N - 1 ; i++ )
        {
            if( value[i] == value[i+1])
            {
                if( start == -1 )
                {
                    count[idx[i]%2]++;
                    start = i;
                }
                count[idx[i+1]%2]++;
            }
            else
            {
                if( start != -1 )
                {
                    // 정리 계산
                    if(( count[0] != count[1] ) &&
                       ((count[start%2] != (count[(start+1)%2] + 1 ) )))
                    {
                        if( count[0] > count[1] )
                        {
                            res1 = count[1] * 2 + start;
                            if(start%2 == 0) res1++;
                        }else
                        {
                            res1 = count[0] * 2 + start;
                            if(start%2 == 1) res1++;
                        }

                        break;
                    }
                    start = -1;
                    count[0] = 0;
                    count[1] = 0;
                }
            }
        }
        if( res1 == N )
        {
            if( start != -1 )
            {
                // 역시 정리
                if(( count[0] != count[1] ) &&
                   ((count[start%2] != (count[(start+1)%2] + 1 ) )))
                {
                    if( count[0] > count[1] )
                    {
                        res1 = count[1] *2 + start;
                        if(start%2 == 0) res1++;
                    }else
                    {
                        res1 = count[0] *2 + start;
                        if(start%2 == 1) res1++;
                    }
                }
            }
        }
        cout << "Case #" << Case << ": " ;

        if(( res0 == N ) && ( res1 == N ))
        {
            cout << "OK\n";
        }
        else
        {
            if(res0 < res1 )
            {
                cout << res0 << '\n';
            }
            else
            {
                cout << res1 << '\n';
            }
        }
    }
    return 0;
}

#include<iostream>
using namespace std;

//TOO_SMALL;
//CORRECT;
//TOO_BIC;
//WRONG_ANSWER;

int main()
{
    int T, N;
    long long int A, B, curr;
    char result[20];

    cin >> T;

    for( int i = 0 ; i < T ; i++ )
    {
        cin >> A >> B;
        cin >> N;
        for( int j = 0 ; j < N ; j++ )
        {
            curr = (A + B) / 2;
            cout << curr << '\n';
            cin >> result;
            switch(result[4])
            {
                case 'S':
                    A = curr + 1;
                    break;
                case 'B':
                    B = curr ;
                    break;
                case 'E':
                    j = N;
                    break;
                case 'G':
                    return 0;
                default:
                    break;
            }
        }
    }
    return 0;
}

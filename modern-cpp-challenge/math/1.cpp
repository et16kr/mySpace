#include<iostream>

using namespace std;

long long int sum1toNum( long long int input )
{
    return (1 + input) * (input/2) + ((input%2)*(input/2+1));
}

long long int sumUnderMultiples( long long int max , long long int by)
{
    return sum1toNum( max / by ) * by ;
}

int main()
{
    long long int input,sum;

    cout << "Input Number : " ;

    cin >> input;

    sum =  sumUnderMultiples(input,5) + sumUnderMultiples(input,3) - sumUnderMultiples(input , 15);
    cout << "Result : " << sum << endl;

    return 0;
}

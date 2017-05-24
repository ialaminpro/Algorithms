/**************************************************************************
***   Problem No    : 3                                                 ***
***   Problem Name  : Binary Search                                     ***
***   Type          : Search                                            ***
***   Author        : Al-Amin                                           ***
***   E-mail        : ialamin.pro@gmail.com/alamin.iyakub@diu.edu.bd    ***
***   University    : DIU, Dept. of CSE                                 ***
***   Facebook      : http://www.facebook.com/alamin25                  ***
***************************************************************************/

/**********************Template Starts Here***********************/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#include <cctype>
#include <set>
#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define popcount (int)__builtin_popcount

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef vector < int > vi;
typedef pair < int, int > ii;
typedef pair < vlong, vlong > lili;
typedef vector < ii > vii;
typedef pair < double, double >  pdd;

template < class T > T sq( T x ) { return x * x; }

const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;
const vlong maxint = 2147483647;
const vlong minint = -2147483648;
const double degtorad = pi/180;
const double radtodeg = 180/pi;
/*******************Template Interval Here****************/

/*******************All Function Here*********************/

vlong gcd ( vlong a, vlong b ) {
    if ( a < 0 ) a *= -1; if ( b < 0 ) b *= -1;
    while ( b ) {
        a = a % b;
        swap ( a, b );
    }
    return a;
}

vlong lcm ( vlong a, vlong b ) {
    return ( a / gcd ( a, b ) ) * b;
}

vlong power ( vlong a, vlong p ) {
    vlong res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = res * x;
        x = x * x;
        p >>= 1;
    }
    return res;
}
/*******************Function Interval Here****************/


int main()
{
    int array[100],f,i,j,n,search_value;

    #ifdef localhost
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


        cout <<"Enter number of elements\n";
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> array[i];
        }

    while (1)
    {
        sort(array,array+i);
        cout <<"Enter value to find\n";
        cin >> search_value;

            int low = 0;
            int high = n - 1 ;
            int mid;
            f = 0;
            while (low <= high)
            {
                mid = (low + high) / 2;

                if(search_value == array[mid])
                {
                   cout << "The number " << array[mid] << " was found at location " << mid <<'\n';
                     f=1;
                    break;
                }
                else if(search_value>array[mid])
                {
                    low = mid + 1;
                }
                else
                {
                   high = mid -1;
                }

            }
            if(f==0)
            {
                cout<< "The number " <<search_value << " was not found.\n ";
            }
    }

    return 0;
}

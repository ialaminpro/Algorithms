/***********************************************************
***  Problem Name   : Insertion Sort                     ***
***  Problem Type   : Sort                               ***
***  Author         : Al-Amin                            ***
***  E-mail         : alamin.iyakub@diu.edu.bd           ***
***  University     : DIU , Dept. of CSE                 ***
***  Facebook       : alamin2625                         ***
***********************************************************/

/******************Template Starts Here********************/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
#include <cctype>
#include <set>



#define sf scanf
#define pf printf

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;

/******************Template Interval Here************************/

/*********************All Function Here*************************/
vlong gcd ( vlong a, vlong b )
{
    if ( a < 0 )a *= -1;
    if ( b < 0 )b *= -1;
    while(b)
    {
        a = a % b;
        swap ( a , b );
    }
    return a;
}

vlong lcm( vlong a, vlong b)
{
    return ( a / gcd ( a , b ) ) * b;
}

vlong power( vlong a, vlong p)
{
    vlong res = 1 , x = a;
    while(p)
    {
        if( p & 1) res *= x;
        x = x * x;
        p >>= 1;
    }
    return res;
}
/********************Function Interval Here**********************/

int main()
{

  int n, array[110], i, key, d, temp, j;

    #ifdef localhost
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

while (1)
{
      pf("Enter number of elements\n");
      sf("%d", &n);

      pf("Enter %d integers\n", n);

      for (i = 1; i <= n; i++) {
        sf("%d", &array[i]);
      }

      for (j = 2 ; j <= n ; j++) {
        key = array[j] ;
        i = j - 1;
        while ( i > 0 && array[i] > key) {
          temp = array[i];
          array[i] = array[ i + 1];
          array[i + 1] = temp;
          i --;
        }

      }

      pf("Sorted list in ascending order:\n");

      for (i = 1; i <= n ; i++) {
        pf("%d ", array[i]);
      }
}

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

void primos(int n, int v[]);

int main()
{
    int i, n = 100; // find the primes up to 500000
    int v[n];
    primos(n, v);
    for (i=0;i<n;i++)
        if (v[i] == 1)
            printf("%d\n",i); // this just prints out each value if it's Prime

    return 0;
}

void primos(int n, int v[])
{
    int i, j, cuadrado;
    cuadrado = n*n;
    for(i=0;i<n;i++)
        v[i]=1; // we initialize the sieve list to all 1's (True)
    v[0]=0,v[1]=0; // Set the first two numbers (0 and 1) to 0 (False)
    for (i=2;i<cuadrado;i++) // loop through all the numbers up to the sqrt(n)
        for (j=i*i;j<n;j+=i) // mark off each factor of i by setting it to 0 (False)
            v[j] = 0;
}

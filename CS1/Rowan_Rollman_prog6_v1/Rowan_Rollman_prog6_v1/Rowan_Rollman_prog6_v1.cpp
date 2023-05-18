#include <iostream>
#include <stdio.h>
using namespace std;

int happy_iteration(int n);
bool is_happy(int n);
void SieveOfEratosthenes(bool prime[]);
int main()
{
    int currNum = 2;
    int happyprime_count = 0;
    bool prime[1000001];
    for (int i=0; i<1000001; i++) {//initializes the entire array as true
        prime[i] = true;
    }
    SieveOfEratosthenes(prime);
    for (currNum = 2; currNum < 1000000; currNum++) {
        if (is_happy(currNum)) {
            if (prime[currNum]) {
                ++happyprime_count;
            }
        }
    }
    printf ("There are %d happy prime numbers between 1 and 1 million.\n", happyprime_count);
}

int happy_iteration(int n)
{
    int result = 0;
    while (n>0) {
        int lastdig = n%10;
        result += lastdig*lastdig;
        n /= 10;
    }
    return result;
}

bool is_happy(int n) //uses Floyd's cycle finding algorithm
{
    int n2 = happy_iteration(n);
    while (n != n2) {
        n = happy_iteration(n);
        n2 = happy_iteration(happy_iteration(n2));
    }

    return n == 1;
}

void SieveOfEratosthenes(bool prime[])
{
    for (int p=2; p*p <= 1000001; p++) {
        if (prime[p] == true) { //if prime p doesn't change, it is prime
            for (int i = p*p; i <= 1000001; i += p) {//updates the numbers we are checking
                prime[i] = false;
            }
        }
    }
}

#include <omp.h>
#include <stdio.h>
using namespace std;

int happy_checking(int n);
bool is_happy(int n);
void SieveOfEratosthenes(bool prime[]);
int main()
{
    int currNum = 2;
    int happyprime_count = 0;
    bool prime[1000001];
    for (int i=0; i<1000001; i++) { //initializes the entire array as true
        prime[i] = true;
    }
    
    SieveOfEratosthenes(prime);
    
    #pragma omp parallel for num_threads(16)
    for (currNum = 2; currNum < 1000000; currNum++) {
        if (is_happy(currNum)) {
            if (prime[currNum]) {
                #pragma omp atomic
                ++happyprime_count;
            }
        }
    }
    printf ("There are %d happy prime numbers between 1 and 1 million.\n", happyprime_count);
}

int happy_checking(int n)
{
    int result=0;
    while (n>0) {
        int lastdig = n%10;
        result += lastdig*lastdig;
        n /= 10;
    }
    return result;
}

bool is_happy(int n) //uses Floyd's cycle finding algorithm
{
    int n2 = happy_checking(n);
    while (n != n2) {
        n = happy_checking(n);
        n2 = happy_checking(happy_checking(n2));
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

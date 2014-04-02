#include<string>
#include<math>
#include<iostream>

using namespace std;

class BigFatInteger2
{
public:
    string isDivisible(int A,int B,int C,int D)
    {
        int a;
        a = gcd(A,C);
        a = primeFactors(a);
        if(a==1)
        {
            return "not divisible";
        }
        else if((B*(A/a))>=(D*(C/a)))
        {
            return "divisible";
        }
        return "not divisible";
    }

    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    int primeFactors(int n)
    {
        // Print the number of 2s that divide n
        while (n%2 == 0)
        {
            return 2;
            n = n/2;
        }

        // n must be odd at this point.  So we can skip one element (Note i = i +2)
        for (int i = 3; i*i <= (n); i = i+2)
        {
            // While i divides n, print i and divide n
            while (n%i == 0)
            {
                return i;
                n = n/i;
            }
        }

        // This condition is to handle the case whien n is a prime number
        // greater than 2
        if (n > 2)
            return n;
    }
};

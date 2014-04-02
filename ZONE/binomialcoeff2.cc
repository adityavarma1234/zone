#include <stdio.h>

typedef unsigned long long uInt64;

int modularPower1009(int base, int exponent)
{
    int res = 1;
    while (exponent)
    {
        if (exponent & 1)
            res = (res * base) % 1009;
        exponent >>= 1;
        base = (base * base) % 1009;
    }
    return res;
}
int main()
{
    int t;
    freopen("input.txt","r",stdin);
    int fact[1010], factMultInv[1010], p = 1, q = 1;
    fact[0] = factMultInv[0] = 1;
    for (t = 1; t <= 1009; ++t)
    {
        p *= t;
        p %= 1009;
        fact[t] = p;

        q *= modularPower1009(t, 1007);
        q %= 1009;
        factMultInv[t] = q;
    }

    scanf("%d", &t);
    while (t--)
    {
        uInt64 n, k;
        int result = 1;
        scanf("%llu%llu", &n, &k);
        while (n)
        {
            int N = n % 1009;
            int K = k % 1009;
            if (N < K)
            {
                result = 0;
                break;
            }
            result *= (fact[N] * factMultInv[K] * factMultInv[N - K]) % 1009;
            result %= 1009;
            n /= 1009;
            k /= 1009;
        }
        printf("%d\n", result);
    }
    return 0;
}

#from sys import stdin,stdout
def exp(a,b):
    result = 1
    while(b!=0):
        if(b%2):
            result = ((result%10000000007)*(a%10000000007))%10000000007
        b = b/2
        a = a*a
    return result%10000000007
T = int(input())
while(T!=0):
    T = T-1
    num = input().split()
    ans = exp(int(num[0]),int(num[1])%10000000006)
    print(ans)
    
    

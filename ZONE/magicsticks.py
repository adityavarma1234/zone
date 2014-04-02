from sys import stdin,stdout

T = int(stdin.readline())
for t in range(T):
    N = int(stdin.readline())
    num = [int(i) for i in stdin.readline().split()]
    a,b,c = [int(i) for i in stdin.readline().split()]
    string = stdin.readline().strip()
    A = 0
    M = 1
    flag = 0
    start = 0
    end = N-1
    rev = 0
    temp = ''
    for i in range(N):
        if string[i]=='R':
            rev = 1 if rev==0 else 0
        elif string[i]=='A':
            A = (A+a)%c
            flag = 1
        elif string[i]=='M':
            M = (M*b)%c
            A = (A*b)%c
            flag = 1
        if(rev==1):
            ans = num[end]%c
            end = end-1
        else:
            ans = num[start]%c
            start = start+1
        if(flag==1):
            ans = (((ans*M)%c)+(A%c))%c
        temp += str(ans) + ' '
        #stdout.write(temp)
    temp += '\n'
    stdout.write(temp)

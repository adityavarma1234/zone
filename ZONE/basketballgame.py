T = int(input())
for t in range(1,T+1):
    a = input().split()
    N = int(a[0])
    M = int(a[1])
    P = int(a[2])
    players = []
    for i in range(0,N):
        temp = input().split()
        players.append(temp)
    

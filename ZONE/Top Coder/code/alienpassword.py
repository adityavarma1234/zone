import math
class AleinAndPassword:
    def getNumber(self,S):
        ans = 0
        S = name
        l = len(name)
        ans = math.factorial(name)
        d = {}
        for i in name:
            if(d.has_key(i)==False):
                count = 0
                d[i] = 1
                for j in name:
                    if i==j:
                        count += 1
                ans = ans/math.factorial(count)
        return ans

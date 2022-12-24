class Solution:
    def numTilings(self, n: int) -> int:
        @cache
        def f(i,flag):
            if(i>n):
                return 0;
            if(i==n):
                return not flag;
            if(flag):
                return (f(i+1,False) + f(i+1,True));
            return (f(i+1,False)+2*f(i+2,True)+f(i+2,False));
             
        return f(0,False) % 1_000_000_007;
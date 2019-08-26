def dfs(n):
    if(n==0):
        return 0;
    if(n&1):
        return n*n*n*b+(n-1)*n*n*a;
    else:
        R=7*dfs(n//2+18*(n/2)*(n/2))
if __name__ == '__main__':
    slove()

while True :
    try :
        k , n = map(int,input().split())
        dp = [[0 for i in range(k + 1)] for j in range(n)]
        for i in range(k + 1) :
            dp[n - 1][i] = 1

        for i in range(n - 2 , - 1 , -1) :
            for j in range(k  , -1 , -1) :
                dp[i][j] += dp[i + 1][j]
                if(j + 1 <= k) :
                    dp[i][j] += dp[i + 1][j + 1]
                if(j - 1 > -1) :
                    dp[i][j] += dp[i + 1][j - 1]

        ans = 0
        for i in range(k + 1):
            ans += dp[0][i]
        total = (k + 1)**n
        print(format(((ans / total) * 100) ,'.5f'))
    except EOFError :
        break
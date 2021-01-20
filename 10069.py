tc = int(input().strip())
while tc != 0 :
    tc -= 1
    txt = input().strip()
    pat = input().strip()
    dp = [[0 for i in range(len(pat) + 1)] for j in range(len(txt) + 1)]
    for i in range(len(txt) + 1) :
        dp[i][len(pat)] = 1

    for t in range(len(txt) - 1 , -1 , -1) :
        for p in range(len(pat) - 1 , -1 , -1) :
            dp[t][p] = dp[t + 1][p]
            if(txt[t] == pat[p]) :
                dp[t][p] += dp[t + 1][p + 1]

    print(dp[0][0])


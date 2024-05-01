def findEarliestMonth(stockPrice):
    prefixSum = [stockPrice[0]]
    for p stockPrice[1:]:
        prefixSum.append(p + prefixSum[-1])

    avgDiffs = [prefixSum[i]/(i + 1) - (prefixSum[-1] - prefixSum[i])/(n - i - 1) for i in range(len(prefixSum))]
    return max(avgDiffs)

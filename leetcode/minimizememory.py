def minimizeMemory(processes, m):
    l = 0
    curr = 0
    biggest = -1
    totalMem = 0

    for i in range(len(processes)):
        totalMem += processes[i]
        curr += processes[i]
        if i < m:
            biggest = curr
        else:
            curr -= processes[l]
            l += 1
            biggest = max(biggest, curr)

    return totalMem - biggest




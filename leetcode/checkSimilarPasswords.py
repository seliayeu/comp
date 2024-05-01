def matchChar(oldChar, newChar):
    if oldChar == newChar:
        return True
    if oldChar == 'z':
        newChar = 'a'
    else:
        newChar = chr(ord(oldChar) + 1)
    return newChar == oldChar

def comparePasswords(oldPassword, newPassword):
    j = 0

    while i < len(oldPassword) and j < len(newPassword):
        if matchChar(oldPassword[i], newPassword[i]):
            j += 1
        i += 1
    if j == len(newPassword):
        return True
    return False

def checkSimilarPasswords(oldPasswords, newPasswords):
    return [ 'YES' if comparePasswords(oldPasswords[i], newPasswords[i]) else 'NO' for i in range(len(newPasswords)]

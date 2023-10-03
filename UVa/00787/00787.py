def main():
    while True:
        try:
            line = input()
        except EOFError:
            break

        nums = line.split(" ")[:-1]
        nums = [int(num) for num in nums]

        prod = 1
        best = float("-inf")

        for i in range(len(nums)):
            prod *= nums[i]
            best = max(prod, best)
            if prod == 0:
                prod = 1
        prod = 1
        for i in range(len(nums) - 1, -1, -1):
            prod *= nums[i]
            best = max(prod, best)
            if prod == 0:
                prod = 1
        
        print(best)


if __name__ == "__main__":
    main()

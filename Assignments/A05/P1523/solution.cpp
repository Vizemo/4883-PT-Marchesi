class Solution:
    def countOdds(self, low: int, high: int) -> int:
        # Calculate how many odd numbers exist between low and high
        oddNums = (high - low) // 2

        # Check if the range between low and high is odd
        if (high - low) % 2 == 1 or low % 2 == 1 or high % 2 == 1:
            oddNums += 1

        return oddNums
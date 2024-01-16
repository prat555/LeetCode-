class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x > 0 and x%10 == 0):   
            return False

        reversedNum = 0
        while x > reversedNum:
            reversedNum = reversedNum * 10 + x % 10
            x = x // 10
        return True if (x == reversedNum or x == reversedNum // 10) else False
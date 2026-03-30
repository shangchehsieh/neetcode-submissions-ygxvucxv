class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1  #two pointer: left, right

        while l < r:
            #內層的l < r是避免特殊測資(空字串"" or 全是特殊字元???!!!)
            # l += 1會一直加到字串外，造成後面程式index error
            while l < r and not self.alphaNum(s[l]):
                l += 1 
            while l < r and not self.alphaNum(s[r]):
                r -= 1
            if s[l].lower() != s[r].lower():
                return False
            l, r = l + 1, r - 1
        return True

    def alphaNum(self, c): #自己手刻.isalnum()
        return (ord('A') <= ord(c) <= ord('Z') or
                ord('a') <= ord(c) <= ord('z') or
                ord('0') <= ord(c) <= ord('9'))


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.replace(" ","") #將空格替換成無
        s = s.lower() #全小寫
        s = re.sub(r'[^a-zA-Z0-9]', '', s)
        #19 char: 1~9 / 10 / 11~19

        l = len(s)//2 #9
        count = 0
        if s is None:
            return True
        for i in range(l):
            if s[i] != s[len(s)-1-i]:
                return False
        return True


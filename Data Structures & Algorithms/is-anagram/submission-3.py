class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        hashmap = defaultdict(int)
        for c in s:
            hashmap[c] += 1
        for c in t:
            hashmap[c] -= 1
            if hashmap[c] < 0:
                return False
        
        for key in hashmap:
            if hashmap[key] > 0:
                return False
        
        return True
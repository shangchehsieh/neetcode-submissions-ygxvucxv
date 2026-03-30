class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = defaultdict(list)

        for key in strs:
            count = [0]*26 # a...z
            
            for c in key:
                count[ord(c) - ord("a")] += 1

            hashmap[tuple(count)].append(key)
        return list(hashmap.values())
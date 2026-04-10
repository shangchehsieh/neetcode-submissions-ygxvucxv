class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = defaultdict(list)
        res = []

        # build sorted key, append in hashmap
        for s in strs:
            sorted_key = tuple(sorted(s))
            hashmap[sorted_key].append(s)
            # {sorted_key1: s1, sorted_key2: s2, ...}

        # append the result
        for v in hashmap.values():
            res.append(v)

        return res
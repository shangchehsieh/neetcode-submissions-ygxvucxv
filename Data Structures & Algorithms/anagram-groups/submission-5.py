class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = defaultdict(list)
        res = []

        for s in strs:
            sort_key = tuple(sorted(s))
            hashmap[sort_key].append(s)
            # {("a","e","t"): ["eat","tea","ate"], ("a","n","t"): ["tan","nat"], ...}

        for v in hashmap.values():
            res.append(v)

        return res
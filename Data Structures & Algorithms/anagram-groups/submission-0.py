class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = defaultdict(list)
        result = []

        for key in strs:
            sorted_key = tuple(sorted(key)) #key
            hashmap[sorted_key].append(key)

        for value in hashmap.values():
            result.append(value)

        return result
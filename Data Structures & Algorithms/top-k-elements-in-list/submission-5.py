class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap = defaultdict(int)
        # {"a": 0, "b": 1, "c": 2}
        for n in nums:
            hashmap[n] += 1
        # [1,2,2,3,3,3,3]
        # {"1": 1, "2": 2, "3": 4}
        top_k = sorted(hashmap.keys(), key=lambda x: hashmap[x], reverse = True)[:k]
        return top_k
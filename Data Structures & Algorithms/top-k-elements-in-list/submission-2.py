class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #hashmap
        hashmap = defaultdict(int)
        result = []

        for c in nums:
            hashmap[c] += 1 #{1,2,3} = [1,2,3]
        
        topk = sorted(hashmap.keys(), key=lambda x: hashmap[x], reverse=True)[:k]
        return topk


        
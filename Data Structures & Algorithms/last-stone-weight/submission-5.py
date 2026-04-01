class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # stones = [2,3,6,2,4]
        stones = [-s for s in stones]
        heapq.heapify(stones) # 6 4 3 2 2
        print(stones)
        while len(stones) > 1:
            x = heapq.heappop(stones)
            y = heapq.heappop(stones)
            if x > y or x < y: heapq.heappush(stones, x-y)
            else: stones.append(0) # x == y
        return abs(stones[0])

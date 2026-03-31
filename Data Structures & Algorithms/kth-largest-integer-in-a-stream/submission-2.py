class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.minHeap = nums
        self.K = k
        heapq.heapify(self.minHeap)
        while(len(self.minHeap) > self.K):
            heapq.heappop(self.minHeap)

    def add(self, val: int) -> int:
        heapq.heappush(self.minHeap, val)
        while(len(self.minHeap) > self.K):
            heapq.heappop(self.minHeap)
        return self.minHeap[0]

class MinHeap:
    
    def __init__(self):
        self.heap = [0]
        self.size = 0
        
    def print_heap(self):
        if self.size:
            print(self.heap[1:])
        else:
            print("Heap empty!")
        
    def peep_min(self):
        if not self.size:
            raise IndexError("Cannot remove from empty heap!")
        return self.heap[1]
    
    def insert(self, x):
        self.heap.append(x)
        self.size += 1
        self.percolate_up(self.size)
        
    def remove_min(self):
        if not self.size:
            raise IndexError("Cannot remove from empty heap!")
        min_val = self.peep_min()
        self.heap[1] = self.heap[self.size]
        self.heap.pop()
        self.size -= 1
        self.percolate_down(1)
        return min_val
        
    def percolate_up(self, i):
        while i // 2 > 0:
            if self.heap[i] < self.heap[i // 2]:
                x = self.heap[i]
                self.heap[i] = self.heap[i // 2]
                self.heap[i // 2] = x
            i //= 2
            
    def percolate_down(self, i):
        while i * 2 <= self.size:
            min_child = self.get_min_child(i)
            if self.heap[i] > self.heap[min_child]:
                x = self.heap[i]
                self.heap[i] = self.heap[min_child]
                self.heap[min_child] = x
            i = min_child
            
    def get_min_child(self, i):
        if i * 2 + 1 > self.size:
            return i * 2
        if self.heap[i * 2] <= self.heap[i * 2 + 1]:
            return i * 2
        else:
            return i * 2 + 1
        
    def heapify(self, xs):
        self.heap = [0] + xs
        self.size = len(xs)        
        for i in range(self.size // 2, 0, -1):
            self.percolate_down(i)
            
            
min_heap = MinHeap()

for x in range(5, 0, -1):
    min_heap.insert(x)
min_heap.print_heap()

min_val = min_heap.remove_min()
min_heap.print_heap()

xs = [10, 8, 6, 4, 2, 1]
new_min_heap = MinHeap()
new_min_heap.heapify(xs)
new_min_heap.print_heap()

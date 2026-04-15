class Solution:
    def __init__(self):
        self.arr = [0,1,2]
    def climbStairs(self, n: int) -> int:
        if n == 1 or n == 2:
            return n
        elif n <= 0:
            return 0 
        for i in range(1, n):
            self.arr.append(self.arr[i] + self.arr[i+1])
        return self.arr[n]
            

class Solution():
    def __init__(self):
        self.arr = [0, 1]
        
    def fib(self, n):
        if n < 0:
            print('error')
            return 0
        elif n == 0 or n == 1:
            return self.arr[n]

        for i in range(2, n + 1):
            self.arr.append(self.arr[i - 1] + self.arr[i - 2])
            
        return self.arr[n]


class Solution:
    def countBits(self, n: int) -> List[int]:
        if n == 0:
            return [0]
        
        arr = [0, 1]
        area = 1  # 代表目前是 2^area 的區間

        for i in range(2, n + 1):
            if i == 2 ** area:
                arr.append(1)
                area += 1
            else:
                index = i - 2 ** (area - 1)
                arr.append(arr[index] + 1)
        
        return arr
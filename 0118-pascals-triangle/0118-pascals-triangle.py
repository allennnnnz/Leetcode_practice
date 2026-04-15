class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        self.dp = [[1],[1,1]]
        if numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1],[1,1]]
        for i in range(numRows - 2):
            last_level = self.dp[-1]
            cur_level = [1]
            for j in range(1,len(self.dp[-1])):
                cur_level.append((last_level[j-1] + last_level[j]))
            cur_level.append(1)
            self.dp.append(cur_level)
        return self.dp


        
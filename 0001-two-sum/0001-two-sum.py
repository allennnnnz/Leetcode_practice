from typing import List

class Solution:
    def binarySearch(self, head, tail, target, nums):
        if head <= tail:
            mid = (head + tail) // 2
            if nums[mid] == target:
                return mid
            elif target < nums[mid]:
                return self.binarySearch(head, mid - 1, target, nums)
            else:
                return self.binarySearch(mid + 1, tail, target, nums)
        return -1

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        indexed = list(enumerate(nums))                   # [(index, value)]
        indexed.sort(key=lambda x: x[1])                  # 按照值排序
        sorted_val = [val for _, val in indexed]          # 拿出排序後的值

        for i in range(len(nums)):
            find = target - indexed[i][1]
            sorted_id = self.binarySearch(i + 1, len(sorted_val) - 1, find, sorted_val)

            if sorted_id != -1:
                original_id_1 = indexed[i][0]
                original_id_2 = indexed[sorted_id][0]

                if original_id_1 != original_id_2:         # ✅ 避免找回自己
                    return [original_id_1, original_id_2]

        return None
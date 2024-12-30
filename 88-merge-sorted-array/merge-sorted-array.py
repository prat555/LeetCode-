class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        for i in range(1,n+1):
            if nums1[-i]==0:
                nums1[-i]=nums2[-i]
        nums1=nums1.sort()
        
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        n=len(nums);
        if(n == 0):
            return 0
        i=1
        ml=1
        st=set(nums)
        for num in nums:
            if(num-1 in st):
                continue
            else:
                c=1
                while(num+c in st):
                    c+=1;
            ml = max(ml,c)
        return ml
        
        
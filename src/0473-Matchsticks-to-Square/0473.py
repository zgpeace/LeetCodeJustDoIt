class Solution:
    def makesquare(self, nums: List[int]) -> bool:
        s, n = sum(nums), len(nums)
        t = s//4
        if len(nums) < 4 or s % 4:
            return False
        
        nums.sort(reverse=True)
        vis = [0] * n
        
        def dfs(cur, u, k):
            if u == 4: return True
            if cur == t: return dfs(0, u + 1, 0)
            
            i = k
            while i < n:
                if vis[i] or (cur + nums[i] > t): 
                    i += 1
                    continue
                    
                vis[i] = 1
                if dfs(cur + nums[i], u, i + 1): return True
                vis[i] = 0
                
                # 针对每条边的第一个和最后一个火柴
                if not cur or cur + nums[i] == t: return False 
                
                j = i
                while j < n and nums[i] == nums[j]: j += 1 # 相同火柴
                i = j - 1
                i += 1
            return False
        
        return dfs(0, 0, 0)
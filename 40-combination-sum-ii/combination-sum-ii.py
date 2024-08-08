class Solution(object):

    def combinationSum2(self, candidates, target):
        candidates.sort()
        result = []
        
        def backtrack(start, combination, remaining_sum):
            if remaining_sum == 0:
                result.append(combination[:])
                return
            
            if remaining_sum < 0:
                return
            
            for i in range(start, len(candidates)):
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                combination.append(candidates[i])
                backtrack(i + 1, combination, remaining_sum - candidates[i])
                combination.pop()
        
        backtrack(0, [], target)
        return result
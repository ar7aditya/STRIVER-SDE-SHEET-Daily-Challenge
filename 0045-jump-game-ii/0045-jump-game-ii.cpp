class Solution {
public:
    int jump(vector<int>& nums) {
        
        const int size = nums.size();
        
        // destination is last index
        int destination = size-1;
        
        int curCoverage = 0, lastJumpIdx = 0;
        
        // counter of jump
        int timesOfJump = 0;
        
        // Quick response if start index == destination index == 0
        if( size == 1 ){
            return 0;
        }
            
        
        // Greedy stragegy: extend coverage as long as possible with lazp jump
        for( int i = 0 ; i < size ; i++){
            
            // extend coverage
            curCoverage = max(curCoverage, i + nums[i] );
            
            // forced to jump (by lazy jump) to extend coverage
            if( i == lastJumpIdx ){
                
                lastJumpIdx = curCoverage;
                
                timesOfJump++;
                
                // check if we reached destination already
                if( curCoverage >= destination){
                    return timesOfJump;
                }
            }
        }
        
        return timesOfJump;
    }
};
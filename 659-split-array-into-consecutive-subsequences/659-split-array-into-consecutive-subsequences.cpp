class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> avaibilityMap;

		unordered_map<int,int> vacancyMap  ;

		for(int i : nums) {
			avaibilityMap[i]++;
		}

		for(int i=0;i<nums.size();i++){
			if(avaibilityMap[nums[i]]<=0){
				continue;
			}

			else if(vacancyMap[nums[i]]>0){
				avaibilityMap[nums[i]]--;

				vacancyMap[nums[i]]--;
				//System.out.println("Vacancy found for " +  (nums[i]+1));

				vacancyMap[nums[i]+1]++;
			}

			else if(avaibilityMap[nums[i]]>0 && avaibilityMap[nums[i]+1]>0 && avaibilityMap[nums[i]+2]>0){

				avaibilityMap[nums[i]]--;
                avaibilityMap[nums[i]+1]--;
				avaibilityMap[nums[i]+2]--;

				vacancyMap[nums[i]+3]++;
			}

			else{
				return false;
			}
		}

		return true;
    }
};

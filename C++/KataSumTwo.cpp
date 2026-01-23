//Задачка с leetcode 23.01.2026

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
  {
        unordered_map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); ++i) 
        {
            int complement = target - nums[i];
            if (numToIndex.find(complement) != numToIndex.end()) 
            {
                return {numToIndex[complement], i};
            }
            numToIndex[nums[i]] = i;
        }
        return {};
    }
};


int main() 
{
    Solution solution;
    // Пример для теста 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Пример 1: [" << result1[0] << ", " << result1[1] << "]" << endl;
    return 0;
}

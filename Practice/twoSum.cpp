#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> HashMap;
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            int x = target - cur;
            if (HashMap.find(x) != HashMap.end()) {
                vector<int> targetSum;
                targetSum.push_back(HashMap[x]);
                targetSum.push_back(i);
                return targetSum;
            }
            HashMap[cur] = i;
        }
        return vector<int>();
    }
};

int main(){
    Solution sol;
    int target;
    vector<int> nums;
    cout << "Please enter the array: ";
    int x;

    while (cin >> x) {
        nums.push_back(x);
        if (cin.peek() == '\n') break;
    }
    cout << "Please enter the target: ";
    cin >> target;
    nums = sol.twoSum(nums, target);
    cout << "[" << nums[0] << ", " << nums[1] << "]" << endl;
}
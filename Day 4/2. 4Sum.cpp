class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(begin(nums), end(nums));
        set<vector<int>> ans;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int low = j + 1, high = nums.size() - 1;
                while (low < high)
                {
                    long long a = nums[i];
                    long long b = nums[j];
                    long long c = nums[low];
                    long long d = nums[high];
                    long long sum = a + b + c + d;
                    if (sum == target)
                    {
                        ans.insert({nums[i], nums[j], nums[low], nums[high]});
                        high--;
                        low++;
                    }
                    else
                    {
                        if (sum > target)
                        {
                            high--;
                        }
                        else
                        {
                            low++;
                        }
                    }
                }
            }
        }
        return vector<vector<int>>(begin(ans), end(ans));
    }
};
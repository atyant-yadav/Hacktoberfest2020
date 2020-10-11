//O(n)
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int pos(0), reach(0), jumps(0);

        for (int i = 0; i < n - 1; i++)
        {
            reach = max(reach, i + nums[i]);
            if (pos == i)
            {
                pos = reach;
                jumps++;
            }
        }

        return jumps;
    }
};

//O(n^2)
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int minV = INT_MAX;
            for (int j = 0; j < i; j++)
                if (j + nums[j] >= i)
                    minV = min(minV, dp[j]);
            if (minV != INT_MAX)
                dp[i] = minV + 1;
            else
                dp[i] = INT_MAX;
        }

        return dp[n - 1];
    }
};

//Review

/*---------------leetcode-----------------
-----------Min Size Subarray Length-------
----------------storm Han-----------------
----------------2016.08.26----------------
Question describing:
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/

#include <vector>

using namespace std;

// Dynamic programming

int minSizeSubarraySum(int s, vector<int>& nums)
{
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
	}

	/*
	如果所有数的总和小于s，则该问题无解，返回0
	*/
	if (sum < s)
		return 0;


	sum = 0;
	bool flag = false;
	int count = 0;

	vector<int> dp(nums.size() + 1, 0);
	dp[0] = nums.size(); //dp[0]是max number，也即等于数组的个数

	for (int i = 1; i < dp.size(); ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			sum += nums[j];
			count++;
			if (sum >= s)
			{
				flag = true;
				break;
			}
		}

		if (flag)
		{
			if (count < dp[i - 1])
				dp[i] = count;
			else
				dp[i] = dp[i - 1];
		}
		else
		{
			dp[i] = dp[i - 1];
		}
		count = 0;
		flag = false;
		sum = 0;
	}

	return dp[dp.size() - 1];
}

// two pointer
int minSizeSubarraySum2(int s, vector<int>& nums)
{
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
	}

	if (s > sum)
		return 0;

	//two pointer
	int p1 = 0;
	int p2 = 0;

	int min = nums.size();
	sum = 0;
	int count = 0;
	while (p2 < nums.size())
	{
		do{
			sum += nums[p2];
			p2++;
		} while (sum < s && p2 < nums.size());

		do{
			sum -= nums[p1];
			p1++;
		} while (sum >= s);

		count = p2 - p1 + 1;
		if (count < min) min = count;
	}
	return min;
}
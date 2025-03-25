// 给定一个整数数组 nums 和一个整数目标值 target
// 请你在该数组中找出 和为目标值 target的那两个整数
// 并返回它们的数组下标。
class Solution
{
public:
    vector<int> twoSum(vector<int> &a, int t)
    {
        int n = a.size();
        vector<pair<int, int>> idxs(n);
        for (int i = 0; i < n; i++)
        {
            idxs[i] = {a[i], i}; // 创建每个元素和其对应索引的对
        }

        // 按照元素值排序
        sort(idxs.begin(), idxs.end());

        int l = 0, r = n - 1;
        vector<int> ret;
        while (l < r)
        {
            int sum = idxs[l].first + idxs[r].first;
            if (sum == t)
            {
                ret.push_back(idxs[l].second);
                ret.push_back(idxs[r].second);
                break;
            }
            else if (sum < t)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ret;
    }
};
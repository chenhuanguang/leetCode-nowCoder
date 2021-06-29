class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        //string:单词 int:出现次数
        map<string, int> mp;//安装字符顺序排序，递增序列
        for (const auto& wd : words)
        {
            mp[wd]++;
        }
        //multimap的key可以重复，但不支持[]
        //int:出现次数 string单词， 安装出现次数大小排序
        multimap<int, string, greater<int>> mf;
        //字母升序遍历
        for (const auto& p : mp)
        {
            //将mp中的出现次数和单词插入到mf中
            //即使单词出现频率相同，也是先插入的在前面，也就是字母小的在前
            //满足优先按照频率排序，再安装字符升序排序
            mf.insert(make_pair(p.second, p.first));
        }

        vector<string> res;
        for (const auto& p : mf)
        {
            if (k == 0)
                break;
            else
            {
                res.push_back(p.second);
                --k;
            }
        }
        return res;
    }
};
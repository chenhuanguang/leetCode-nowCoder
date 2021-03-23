class Solution {
public:
    string reverseWords(string s) 
    {
        int fast = 0;
        int slow = 0;
        int len = s.size();
        while (fast < len)
        {
            while (fast < len && s[fast] != ' ')
            {
                ++fast;
            }

            int tmp = fast;
            while (fast > slow)
            {
                fast--;
                swap(s[fast], s[slow]);
                ++slow;
            }
            fast = slow = ++tmp;
        }
        return s;
    }
};
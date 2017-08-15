/*
*  在string中找到最长无重复字符的子串。返回该子串长度  DP（O(n）)
*/
    int lengthOfLongestSubstring(string s) {
       vector<int> dict(256, -1);
        int maxlen = 0;
        int start = -1;
        for(int i = 0; i < s.size(); ++i){
            if(dict[s[i]] > start){
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            maxlen = max(maxlen, i - start);
        }
        return maxlen;
    }

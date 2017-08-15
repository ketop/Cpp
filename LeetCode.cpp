/*
*  在string中找到最长无重复字符的子串。返回该子串长度  DP（O(n))
*  使用dict来存储ASCII码中的字符在string中的索引。 如果出现重复字符，则更新计数起点，该起点为该字符之前在string中的索引。
*  用此作差可以得到当前不重复字符子串的长度
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

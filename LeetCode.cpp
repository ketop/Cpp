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
/*
* 最长回文， 使用动态规划DP， 数组dp[j][i]刻画下标索引j到i之间的字符串是否为回文。
* 如果j==i, 则肯定为回文。如果s[i]=s[j]  分为如下情况： 如果i=j+1, 则也为回文。如果i > j+1, 且s[j+1][i-1]为回文，则s[j][i]为回文
* len记录最长回文长度
*/
    string longestPalindrome(string s) {
        int dp[s.size()][s.size()] = {0}, left = 0, right = 0, len = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(left, right - left + 1);
    }

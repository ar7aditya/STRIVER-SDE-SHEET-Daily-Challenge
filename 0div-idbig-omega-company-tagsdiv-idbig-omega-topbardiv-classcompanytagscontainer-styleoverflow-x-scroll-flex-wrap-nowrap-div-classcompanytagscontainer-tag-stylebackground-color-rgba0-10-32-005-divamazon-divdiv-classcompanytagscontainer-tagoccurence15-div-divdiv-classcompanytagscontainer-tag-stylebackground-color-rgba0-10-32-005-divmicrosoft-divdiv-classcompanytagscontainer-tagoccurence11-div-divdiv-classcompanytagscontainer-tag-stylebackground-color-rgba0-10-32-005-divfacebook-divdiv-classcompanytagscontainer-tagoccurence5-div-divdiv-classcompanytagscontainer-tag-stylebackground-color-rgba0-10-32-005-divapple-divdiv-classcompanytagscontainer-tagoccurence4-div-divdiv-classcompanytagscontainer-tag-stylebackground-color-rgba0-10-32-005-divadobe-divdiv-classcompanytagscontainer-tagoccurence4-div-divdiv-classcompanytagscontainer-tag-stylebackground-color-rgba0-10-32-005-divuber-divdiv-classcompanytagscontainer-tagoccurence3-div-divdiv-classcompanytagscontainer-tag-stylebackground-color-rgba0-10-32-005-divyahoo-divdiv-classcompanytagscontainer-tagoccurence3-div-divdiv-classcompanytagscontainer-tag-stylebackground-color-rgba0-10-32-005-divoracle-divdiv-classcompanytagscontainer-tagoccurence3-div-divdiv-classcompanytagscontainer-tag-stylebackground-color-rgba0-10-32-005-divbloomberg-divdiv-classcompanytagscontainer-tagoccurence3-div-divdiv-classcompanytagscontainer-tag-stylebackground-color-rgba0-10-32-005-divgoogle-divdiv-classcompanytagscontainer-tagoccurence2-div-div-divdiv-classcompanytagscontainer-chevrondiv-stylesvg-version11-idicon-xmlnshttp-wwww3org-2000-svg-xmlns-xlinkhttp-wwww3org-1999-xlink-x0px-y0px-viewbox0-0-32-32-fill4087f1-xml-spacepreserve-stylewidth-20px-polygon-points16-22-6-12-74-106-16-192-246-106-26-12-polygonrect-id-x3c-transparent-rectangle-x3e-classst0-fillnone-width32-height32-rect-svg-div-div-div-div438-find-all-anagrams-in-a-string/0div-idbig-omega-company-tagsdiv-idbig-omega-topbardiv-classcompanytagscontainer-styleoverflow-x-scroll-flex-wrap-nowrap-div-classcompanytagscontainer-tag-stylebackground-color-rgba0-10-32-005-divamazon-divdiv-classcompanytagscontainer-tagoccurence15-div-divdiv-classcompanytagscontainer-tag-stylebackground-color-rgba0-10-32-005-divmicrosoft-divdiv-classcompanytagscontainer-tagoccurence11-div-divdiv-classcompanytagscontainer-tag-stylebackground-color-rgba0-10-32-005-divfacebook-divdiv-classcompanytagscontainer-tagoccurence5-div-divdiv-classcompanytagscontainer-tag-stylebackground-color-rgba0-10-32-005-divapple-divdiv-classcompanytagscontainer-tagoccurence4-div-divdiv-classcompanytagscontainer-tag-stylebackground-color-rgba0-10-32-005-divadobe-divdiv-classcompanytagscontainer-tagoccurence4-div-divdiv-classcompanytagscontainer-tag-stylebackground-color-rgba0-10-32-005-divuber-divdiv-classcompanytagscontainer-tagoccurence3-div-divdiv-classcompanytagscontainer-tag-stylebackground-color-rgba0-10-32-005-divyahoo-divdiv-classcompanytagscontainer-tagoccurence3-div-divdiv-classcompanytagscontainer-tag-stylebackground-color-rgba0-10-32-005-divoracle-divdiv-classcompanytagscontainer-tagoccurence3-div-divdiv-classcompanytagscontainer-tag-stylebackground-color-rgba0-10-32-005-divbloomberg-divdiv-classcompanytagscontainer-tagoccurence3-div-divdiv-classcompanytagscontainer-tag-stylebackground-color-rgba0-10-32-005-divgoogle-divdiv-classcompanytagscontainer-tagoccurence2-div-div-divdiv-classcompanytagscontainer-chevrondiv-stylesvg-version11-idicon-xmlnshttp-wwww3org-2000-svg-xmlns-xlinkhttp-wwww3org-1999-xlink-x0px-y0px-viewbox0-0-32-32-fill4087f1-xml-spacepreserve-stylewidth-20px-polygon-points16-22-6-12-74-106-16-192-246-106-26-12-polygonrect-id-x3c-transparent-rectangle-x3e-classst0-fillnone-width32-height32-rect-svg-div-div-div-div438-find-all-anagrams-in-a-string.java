import java.util.*;

public class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ans = new ArrayList<>();
        int n = p.length();
        HashMap<Character, Integer> mp = new HashMap<>();
        int left = 0, right = 0;

        // Populate the frequency map for characters in `p`
        for (char ch : p.toCharArray()) {
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }

        // Count of unique characters in the map
        int required = mp.size();

        // Sliding window variables
        int windowMatch = 0;

        // Sliding window over `s`
        while (right < s.length()) {
            char ch = s.charAt(right);
            // If the character is part of `p`, decrement its count in the map
            if (mp.containsKey(ch)) {
                mp.put(ch, mp.get(ch) - 1);
                if (mp.get(ch) == 0) {
                    windowMatch++;
                }
            }
            right++;

            // Check if the window size matches `p`'s length
            while (right - left == n) {
                if (windowMatch == required) {
                    ans.add(left); // Anagram found
                }

                char leftChar = s.charAt(left);
                // Shrink the window from the left
                if (mp.containsKey(leftChar)) {
                    if (mp.get(leftChar) == 0) {
                        windowMatch--;
                    }
                    mp.put(leftChar, mp.get(leftChar) + 1);
                }
                left++;
            }
        }

        return ans;
    }
}


/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

*/


class Solution {
public:
    bool isAnagram(string s, string t) {
    
    Approach 1 using Hashtable
        unordered_map<char, int> count;
        
        // Count the frequency of characters in string s
        for(auto X: s) {
            count[X]++;
        }

        // decrement the frequency of characters in string t
        for(auto X: t) {
            count[X]--;
        }

        //check if any character has non-zero frequency
        for(auto X: count) {
            if(X.second != 0) {
                return false;
            }
        }
        return true;
    


    // Approach 2 using Array
    // int count[26] = {0};

    // for(char X: s){
    //     count[X - 'a']++;
    // }

    // for(char X: t) {
    //     count[X - 'a']--;
    // }

    // for(int val: count) {
    //     if(val != 0) {
    //         return false;
    //     }
    // }
    // return true;
    }
};

/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include<iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() < 2) return s;
    int max_len = 0;
    int start_idx = 0;
    int i = 0;
    while (i < s.size()) {
      int r_ptr = i;
      int l_ptr = i;
      //find the middle of a palindrome
      while (r_ptr < s.size() - 1 && s[r_ptr] == s[r_ptr + 1]) r_ptr++;
      i = r_ptr + 1;
      //expand from the middle out
      while (r_ptr < s.size() - 1 && l_ptr > 0 && s[r_ptr + 1] == s[l_ptr - 1]) {
        r_ptr++;
        l_ptr--;
      }
      int new_len = r_ptr - l_ptr + 1;
      if (new_len > max_len) {
        start_idx = l_ptr;
        max_len = new_len;
      }
    }
    return s.substr(start_idx, max_len);
  }
};
// @lc code=end

int main(int argc, char **argv) {
  string s = "zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir";
  // string s = "aab";
  Solution solu;
  std::cout << solu.longestPalindrome(s);
  return 0;
}


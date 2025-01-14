/*
412. Fizz Buzz
Given an integer n, return a string array answer (1-indexed) where:
answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i if non of the above conditions are true.
 
Example 1:
Input: n = 3
Output: ["1","2","Fizz"]
Example 2:
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]
Example 3:
Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
Constraints:
1 <= n <= 10^4
*/

#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<string> result;
        for(int i = 0; i < n ; i++) {
            if((i+1)% 3 == 0 && (i+1)%5 == 0) {
                result.push_back("FizzBuzz");
            } else if((i+1)%3 == 0) {
                result.push_back("Fizz");
            } else if((i+1)%5 == 0) {
                result.push_back("Buzz");
            } else {
                result.push_back(to_string(i + 1));
            }
        } 
        return result;
    }
};

int main() {
    Solution solution;
    solution.fizzBuzz(3);
}
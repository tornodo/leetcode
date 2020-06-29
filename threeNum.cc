#include "common.h"


#include "trie.hpp"
#include "leetcode139.h"
#include "leetcode209.h"
#include "leetcode215.h"

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // queue<uint8_t> s;
        ListNode* l3 = new ListNode(0);
        auto tmpP = l3;
        uint8_t j = 0;
        for(;l1 != nullptr || l2 != nullptr;) {
            uint8_t sum;
            if (l1 == nullptr) {
                sum = l2->val + j;
            } else if (l2 == nullptr) {
                sum = l1->val + j;
            } else {
                sum = l2->val + l1->val + j;
            }
            uint8_t d = sum / 10;
            uint8_t y = sum % 10;
            if (d != 0) {
                // s.push(y);
                auto node = new ListNode(y);
                l3->next = node;
                l3 = node;
                j = 1;
            } else {
                // s.push(sum);
                auto node = new ListNode(sum);
                l3->next = node;
                l3 = node;
                j = 0;
            }


            if (l1 != nullptr && l1->next != nullptr) {
                l1 = l1->next;
            } else {
                l1 = nullptr;
            }
            if (l2 != nullptr && l2->next != nullptr) {
                l2 = l2->next;
            } else {
                l2 = nullptr;
            }
        }
        if (j != 0) {
            // s.push(j);
            auto node = new ListNode(j);
            l3->next = node;
            l3 = node;
        }
        // ListNode *node = new ListNode(s.front());
        // s.pop();
        // ListNode *preNode = node;
        // for(; s.size() > 0; ) {
        //     ListNode *n = new ListNode(s.front());
        //     s.pop();
        //     node->next = n;
        //     node = n;
        // }
        return tmpP->next;

    }
};


int main(int argc, char** argv) {
    // int a1[] = {2,4,3}, a2[] = {5,6,4};
    // Solution solution;
    // ListNode *l1 = new ListNode(a1[0]);
    // ListNode *l2 = new ListNode(a2[0]);
    // auto p1 = l1;
    // auto p2 = l2;
    // for (int i = 1; i < sizeof(a1) / sizeof(a1[0]); i++) {
    //     auto n = new ListNode(a1[i]);
    //     p1->next = n;
    //     p1 = n;
    // }
    // for (int i = 1; i < sizeof(a2) / sizeof(a2[0]); i++) {
    //     auto n = new ListNode(a2[i]);
    //     p2->next = n;
    //     p2 = n;
    // }
    // auto l3 = solution.addTwoNumbers(l1, l2);
    // for(;l3 != nullptr; l3 = l3->next) {
    //     cout << l3->val << " ";
    // }
    // cout << endl;
    // string s = "0123456789";
    // cout << s.replace(3, 4, "") << endl;
    // stringstream ss;
    // ss << "a";
    // ss << "b";
    // cout << ss.str() << endl;
    
    // leetcode 139
    // vector<string> tmp{"aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba"};
    // cout << wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", tmp);
    // vector<string> tmp{"leet","code"};
    // cout << wordBreak("leetcode", tmp) << endl;

    // leetcode 209
    // int s = 15;
    // vector<int> nums{5,1,3,5,10,7,4,9,2,8};
    // cout << minSubArrayLen(s, nums) << endl;

    // leetcode 215
    // vector<int> nums{};
    // int k = 918;
    // cout << findKthLargest(nums, k) << endl;
    // maxHeap<int> g(nums);
    // cout << g.max() << endl;
    // g.push(7);
    // cout << g.max() << endl;
    // g.push(8);
    // cout << g.max() << endl;
    // while(g.size() > 0) {
    //     cout << g.pop() << " ";
    // }
    // cout << endl;
    // cout << quicksortfindKthLargest(nums, k) << endl;
    return 0;
}

/**
 *  @judge LeetCode
 *  @id 61
 *  @name Rotate List
 * 
 *  @tag Data Structure
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr)
			return head;
		int n, cnt;
		ListNode *pos, *last;
		n = 0;
		for (pos = head; pos != nullptr; pos = pos->next) {
			n++;
			last = pos;
		}
		k = n - k % n;
		pos = head;
		for (cnt = 0; cnt < k - 1; cnt++)
			pos = pos->next;
		last->next = head;
		head = pos->next;
		pos->next = nullptr;
		return head;
	}
};
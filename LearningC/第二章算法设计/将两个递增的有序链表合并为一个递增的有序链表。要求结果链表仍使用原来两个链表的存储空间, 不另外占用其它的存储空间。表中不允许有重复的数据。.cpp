
#include <iostream>

//2.1 
// 将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表的存储空间, 不另外占用其它的存储空间。表中不允许有重复的数据。

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 合并两个递增的有序链表为一个递增的有序链表。
 * 要求结果链表仍使用原来两个链表的存储空间，不另外占用其它的存储空间。
 * 表中不允许有重复的数据。
 *
 * @param l1 第一个有序链表
 * @param l2 第二个有序链表
 * @return 合并后的链表头结点
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	// 如果其中一个链表为空，直接返回另一个链表
	if (!l1) return l2;
	if (!l2) return l1;

	ListNode* head = nullptr;

	// 确定合并后链表的头结点
	if (l1->val < l2->val) {
		head = l1;
		l1 = l1->next;
	}
	else if (l1->val > l2->val) {
		head = l2;
		l2 = l2->next;
	}
	else {
		// 如果头结点值相同，取l1为头，l2跳过该重复值
		head = l1;
		l1 = l1->next;
		l2 = l2->next;
	}

 	ListNode* current = head;

	// 遍历两个链表，直到其中一个为空
	while (l1 && l2) {
		if (l1->val < l2->val) {
			// l1较小，接入l1
			current->next = l1;
			l1 = l1->next;
		}
		else if (l1->val > l2->val) {
			// l2较小，接入l2
			current->next = l2;
			l2 = l2->next;
		}
		else {
			// 值相等，保留一个（这里保留l1），l2跳过
			current->next = l1;
			l1 = l1->next;
			l2 = l2->next;
		}
		// 移动尾指针		current = current->next;
	}

	// 将剩余的链表接在后面
	if (l1) current->next = l1;
	if (l2) current->next = l2;

	return head;
}

int main()
{
		// 创建第一个有序链表 1 -> 3 -> 5
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(3);
	l1->next->next = new ListNode(5);
	// 创建第二个有序链表 2 -> 3 -> 4 -> 6
	ListNode* l2 = new ListNode(2);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);
	l2->next->next->next = new ListNode(6);
	// 合并链表
	ListNode* mergedList = mergeTwoLists(l1, l2);
	// 输出合并后的链表
	ListNode* current = mergedList;
	while (current) {
		std::cout << current->val << " ";
		current = current->next;
	}
	std::cout << std::endl;
	// 释放内存（省略）
	return 0;
}
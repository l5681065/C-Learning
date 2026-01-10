#pragma once
#include <iostream>
#include <vector> 

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// 辅助函数：打印链表
void printList(ListNode* head) {
	ListNode* current = head;
	while (current) {
		std::cout << current->val << " -> ";
		current = current->next;
	}
	std::cout << "NULL" << std::endl;
}

// 从vector创建链表
ListNode* createList(const std::vector<int>& vals) {
	if (vals.empty()) {
		return nullptr;
	}
	ListNode* head = new ListNode(vals[0]);
	ListNode* current = head;
	for (size_t i = 1; i < vals.size(); ++i) {
		current->next = new ListNode(vals[i]);
		current = current->next;
	}
	return head;
}

#pragma once
#include <iostream>
#include <vector> 

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};




inline void freeList(ListNode* head) {
	while (head) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

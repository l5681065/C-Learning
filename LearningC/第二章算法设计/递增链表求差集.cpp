//2.4
//已知两个链表A和B分别表示两个集合，其元素递增排列。请设计算法求出两个集合A和B 的差集（即仅由在A中出现而不在B中出现的元素所构成的集合），并以同样的形式存储，同时返回该集合的元素个数。
#pragma once
#include "ListUtils.hpp"

//题目分析
/*
求两个集合A和B的差集是指在A中删除A和B中共有的元素，即删除链表中的相应结点, 所以要保存待删除结点的前驱，使用指针pre指向前驱结点。pa和pb分别是链表La和Lb的工作指针, 初始化为相应链表的第一个结点，从第一个结点开始进行比较，当两个链表La和Lb均为到达表尾结点时，如果La表中的元素小于Lb表中的元素，pre置为La表的工作指针pa删除Lb表中的元素；如果其中一个表中的元素较小时，删除此表中较小的元素，此表的工作指针后移。当链表La和Lb有一个为空时，依次删除另一个非空表中的所有元素。
*/

inline void printList(ListNode* head) {
	ListNode* current = head;
	while (current) {
		std::cout << current->val << " -> ";
		current = current->next;
	}
	std::cout << "NULL" << std::endl;
}

inline ListNode* createList(const std::vector<int>& vals) {
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

//我的算法理解错了题意，求的是对称差集，而不是A-B
int difference_my(ListNode *& A, ListNode*& B)
{
	ListNode*  dummyNode = new ListNode(0); // 创建哑节点
	ListNode* tail = dummyNode; // 结果链表的尾指针
	ListNode* pa = A;
	ListNode* pb = B;
	int count = 0; // 计数器，记录差集元素个数
	while (pa && pb)
	{
		if (pa->val < pb->val)
		{
			tail->next = pa;
			tail = tail->next;
			pa = pa->next;
			
			count ++;
		}
		else if (pa->val > pb->val)
		{
			tail->next = pb;
			tail = tail->next;
			pb = pb->next;
			count++;
		}
		else
		{
			pa = pa->next;
			pb = pb->next; 
		}
	}

	while (pa)
	{
		tail->next = pa;
		tail = tail->next;
		pa = pa->next;
		count++;
	}
	while (pb)
	{
		tail->next = pb;
		tail = tail->next;
		pb = pb->next;
		count++;
	}

	tail->next = nullptr; // 结束结果链表
	A = dummyNode->next; // 更新A为结果链表的头
	delete dummyNode;
	return count;
}

int  difference_my2(ListNode*& A, ListNode*& B)
{
	ListNode* dummyNode = new ListNode(0); // 创建哑节点
	ListNode* tail = dummyNode; // 结果链表的尾指针
	ListNode* pa = A;
	ListNode* pb = B;
	int count = 0; // 计数器，记录差集元素个数
	while (pa && pb)
	{
		if (pa->val < pb->val)
		{
			tail->next = pa;
			tail = tail->next;
			pa = pa->next;
			count ++;
		}
		else if (pa->val > pb->val)
		{
			pb = pb->next;
		}
		else
		{
			pa = pa->next;
			pb = pb->next;
			tail->next = nullptr; // 断开连接
		}
	}
	while (pa)
	{
		tail->next = pa;
		tail = tail->next;
		pa = pa->next;
		count++;
	}
	tail->next = nullptr; // 结束结果链表
	A = dummyNode->next; // 更新A为结果链表的头
	return count;
}


void runTestCase(const std::string& title, const std::vector<int>& aValues, const std::vector<int>& bValues)
{
	std::cout << title << std::endl;
	ListNode* a = createList(aValues);
	ListNode* b = createList(bValues);

	std::cout << "A: ";
	printList(a);
	std::cout << "B: ";
	printList(b);

	const int diffCount =   difference_my2(a, b);
	std::cout << "差集 (A - B): ";
	printList(a);
	std::cout << "元素个数: " << diffCount << std::endl;
	std::cout << "-------------------------" << std::endl;

	/*freeList(a);
	freeList(b);*/
}


int main_2_4()
{
	runTestCase("测试用例 1: 部分重叠", { 1, 2, 3, 4, 5 }, { 2, 4, 6 });
	runTestCase("测试用例 2: B 为 A 的子集", { 2, 4, 6, 8 }, { 2, 4, 6, 8 });
	runTestCase("测试用例 3: 无交集", { 1, 3, 5 }, { 2, 4, 6 });
	runTestCase("测试用例 4: B 为空", { 1, 2, 3 }, {});
	runTestCase("测试用例 5: A 为空", {}, { 1, 2, 3 });
	runTestCase("测试用例 6: B 含更小与更大元素", { 3, 4, 5, 7 }, { 1, 3, 6, 8 });
	runTestCase("测试用例 7: ", { 10, 30, 50, 70 }, { 31, 32, 50, 70 });
	runTestCase("测试用例 8: ", { 1,2,3,4,5 }, { 31, 32, 50, 70 });
	return 0;

}
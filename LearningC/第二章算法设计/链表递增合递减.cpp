//2.2
// 将两个非递减的有序链表合并为一个非递增的有序链表。要求结果链表仍使用原来两个链表的存储空间, 不另外占用其它的存储空间。表中允许有重复的数据。

//核心思路：头插法(Head Insertion)
//这个算法最巧妙的地方在于它利用了“头插法”来自然地实现排序的逆转。
//我们知道，输入的两个链表 l1 和 l2 都是递增的。这意味着在任何时候，l1 的头结点和 l2 的头结点都是各自链表中当前剩下的最小元素。
//算法的思路是：
//1.	不断摘取最小节点：比较 l1 和 l2 的头结点，找出值较小的那个。这个节点就是两个链表中所有未处理节点里的最小者。
//2.	插入到结果链表的头部：将这个摘取下来的最小节点，插入到最终结果链表 head 的最前面。

//这个算法的设计精髓在于：
//•	归并思想：借鉴了归并排序的思路，每次从两个有序序列中取出一个元素进行合并。
//•	头插法逆序：通过“头插法”这一简单的链表操作，巧妙地将“摘取最小”的递增过程，直接转化为“构建最大在前”的递减结果，避免了先合并再反转链表的额外开销。
//•	空间效率：整个过程只移动指针，没有创建任何新的 ListNode 节点，完全复用了原有空间，满足了题目的要求。

#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 合并两个非递减(递增)的有序链表为一个非递增(递减)的有序链表。
 * 要求结果链表仍使用原来两个链表的存储空间，不另外占用其它的存储空间。
 * 表中允许有重复的数据。
 *
 * @param l1 第一个有序链表
 * @param l2 第二个有序链表
 * @return 合并后的链表头结点
 */


 //下面的代码有问题,输出的是递增的链表,结果是需要递减的链表
//ListNode* mergeTwoListsDesc(ListNode* l1, ListNode* l2) {
//	if (!l1) return l2;
//	if (!l2) return l1;
//	ListNode* head = nullptr;
//	// 确定合并后链表的头结点
//	if (l1->val < l2->val) {
//		head = l1;
//		l1 = l1->next;
//	}
//	else if (l1->val > l2->val) {
//		head = l2;
//		l2 = l2->next;
//	}
//	else {
//		// 如果头结点值相同
//		head = l1;
//		l1 ->next = l2;
//		l2 = l2->next;
//	}
//	ListNode* current = head;
//	while (l1&&l2)
//	{
//		if (l1->val < l2->val)
//		{
//			current->next = l1;
//			l1 = l1->next;
//		}
//		else if (l1->val > l2->val)
//		{
//			current->next = l2;
//			l2 = l2->next;
//		}
//		else
//		{
//			current->next = l1;
//			l1->next = l2;
//			l2 = l2->next;
//		}
//		current = current->next;
//	}
//	if (l1) current->next = l1;
//	if (l2) current->next = l2;
//	return head;
//}


ListNode* mergeTwoListsDesc(ListNode* l1, ListNode* l2)
{
	ListNode* head = nullptr; // 1. 初始化结果链表的头指针为空
	ListNode* temp = nullptr;

	// 2. 当两个链表都还有节点时，循环处理
	while (l1 && l2) {
		// 2.1. 比较并找出值更小的节点
		if (l1->val <= l2->val) {
			temp = l1;      // 临时保存 l1 的头结点
			l1 = l1->next;  // l1 指针后移
		}
		else {
			temp = l2;      // 临时保存 l2 的头结点
			l2 = l2->next;  // l2 指针后移
		}
		// 2.2. 头插法：将取出的节点 temp 插入到 head 的前面
		temp->next = head;  // temp 的下一个指向当前的 head
		head = temp;        // 更新 head 为 temp，使其成为新的头
	}

	// 3. 处理其中一个链表剩下的部分
	// 此时 l1 和 l2 最多只有一个不为空
	ListNode* rest = l1 ? l1 : l2;
	while (rest) {
		temp = rest;
		rest = rest->next;
		// 同样使用头插法将剩余节点逐个插入
		temp->next = head;
		head = temp;
	}

	return head; // 4. 返回最终构建好的递减链表的头结点
}

// 辅助函数：打印链表
void printList(ListNode* head) {
	ListNode* current = head;
	while (current) {
		std::cout << current->val << " -> ";
		current = current->next;
	}
	std::cout << "NULL" << std::endl;
}

// 辅助函数：根据数组创建链表
ListNode* createList(const std::initializer_list<int>& vals) {
	if (vals.size() == 0) {
		return nullptr;
	}
	auto it = vals.begin();
	ListNode* head = new ListNode(*it);
	ListNode* current = head;
	it++;
	while (it != vals.end()) {
		current->next = new ListNode(*it);
		current = current->next;
		it++;
	}
	return head;
}

int main() {
	// 生成mergeTwoListsDesc的测试用例

		// 测试用例 1: 基本情况
	std::cout << "测试用例 1: 基本情况" << std::endl;
	ListNode* l1_1 = createList({ 1, 3, 5 });
	ListNode* l2_1 = createList({ 2, 4, 6 });
	std::cout << "L1: "; printList(l1_1);
	std::cout << "L2: "; printList(l2_1);
	ListNode* merged_1 = mergeTwoListsDesc(l1_1, l2_1);
	std::cout << "合并后 (非递增): "; printList(merged_1);
	std::cout << "预期结果: 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL" << std::endl << std::endl;

	// 测试用例 2: 一个链表为空
	std::cout << "测试用例 2: 一个链表为空" << std::endl;
	ListNode* l1_2 = createList({ 1, 2, 3 });
	ListNode* l2_2 = nullptr;
	std::cout << "L1: "; printList(l1_2);
	std::cout << "L2: "; printList(l2_2);
	ListNode* merged_2 = mergeTwoListsDesc(l1_2, l2_2);
	std::cout << "合并后 (非递增): "; printList(merged_2);
	std::cout << "预期结果: 3 -> 2 -> 1 -> NULL" << std::endl << std::endl;

	// 测试用例 3: 两个链表都为空
	std::cout << "测试用例 3: 两个链表都为空" << std::endl;
	ListNode* l1_3 = nullptr;
	ListNode* l2_3 = nullptr;
	std::cout << "L1: "; printList(l1_3);
	std::cout << "L2: "; printList(l2_3);
	ListNode* merged_3 = mergeTwoListsDesc(l1_3, l2_3);
	std::cout << "合并后 (非递增): "; printList(merged_3);
	std::cout << "预期结果: NULL" << std::endl << std::endl;

	// 测试用例 4: 包含重复值
	std::cout << "测试用例 4: 包含重复值" << std::endl;
	ListNode* l1_4 = createList({ 1, 2, 2, 5 });
	ListNode* l2_4 = createList({ 2, 3, 5, 6 });
	std::cout << "L1: "; printList(l1_4);
	std::cout << "L2: "; printList(l2_4);
	ListNode* merged_4 = mergeTwoListsDesc(l1_4, l2_4);
	std::cout << "合并后 (非递增): "; printList(merged_4);
	std::cout << "预期结果: 6 -> 5 -> 5 -> 3 -> 2 -> 2 -> 2 -> 1 -> NULL" << std::endl << std::endl;

	//// 测试用例 5: 链表长度不同
	//std::cout << "测试用例 5: 链表长度不同" << std::endl;
	//ListNode* l1_5 = createList({ 10, 20 });
	//ListNode* l2_5 = createList({ 1, 2, 3, 30 });
	//std::cout << "L1: "; printList(l1_5);
	//std::cout << "L2: "; printList(l2_5);
	//ListNode* merged_5 = mergeTwoListsDesc(l1_5, l2_5);
	//std::cout << "合并后 (非递增): "; printList(merged_5);
	//std::cout << "预期结果: 30 -> 20 -> 10 -> 3 -> 2 -> 1 -> NULL" << std::endl << std::endl;

	// 注意：由于链表节点被重用和重新链接，原始链表的头指针（如 l1_1, l2_1 等）
	// 在合并后不再代表原始的完整链表。因此，我们不在此处尝试释放内存，
	// 因为这会变得复杂。在实际应用中，需要一个合适的策略来管理合并后链表的内存。

	return 0;
}
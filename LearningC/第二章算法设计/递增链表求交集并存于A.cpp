#include <iostream>
#include <vector>


//2.3
//已知两个链表A和B分别表示两个集合，其元素递增排列。请设计算法求出A与B的交集，并存放于A链表中。
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


// 打印链表
inline void printList(ListNode* head) {
	ListNode* current = head;
	while (current) {
		std::cout << current->val << " -> ";
		current = current->next;
	}
	std::cout << "NULL" << std::endl;
}

// 从vector创建链表
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

//我自己的思路  算法复杂度较高 O(m*n)
void	 intersection_my(ListNode*& A, ListNode*& B)
{
	ListNode* current = nullptr;
	ListNode* head = nullptr;
	//遍历链表A
	for (ListNode* pa = A; pa; pa = pa->next) {
		//在链表B中查找与A中当前节点值相同的节点;
		for (ListNode* pb = B; pb; pb = pb->next) {
			if (pa->val == pb->val) {
				if ( !current)
				{
					current = pa;
				}
				else
				{
					current->next = pa;
					current = current->next;
				}
				if (!head)
				{
					head = current;
				}
			}
		}
	}
	if (current)
	{
		current->next = nullptr;
	}
	A = head;
}

//ai的思路 算法fu复杂度 O(m+n)  AI 的双指针算法利用“两个链表递增”这一特性，只需同步向前扫描一次
void intersection_ai(ListNode*& A, ListNode*& B)
{
	ListNode* dummy = new ListNode(0); // 创建一个哑节点，简化操作
	ListNode* tail = dummy; // 结果链表的尾指针
	ListNode* pa = A;
	ListNode* pb = B;
	while (pa && pb) {
		if (pa->val < pb->val) {
			pa = pa->next; // A的值较小，移动A指针
		}
		else if (pa->val > pb->val) {
			pb = pb->next; // B的值较小，移动B指针
		}
		else {
			// 找到交集元素
			tail->next = pa; // 将交集元素接入结果链表
			tail = tail->next; // 移动尾指针
			pa = pa->next; // 移动A指针
			pb = pb->next; // 移动B指针
		}
	}
	tail->next = nullptr; // 结束结果链表
	A = dummy->next; // 更新A为结果链表的头
	delete dummy; // 删除哑节点
}

//ai的思路 不带哑结点 算法fu复杂度 O(m+n)
void intersection_ai_no_dummy(ListNode*& A, ListNode*& B)
{
	ListNode* head = nullptr; // 结果链表的头指针
	ListNode* tail = nullptr; // 结果链表的尾指针
	ListNode* pa = A;
	ListNode* pb = B;
	while (pa && pb) {
		if (pa->val < pb->val) {
			pa = pa->next; // A的值较小，移动A指针
		}
		else if (pa->val > pb->val) {
			pb = pb->next; // B的值较小，移动B指针
		}
		else {
			// 找到交集元素
			if (!head) {
				head = pa; // 初始化头指针
				tail = pa; // 初始化尾指针
			}
			else {
				tail->next = pa; // 将交集元素接入结果链表
				tail = tail->next; // 移动尾指针
			}
			pa = pa->next; // 移动A指针
			pb = pb->next; // 移动B指针
		}
	}
	if (tail) {
		tail->next = nullptr; // 结束结果链表
	}
	A = head; // 更新A为结果链表的头
}

int main_2_3()
{
	// 测试用例 1: A和B有部分交集
	std::cout << "测试用例 1: A和B有部分交集" << std::endl;
	ListNode* a1 = createList({ 1, 3, 5, 7 });
	ListNode* b1 = createList({ 2, 3, 6, 7 });
	std::cout << "A: "; printList(a1);
	std::cout << "B: "; printList(b1);
	intersection_my(a1, b1); // 假设交集函数为 intersection
	std::cout << "交集 (存入A): "; printList(a1);
	std::cout << "-------------------------" << std::endl;


	// 测试用例 2: A和B没有交集
	std::cout << "测试用例 2: A和B没有交集" << std::endl;
	ListNode* a2 = createList({ 1, 3, 5 });
	ListNode* b2 = createList({ 2, 4, 6 });
	std::cout << "A: "; printList(a2);
	std::cout << "B: "; printList(b2);
	intersection_my(a2, b2);
	 std::cout << "交集 (存入A): "; printList(a2);
	std::cout << "-------------------------" << std::endl;

	// 测试用例 3: B是A的子集
	std::cout << "测试用例 3: B是A的子集" << std::endl;
	ListNode* a3 = createList({ 1, 2, 3, 4, 5 });
	ListNode* b3 = createList({ 2, 4 });
	std::cout << "A: "; printList(a3);
	std::cout << "B: "; printList(b3);
	intersection_my(a3, b3);
	 std::cout << "交集 (存入A): "; printList(a3);
	std::cout << "-------------------------" << std::endl;

	// 测试用例 4: 其中一个链表为空 (B为空)
	std::cout << "测试用例 4: B为空" << std::endl;
	ListNode* a4 = createList({ 1, 2, 3 });
	ListNode* b4 = createList({});
	std::cout << "A: "; printList(a4);
	std::cout << "B: "; printList(b4);
	intersection_my(a4, b4);
	 std::cout << "交集 (存入A): "; printList(a4);
	std::cout << "-------------------------" << std::endl;

	// 测试用例 5: 两个链表完全相同
	std::cout << "测试用例 5: 两个链表完全相同" << std::endl;
	ListNode* a5 = createList({ 10, 20, 30 });
	ListNode* b5 = createList({ 10, 20, 30 });
	std::cout << "A: "; printList(a5);
	std::cout << "B: "; printList(b5);
	intersection_my(a5, b5);
	 std::cout << "交集 (存入A): "; printList(a5);
	std::cout << "-------------------------" << std::endl;

	// 注意：这里没有实现内存释放，在实际项目中需要注意delete创建的节点。
	

	return 0;
}
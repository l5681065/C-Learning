// 详细设计（伪代码）：
// 1. 定义单链表结点结构 ListNode，包含 int val 和 ListNode* next。
// 2. 编写 createList 函数：接收一个整数向量，创建带头结点的单链表并返回头结点指针（头结点为哑结点）。
//    - 新建头结点 head（val 可为 0）
//    - 使用 tail 指针将每个输入值作为新结点追加到链表尾部
//    - 返回 head
// 3. 编写 splitList 函数：将带头结点的链表 A 分解为两个带头结点的链表 B、C。
//    - 输入：A 的头结点指针（A->next 指向第一个真正结点）
//    - 创建两个哑头 Bhead、Chead，以及对应的尾指针 bTail、cTail（初始指向各自哑头）
//    - 遍历 A 的非头结点：对于遍历到的结点 cur，先保存 next = cur->next，然后根据 cur->val 的符号：
//        - 如果 < 0：将 cur 接到 bTail->next；更新 bTail = cur
//        - 如果 > 0：将 cur 接到 cTail->next；更新 cTail = cur
//      （题目保证元素为非零整数）
//    - 遍历结束后：将 bTail->next = nullptr，cTail->next = nullptr，A->next = nullptr（A 被拆空）
//    - 返回 Bhead 和 Chead（通过引用参数或 pair）
// 4. 编写 printList 工具：打印带头结点链表的元素（用于测试）
// 5. 在 main 中：为若干测试用例创建链表 A，打印 A，调用 splitList 得到 B、C，打印 B、C，并释放内存。
//    - 测试用例：混合正负、全正、全负、空表边界等
// 6. 编写 freeList 函数：释放带头结点链表所有结点（包括哑头）
// 7. 确保所有操作均为移动结点（不复制结点数据），符合题意“利用 A 表的结点”
// 实现注意事项：
// - 使用 C++14，代码自包含，不依赖外部 ListUtils.hpp 的实现（仅保留包含以兼容原文件）
// - 输出格式简洁，便于在 Visual Studio 输出窗口查看

#include "ListUtils.hpp"
#include <iostream>
#include <vector>
#include <initializer_list>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int v = 0) : val(v), next(nullptr) {}
};

// 创建带头结点的链表
ListNode* createList(const std::vector<int>& vals)
{
	ListNode* head = new ListNode(); // 哑头
	ListNode* tail = head;
	for (int v : vals)
	{
		ListNode* node = new ListNode(v);
		tail->next = node;
		tail = node;
	}
	return head;
}

// 打印链表（跳过哑头），格式: name: v1 v2 v3
void printList(ListNode* head, const char* name)
{
	std::cout << name << ":";
	if (!head || !head->next)
	{
		std::cout << " (empty)\n";
		return;
	}
	ListNode* p = head->next;
	while (p)
	{
		std::cout << " " << p->val;
		p = p->next;
	}
	std::cout << "\n";
}

// 释放链表所有结点（包含哑头）
void freeList(ListNode* head)
{
	ListNode* p = head;
	while (p)
	{
		ListNode* nxt = p->next;
		delete p;
		p = nxt;
	}
}

// 将 A 分解为 B（<0）和 C (>0)，均为带哑头的链表。A 的结点被重用，A 最终为空（A->next = nullptr）
void splitList(ListNode* A, ListNode*& B, ListNode*& C)
{
	ListNode* BTail, * CTail;
	B = new ListNode(0); // B 哑头
	C = new ListNode(0); // C 哑头
	BTail = B;
	CTail = C;
	while (A)
	{
		if (A->next < 0)
		{
			BTail->next = A;
			BTail = BTail->next;
		}
		else
		{
			CTail->next = A;
			CTail = CTail->next;
		}
		A = A->next;
	}
}

// 便捷测试：运行单个测试用例，打印并拆分
void runTest(const std::vector<int>& vals)
{
	ListNode* A = createList(vals);
	printList(A, "A (original)");
	ListNode* B = nullptr;
	ListNode* C = nullptr;
	splitList(A, B, C);
	printList(B, "B (<0)");
	printList(C, "C (>0)");
	// 释放内存：B、C 是用 A 的结点组成的，且 A 头与 B/C 头均为新分配，需要分别释放
	freeList(A); // A 是哑头但已无数据结点
	freeList(B);
	freeList(C);
	std::cout << "--------------------------\n";
}

int main()
{
	// 测试用例：混合正负
	runTest({ 5, -3, 7, -1, 2, -8 });
	// 全正
	runTest({ 1, 2, 3, 4 });
	// 全负
	runTest({ -1, -2, -3 });
	// 交替
	runTest({ -5, 6, -7, 8, -9, 10 });
	// 单元素正
	runTest({ 42 });
	// 单元素负
	runTest({ -42 });
	// 空表（无元素）
	runTest({});
	return 0;
}
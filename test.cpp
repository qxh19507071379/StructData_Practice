#include <iostream>
using namespace std;
typedef struct ListNode {
	int data;
	struct ListNode* pNext;
}Node;
Node* CreateHead() {
	Node* head = new Node[sizeof(Node)];
	head->data = -1;
	head->pNext = NULL;
	return head;
}
Node* CreateNode(int val) {
	Node* node = new Node[sizeof(Node)];
	node->pNext = NULL;
	node->data = val;
	return node;
}
void Push_back(Node* head, int val) {
	Node* node = CreateNode(val);
	Node* pCur = head;
	while (pCur->pNext) {
		pCur = pCur->pNext;
	}
	pCur->pNext = node;
}
void CoutList(Node* head) {
	Node* pCur = head->pNext;
	if (pCur == NULL) {
		return;
	}
	while (pCur) {
		cout << pCur->data << " ";
		pCur = pCur->pNext;
	}
	cout << endl;
}
Node* solution(Node* head, int k, int m) {
	Node* pCur = head->pNext;
	Node* pFur = head;
	for (int i = 1; i < k; i++) {
		pFur = pCur;
		pCur = pCur->pNext;
	}
	int ans = 1;
	while (true) {
		if (head->pNext == pCur && pCur->pNext == nullptr) {
			return head;
		}
		else {
			pFur = pCur;
			pCur = pCur->pNext;
			ans++;
		}
		if (ans == m) {
			if (pCur->pNext == nullptr) {
				pFur->pNext = pCur->pNext;
				pCur = pFur->pNext;
				pFur = head;
				pCur = head->pNext;
				ans = 1;
			}
			else if (pCur->pNext->pNext == nullptr) {
				pFur->pNext = pCur->pNext;
				pCur = pFur->pNext;
				pFur = head;
				pCur = head->pNext;
				if (ans == m) {
					pFur->pNext = pCur->pNext;
					pCur = pFur->pNext;
					ans = 1;
				}
			}
			else {
				pFur->pNext = pCur->pNext;
				pCur = pFur->pNext;
				ans = 1;
			}
		}
	}
}
void test() {
	Node* list = CreateHead();
	int n,k,m;
	cin >> n>>k>>m;
	for (int i = 0; i < n; i++) {
		Push_back(list, i + 1);
	}
	solution(list, k, m);
	CoutList(list);
}
int main() {
	test();
	return 0;
}
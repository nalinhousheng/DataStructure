#include"LinkList.h"

int main() {
	LinkList<int> list;
	LNode<int>* node1 = new LNode<int>;
	node1->data = 1;
	LNode<int>* node2 = new LNode<int>;
	node2->data = 2;
	LNode<int>* node3 = new LNode<int>;
	node3->data = 3;
	list.CreateLinkList(5);
	list.TravalLinkList();
	list.InsertNode(1, node1);
	list.InsertNode(2, node2);
	list.InsertNode(3, node3);
	list.TravalLinkList();
	list.DeleteNode(3);
	list.TravalLinkList();
	getchar();
	getchar();
	return 0;
}
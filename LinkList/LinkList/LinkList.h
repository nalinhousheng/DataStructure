//单链表

#pragma once

#include<iostream>
using namespace std;

template<class elemType>
class LNode {
public:
	elemType data;//数据域
	LNode* next;//指针域
	LNode() { data = 0; next = NULL; }
};

template<class elemType>
class LinkList {
public:
	LNode<elemType> *head;
	int length;
	LinkList();
	~LinkList();
	bool IsEmpty() { return head->next == NULL; }
	int CreateLinkList(int n);//创建
	int DestoryLinkList();//销毁
	int InsertNode(int,LNode<elemType>*);//插入节点
	int DeleteNode(int);//按位序删除
	int TravalLinkList();//遍历
};

template<class elemType>
LinkList<elemType>::LinkList() {
	head = new LNode<elemType>;
	length = 0;
}

template<class elemType>
LinkList<elemType>::~LinkList() {
	delete head;
}

template<class elemType>
int LinkList<elemType>::CreateLinkList(int n) {
	if (n <= 0) {
		cout << "error" << endl;
		return -1;
	}
	length = n;
	LNode<elemType> *temp = new LNode<elemType>;
	temp = head;
	for (int i = 0; i < n; i++) {
		LNode<elemType> *tempData = new LNode<elemType>;
		cout << "第" << i + 1 << "个节点：" << endl;
		cin >> tempData->data;
		temp->next = tempData;
		temp = tempData;
	}
	return 0;
}

template<class elemType>
int LinkList<elemType>::DestoryLinkList() {
	if (head==NULL) {
		cout << "链表为空" << endl;
		return -1;
	}
	LNode<elemType> temp = new LNode<elemType>;
	while (head != NULL) {
		temp = head->next;
		delete head;
		head = temp;
	}
	return 0;
}

//插入节点
template<class elemType>
int LinkList<elemType>::InsertNode(int i, LNode<elemType>* p) {
	if (i<0||i>length+1) {
		cout << "error" << endl;
		return -1;
	}
	if (IsEmpty()&&i>1) {
		cout << "链表为空" << endl;
		return -1;
	}
	LNode<elemType>* temp = new LNode<elemType>;
	temp->data = p->data;
	if (i < 2) {
		temp->next = head->next;
		head->next = temp;
	}
	else if (i > length) {
		LNode<elemType>* q = new LNode<elemType>;
		q = head;
		while (q->next!=NULL) {
			q = q->next;
		}
		q->next = temp;
	}
	else {
		LNode<elemType>* q = new LNode<elemType>;
		q = head;
		for (int j = 1; j < i; j++) {
			q = q->next;
		}
		temp->next = q->next;
		q->next = temp;
	}
	length++;
	return 0;
}

//按位序删除节点
template<class elemType>
int LinkList<elemType>::DeleteNode(int i) {
	if (i > length||i<1) {
		cout << "error" << endl;
		return -1;
	}
	if (IsEmpty()) {
		cout << "链表为空" << endl;
		return -1;
	}
	LNode<elemType>* temp = new LNode<elemType>;
	if (i < 2) {
		temp = head->next;
		head->next = temp->next;
		free(temp);
	}
	else if (i == length) {
		temp = head;
		for (int j = 1; j < length; j++) {
			temp = temp->next;
		}
		LNode<elemType>* temp2 = new LNode<elemType>;
		temp2 = temp->next;
		temp->next = NULL;
		delete temp2;
	}
	else {
		temp = head;
		for (int j = 1; j < i; j++) {
			temp = temp->next;
		}
		LNode<elemType>* temp2 = new LNode<elemType>;
		temp2 = temp->next;
		temp->next = temp2->next;
		delete temp2;
	}
	length--;
	return 0;
}

//遍历
template<class elemType>
int LinkList<elemType>::TravalLinkList() {
	if (length == 0) {
		cout << "链表为空" << endl;
		return -1;
	}
	LNode<elemType>* p=head->next;
	while(p!=NULL) {
		cout << p->data << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
	return 0;
}

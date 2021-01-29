#pragma once
#include<iostream>
using namespace std;

template<class T>
class LNode{
public:
	T data;
	LNode* prior, *next;
	LNode() { data = 0; prior = NULL; next = NULL; }
};

template<class T>
class DLinkList {
public:
	LNode<T>* head;
	int length;
	DLinkList();
	~DLinkList();
	int CreateLinkList(int);//����
	int DestoryLinkList();//����
	int InsertNode(int, LNode<T>*);//����ڵ�
	int DeleteNode(int);//��λ��ɾ��
	int TravalLinkList();//����
};

template<class T>
DLinkList<T>::DLinkList() {
	head = new LNode<T>;
	length = 0;
}

template<class T>
DLinkList<T>::~DLinkList() {
	delete head;
}

template<class T>
int DLinkList<T>::CreateLinkList(int n) {
	if (n < 1) {
		cout << "error" << endl;
		return -1;
	}
	return 0;
}
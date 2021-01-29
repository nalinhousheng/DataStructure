//˳���

#pragma once

#include<iostream>
using namespace std;

//Ĭ����󳤶�
#define InitSize 10

template <class elemType>
class SqList {
private:
	elemType * data;//��ָ��ָʾ��̬��������
	int length;//˳���ǰ����
	int MaxSize;//�������
public:
	SqList();//��ʼ��
	bool PrintList();//��ӡ˳���
	bool ListInsert(int,elemType);//����
	bool ListDelete(int, elemType&);//ɾ��
	elemType GetElem(int);//��λ����
	int LocateElem(elemType);//��ֵ����
};

template <class elemType>
SqList<elemType>::SqList() {
	MaxSize = InitSize;
	data = new elemType[MaxSize];
	length = 0;
}

//��ӡ˳���
template <class elemType>
bool SqList<elemType>::PrintList() {
	if (length < 1) { return false; }
	for (int i = 0; i < length; i++) {
		cout << data[i];
	}
	return true;
}

//����
template <class elemType>
bool SqList<elemType>::ListInsert(int i,elemType e) {
	if (i<1 || i>length + 1) { return false; }
	for (int j = length; j >= i; j--) {
		data[j] = data[j - 1];
	}
	data[i - 1] = e;
	length++;
	return true;
}

//ɾ��
template <class elemType>
bool SqList<elemType>::ListDelete(int i,elemType& e)
{
	if (i<1 || i>length ) { return false; }
	e = data[i - 1];
	for (int j = i; j < length; j++) {
		data[j-1] = data[j];
	}
	length--;
	return true;
}

//��λ����
template<class elemType>
elemType SqList<elemType>::GetElem(int i) {
	return data[i - 1];
}

//��ֵ����
template<class elemType>
int SqList<elemType>::LocateElem(elemType e) {
	for (int i = 0; i < length; i++) {
		if (data[i] == e) {
			return i;
		}
	}
	return -1;
}
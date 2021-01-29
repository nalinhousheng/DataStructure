//˳���

#pragma once

#include<iostream>
using namespace std;

//˳����������
#define MaxSize 10

class SqList {
private:
	int data[MaxSize];//�þ�̬����������Ԫ��
	int length;//���鵱ǰ����
public:
	SqList(); //��ʼ��
	int GetLength();//���ص�ǰ����
	void PrintList();//��ӡ˳���
	bool ListInsert(int,int);//����
	bool ListDelete(int, int&);//ɾ��
	int GetElem(int);//��λ����
	int LocateElem(int);//��ֵ����
};

//��ʼ��
SqList::SqList() {
	for (int i = 0; i < MaxSize; i++) {
		data[i] = 0;
	}
	length = 0;
}

//���ص�ǰ����
int SqList::GetLength() {
	return length;
}

//��ӡ˳���
void SqList::PrintList() {
	for (int i = 0; i < length; i++) {
		cout << data[i]<<endl;
	}
}

//����
bool SqList::ListInsert(int i, int e) {
	if (i > length + 1 || i < 1) {
		return false;
	}
	if (length>=MaxSize) {
		return false;
	}
	for (int j = length; j >= i; j--) {
		data[j] = data[j - 1];
	}
	data[i - 1] = e;
	length++;
	return true;
}

//ɾ��
bool SqList::ListDelete(int i, int&e) {
	if (i > length || i < 1) {
		return false;
	}
	e = data[i - 1];
	for (int j = i; j < length; j++) {
		data[j-1] = data[j];
	}
	length--;
	return true;
}

//��λ����
int SqList::GetElem(int i) {
	return data[i - 1];
}

//��ֵ����
int SqList::LocateElem(int e) {
	for (int i = 0; i < length; i++) {
		if (data[i] == e) {
			return i + 1;
		}
	}
	return 0;
}
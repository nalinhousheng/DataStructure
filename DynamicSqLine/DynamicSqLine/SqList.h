//顺序表

#pragma once

#include<iostream>
using namespace std;

//默认最大长度
#define InitSize 10

template <class elemType>
class SqList {
private:
	elemType * data;//用指针指示动态分配数组
	int length;//顺序表当前长度
	int MaxSize;//最大容量
public:
	SqList();//初始化
	bool PrintList();//打印顺序表
	bool ListInsert(int,elemType);//插入
	bool ListDelete(int, elemType&);//删除
	elemType GetElem(int);//按位查找
	int LocateElem(elemType);//按值查找
};

template <class elemType>
SqList<elemType>::SqList() {
	MaxSize = InitSize;
	data = new elemType[MaxSize];
	length = 0;
}

//打印顺序表
template <class elemType>
bool SqList<elemType>::PrintList() {
	if (length < 1) { return false; }
	for (int i = 0; i < length; i++) {
		cout << data[i];
	}
	return true;
}

//插入
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

//删除
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

//按位查找
template<class elemType>
elemType SqList<elemType>::GetElem(int i) {
	return data[i - 1];
}

//按值查找
template<class elemType>
int SqList<elemType>::LocateElem(elemType e) {
	for (int i = 0; i < length; i++) {
		if (data[i] == e) {
			return i;
		}
	}
	return -1;
}
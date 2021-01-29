//顺序表

#pragma once

#include<iostream>
using namespace std;

//顺序表最大容量
#define MaxSize 10

class SqList {
private:
	int data[MaxSize];//用静态数组存放数据元素
	int length;//数组当前长度
public:
	SqList(); //初始化
	int GetLength();//返回当前长度
	void PrintList();//打印顺序表
	bool ListInsert(int,int);//插入
	bool ListDelete(int, int&);//删除
	int GetElem(int);//按位查找
	int LocateElem(int);//按值查找
};

//初始化
SqList::SqList() {
	for (int i = 0; i < MaxSize; i++) {
		data[i] = 0;
	}
	length = 0;
}

//返回当前长度
int SqList::GetLength() {
	return length;
}

//打印顺序表
void SqList::PrintList() {
	for (int i = 0; i < length; i++) {
		cout << data[i]<<endl;
	}
}

//插入
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

//删除
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

//按位查找
int SqList::GetElem(int i) {
	return data[i - 1];
}

//按值查找
int SqList::LocateElem(int e) {
	for (int i = 0; i < length; i++) {
		if (data[i] == e) {
			return i + 1;
		}
	}
	return 0;
}
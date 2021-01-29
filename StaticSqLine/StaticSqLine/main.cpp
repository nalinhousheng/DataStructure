#include"SqList.h"

int main() {
	SqList L;
	L.ListInsert(1, 1);
	L.ListInsert(2, 2);
	L.PrintList();
	int e = -1;
	L.ListDelete(1, e);
	cout << e << endl;
	L.PrintList();
	getchar();
	return 0;
}
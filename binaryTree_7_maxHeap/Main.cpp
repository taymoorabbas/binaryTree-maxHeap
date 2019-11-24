#include<iostream>
#include"Classes.h"
using namespace std;

int main(){

	cout << "this project is availible on github" << endl;
	cout << "hello world" << endl;
	Heap heap;

	heap.insert(5);
	heap.insert(6);
	heap.insert(10);
	heap.breadthFirst();
	heap.search(6);
	heap.remove();
	heap.breadthFirst();
	system("pause");

}
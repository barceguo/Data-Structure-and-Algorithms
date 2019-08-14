#ifndef DOUBLE_LINK_H
#define DOUBLE_LINK_H

#include <iostream>
using namespace std;

template<class T>
struct Node
{
public:
	T val;
	Node *prev;
	Node *next;
public:
	Node(){}
	Node(T t,Node *prev,Node *next){
		this->val=t;
		this->prev=prev;
		this->next=next;
	}

};

template<class T>
class DoubleLink
{
public:
	DoubleLink();
	~DoubleLink();

	int size();
	bool is_empty();

	T get(int index);
	T get_first();
	T get_last();

	bool insert(T t,int index);
	bool insert_first(T t);
	bool insert_last(T t);

	bool del(int index);
	bool delete_first();
	bool delete_last();
private:
	int count;
	Node<T> *phead;
	Node<T> *get_node(int index);

};

template<class T>
DoubleLink<T>::DoubleLink() :count(0)
{
	phead = new Node<T>();
	phead->prev=phead->next=phead;
}

//析构函数
template<class T>
DoubleLink<T>::~DoubleLink()
{
	//删除所有节点
	Node<T> *pnode=phead->next;
	Node<T> *ptemp=NULL;
	while(pnode!=phead){
		ptemp=pnode;
		pnode=pnode->next;
		delete ptemp;
	}
	//删除表头
	delete phead;
	phead = NULL;
	count=0;
}

//获取链表大小
template<class T>
int DoubleLink<T>::size(){
	return count;
}

//判断链表是否为空
template<class T>
bool DoubleLink<T>::is_empty(){
	return count==0;
}

//获取第index位置节点
template<class T>
Node<T>* DoubleLink<T>::get_node(int index){
	if(index<0 ||index>=count){
		cout<<"get node error,index out of range!"<<endl;
		return NULL;
	}
	if(index<(count/2)){
		int i=0;
		Node<T>* pnode=phead->next;
		while(i++<index){
			pnode=pnode->next;
		}
		return pnode;
	}
	int rindex=count-index-1,i=0;
	Node<T>* pnode=phead->prev;
	while(i++<rindex){
		pnode=pnode->prev;
	}
	return pnode;
}
//获取第index位置元素
template<class T>
T DoubleLink<T>::get(int index){
	return get_node(index)->val;
}
//获取第一个节点元素
template<class T>
T DoubleLink<T>::get_first(){
	return get_node(0)->val;
}
//获取最后节点的元素
template<class T>
T DoubleLink<T>::get_last(){
	return get_node(count-1)->val;
}

//index位置插入节点
template<class T>
bool DoubleLink<T>::insert(T t,int index){
	if(index==0) return insert_first(t);
	Node<T> *pindex = get_node(index);
	if(!pindex)
		return false;
	Node<T> *pnode = new Node<T>(t,pindex->prev,pindex);
	pindex->prev->next= pnode;
	pindex->prev=pnode;
	count++;
	return true;
}
//表头插入节点
template<class T>
bool DoubleLink<T>::insert_first(T t){
	Node<T> *pnode = new Node<T>(t,phead,phead->next);
	phead->next->prev= pnode;
	phead->next=pnode;
	count++;
	return true;
}
//末尾插入节点
template<class T>
bool DoubleLink<T>::insert_last(T t){
	Node<T> *pnode = new Node<T>(t,phead->prev,phead);
	phead->prev->next= pnode;
	phead->prev=pnode;
	count++;
	return true;
}

//删除index位置节点
template<class T>
bool DoubleLink<T>::del(int index){
	Node<T> *pnode=get_node(index);
	if(!pnode)
		return false;
	pnode->next->prev = pnode->prev;
	pnode->prev->next = pnode->next;
	delete pnode;
	count--;
	return true;
}
//删除第一个节点
template<class T>
bool DoubleLink<T>::delete_first(){
	
	return del(0);
}
//删除最后一节点
template<class T>
bool DoubleLink<T>::delete_last(){
	
	return del(count-1);
}

#endif
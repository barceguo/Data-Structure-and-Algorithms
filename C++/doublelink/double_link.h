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

//��������
template<class T>
DoubleLink<T>::~DoubleLink()
{
	//ɾ�����нڵ�
	Node<T> *pnode=phead->next;
	Node<T> *ptemp=NULL;
	while(pnode!=phead){
		ptemp=pnode;
		pnode=pnode->next;
		delete ptemp;
	}
	//ɾ����ͷ
	delete phead;
	phead = NULL;
	count=0;
}

//��ȡ�����С
template<class T>
int DoubleLink<T>::size(){
	return count;
}

//�ж������Ƿ�Ϊ��
template<class T>
bool DoubleLink<T>::is_empty(){
	return count==0;
}

//��ȡ��indexλ�ýڵ�
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
//��ȡ��indexλ��Ԫ��
template<class T>
T DoubleLink<T>::get(int index){
	return get_node(index)->val;
}
//��ȡ��һ���ڵ�Ԫ��
template<class T>
T DoubleLink<T>::get_first(){
	return get_node(0)->val;
}
//��ȡ���ڵ��Ԫ��
template<class T>
T DoubleLink<T>::get_last(){
	return get_node(count-1)->val;
}

//indexλ�ò���ڵ�
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
//��ͷ����ڵ�
template<class T>
bool DoubleLink<T>::insert_first(T t){
	Node<T> *pnode = new Node<T>(t,phead,phead->next);
	phead->next->prev= pnode;
	phead->next=pnode;
	count++;
	return true;
}
//ĩβ����ڵ�
template<class T>
bool DoubleLink<T>::insert_last(T t){
	Node<T> *pnode = new Node<T>(t,phead->prev,phead);
	phead->prev->next= pnode;
	phead->prev=pnode;
	count++;
	return true;
}

//ɾ��indexλ�ýڵ�
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
//ɾ����һ���ڵ�
template<class T>
bool DoubleLink<T>::delete_first(){
	
	return del(0);
}
//ɾ�����һ�ڵ�
template<class T>
bool DoubleLink<T>::delete_last(){
	
	return del(count-1);
}

#endif
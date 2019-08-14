#include <stdio.h>
#include <malloc.h>
#include "double_link.h"

/**
 * C ����ʵ�ֵ�˫�������ܴ洢����Ԫ�� *
 * @author barceguo
 * @date 2019/08/14
 */
// ˫������ڵ�

typedef struct dlink_node{
	struct dlink_node *prev;
	struct dlink_node *next;
	void *p;
}node;

static node *phead = NULL;
static int count = 0;

static node* create_node(void *pval){
	node *pnode=NULL;
	pnode = (node*)malloc(sizeof(node));
	if(!pnode){
		printf("create node error");
		return NULL;
	}
	pnode->next = pnode->prev = pnode;
	pnode->p = pval;
	return pnode;
}

static node* get_node(int index){
	if(index<0 || index>=count){
		printf("%s error:index out of range!\n",__FUNCTION__);
		return NULL;
	}
	if(index<=(count/2))
	{
		node *pnode = phead->next;
		int i=0;
		while((i++)<index){
			pnode = pnode->next;
		}
		return pnode;
	}else{
		node *pnode = phead->prev;
		int j=0;
		int rindex=count-index-1;
		while((j++)<rindex){
			pnode = pnode->prev;
		}
		return pnode;
	}

}

static node* get_node_first(){
	return get_node(0); 
}

static node* get_node_last(){
	return get_node(count-1); 
}


int create_dlink(){
	phead = create_node(NULL);
	if(!phead)
		return -1;	
	count = 0;
	return 0;

}


//�ͷ�˫�������ɹ�����0��ʧ�ܷ���-1
int destroy_dlink(){
	if(!phead)
	{
		printf("%s error:dlink is null!\n",__FUNCTION__);
		return -1;
	}
	node *pnode = phead->next;
	node *ptemp = NULL;
	while(pnode!=phead){
		ptemp=pnode;
		pnode=pnode->next;
		free(ptemp);
	}
	free(phead);
	phead = NULL;
	count=0;
	return 0;

}

//˫�������Ƿ�λ�գ��շ���1�����շ���0
int dlink_is_empty(){
	return count == 0;
}
//˫�������С
int dlink_size(){
	return count;
}

//��ȡ��indexλ�õĽڵ�Ԫ�أ��ɹ����ؽڵ�ֵ��ʧ�� ����NULL
void* dlink_get(int index){
	node *pnode = get_node(index);
	if(!pnode){
		printf("%s error",__FUNCTION__);
		return NULL;
	}
	return pnode->p;
}
//��ȡ���һ��λ�õĽڵ�Ԫ�أ��ɹ����ؽڵ�ֵ��ʧ�� ����NULL
void* dlink_last(){
	return dlink_get(0);
}
//��ȡ��1���ڵ�Ԫ�أ��ɹ����ؽڵ�ֵ��ʧ�� ����NULL
void* dlink_first(){
	return dlink_get(count-1);
}

//��indexλ�ò���ڵ㣬�ɹ����ؽڵ�0��ʧ�� ����-1
int dlink_insert(int index,void *pval){
	if(index == 0) return dlink_insert_first(pval);
	node *pindex=get_node(index);
	if(!pindex)
		return -1;
	node *pnode = create_node(pval);
	if(!pnode)
		return -1;
	pnode->prev=pindex->prev;
	pnode->next=pindex;
	pindex->prev->next=pnode;
	pindex->prev=pnode;
	count++;
	return 0;
}
//��ͷ����ڵ㣬�ɹ����ؽڵ�0��ʧ�� ����-1
int dlink_insert_first(void *pval){
	node *pnode = create_node(pval);
	if(!pnode)
		return -1;
	pnode->prev=phead;
	pnode->next=phead->next;
	phead->next->prev=pnode;
	phead->next=pnode;
	count++;
	return 0;
}
//��β����ڵ㣬�ɹ����ؽڵ�0��ʧ�� ����-1
int dlink_insert_last(void *pval){
	node *pnode = create_node(pval);
	if(!pnode)
		return -1;
	pnode->prev=phead->prev;
	pnode->next=phead;
	phead->prev->next=pnode;
	phead->prev=pnode;
	count++;
	return 0;
}

//ɾ����indexλ�ýڵ㣬�ɹ����ؽڵ�0��ʧ�� ����-1
int dlink_delete(int index){
	node *pindex=get_node(index);
	if(!pindex)
		return -1;
	pindex->next->prev=pindex->prev;
	pindex->prev->next=pindex->next;
	free(pindex);
	count--;
	return 0;
}

//ɾ����ͷ�ڵ㣬�ɹ����ؽڵ�0��ʧ�� ����-1
int dlink_delete_first(){
	return dlink_delete(0);
}

//ɾ����β�ڵ㣬�ɹ����ؽڵ�0��ʧ�� ����-1
extern int dlink_delete_last(){
	return dlink_delete(count-1);
}

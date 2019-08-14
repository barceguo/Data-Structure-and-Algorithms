#ifndef _DOUBLE_LINK_H
#define _DOUBLE_LINK_H

//新建双向链表；成功返回0，失败返回-1
extern int create_dlink();
//释放双向链表；成功返回0，失败返回-1
extern int destroy_dlink();

//双向链表是否位空，空返回1，不空返回0
extern int dlink_is_empty();
//双向链表大小
extern int dlink_size();

//获取第index位置的节点，成功返回节点指针，失败 返回NULL
extern void* dlink_get(int index);
//获取最后一个位置的节点，成功返回节点指针，失败 返回NULL
extern void* dlink_last();
//获取第1个节点，成功返回节点指针，失败 返回NULL
extern void* dlink_first();

//第index位置插入节点，成功返回节点0，失败 返回-1
extern int dlink_insert(int index,void *pval);
//表头插入节点，成功返回节点0，失败 返回-1
extern int dlink_insert_first(void *pval);
//表尾插入节点，成功返回节点0，失败 返回-1
extern int dlink_insert_last(void *pval);

//删除第index位置节点，成功返回节点0，失败 返回-1
extern int dlink_delete(int index);
//删除表头节点，成功返回节点0，失败 返回-1
extern int dlink_delete_first();
//删除表尾节点，成功返回节点0，失败 返回-1
extern int dlink_delete_last();

#endif
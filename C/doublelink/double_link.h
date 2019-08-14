#ifndef _DOUBLE_LINK_H
#define _DOUBLE_LINK_H

//�½�˫�������ɹ�����0��ʧ�ܷ���-1
extern int create_dlink();
//�ͷ�˫�������ɹ�����0��ʧ�ܷ���-1
extern int destroy_dlink();

//˫�������Ƿ�λ�գ��շ���1�����շ���0
extern int dlink_is_empty();
//˫�������С
extern int dlink_size();

//��ȡ��indexλ�õĽڵ㣬�ɹ����ؽڵ�ָ�룬ʧ�� ����NULL
extern void* dlink_get(int index);
//��ȡ���һ��λ�õĽڵ㣬�ɹ����ؽڵ�ָ�룬ʧ�� ����NULL
extern void* dlink_last();
//��ȡ��1���ڵ㣬�ɹ����ؽڵ�ָ�룬ʧ�� ����NULL
extern void* dlink_first();

//��indexλ�ò���ڵ㣬�ɹ����ؽڵ�0��ʧ�� ����-1
extern int dlink_insert(int index,void *pval);
//��ͷ����ڵ㣬�ɹ����ؽڵ�0��ʧ�� ����-1
extern int dlink_insert_first(void *pval);
//��β����ڵ㣬�ɹ����ؽڵ�0��ʧ�� ����-1
extern int dlink_insert_last(void *pval);

//ɾ����indexλ�ýڵ㣬�ɹ����ؽڵ�0��ʧ�� ����-1
extern int dlink_delete(int index);
//ɾ����ͷ�ڵ㣬�ɹ����ؽڵ�0��ʧ�� ����-1
extern int dlink_delete_first();
//ɾ����β�ڵ㣬�ɹ����ؽڵ�0��ʧ�� ����-1
extern int dlink_delete_last();

#endif
#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>

typedef struct ListElmt_
{
	void* data;             							 /*链表数据*/
	struct ListElmt_* next;								 /*链表下一个元素的指针*/
}ListElmt;


typedef struct ListElmt_
{
	int size;											/*链表长度*/
	int (*match)(const void* key1, const void* key2);	/*链表元素比较函数指针*/
	void (*destroy)(void* data); 						/*销毁链表元素*/
	ListElmt* head;										/*链表头*/
	ListElmt* tail;										/*链表尾*/
}List;

/**
 * [list_destroy description] 初始化链表
 * @param list [description]  链表指针	
 * @param (*destroy)(void* data)[description] 销毁链表中的元素的函数指针 
 */
void list_init(List* list, void (*destroy)(void* data));

/**
 * [list_destroy description] 销毁链表
 * @param list [description]  链表指针
 */
void list_destroy(List* list);

/**
 * [list_ins_next description] 在链表中给定的元素后面插入内容为data的元素
 * @param  list    [description] 链表指针
 * @param  element [description] 需要插入的链表元素
 * @param  data    [description] 链表元素的内容
 * @return         [description] 返回插入元素的状态，0表示插入成功，-1 表示插入失败
 */
int list_ins_next(List *list, ListElmt* element,const void* data);

/**
 * [list_rem_next description]
 * @param  list    [description]
 * @param  element [description]
 * @param  data    [description]
 * @return         [description]
 */
int list_rem_next(List *list, ListElmt* element, void ** data);

/**
 * [list_size(list) description]
 * @param  list [description]
 * @return      [description]
 */
#define list_size(list) (list)->size

/**
 * [list_head(list) description]
 * @param  list [description]
 * @return      [description]
 */
#define list_head(list) (list)->head

/**
 * [list_tail(list) description]
 * @param  list [description]
 * @return      [description]
 */
#define list_tail(list) (list)->tail

/**
 * [list_is_head(list) description]
 * @param  head [description]
 * @return      [description]
 */
#define list_is_head(list) ((list)->head == NULL?1:0)

/**
 * [list_is_tail(list) description]
 * @param  head [description]
 * @return      [description]
 */
#define list_is_tail(list) ((list)->head == NULL?1:0)

/**
 * [list_data(element) description]
 * @param  data [description]
 * @return      [description]
 */
#define list_data(element) ((element)->data)

/**
 * [list_next(element) description]
 * @param  element [description]
 * @return         [description]
 */
#define list_next(element) ((element)->next）
#endif
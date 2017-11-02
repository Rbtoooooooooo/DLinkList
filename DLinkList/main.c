//
//  main.c
//  DLinkList
//
//  Created by 罗璞 on 2017/11/1.
//  Copyright © 2017年 Rbtoooooooooo. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"


/**
 双向结点
 */
typedef struct DNode {
    int data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

/**
 insert one elem at an index which is resonable.
 
 @param l 被插入元素的双向链表
 @param index 插入的位序
 @param e 插入的元素
 */
void insertElem(DLinkList l, int index, int e) {
    if (index<1 || index>l->data+1) {
        printf("The index is NOT resonable!!!\n");
    }
    DNode *p = l;
    int i = index;
    while (i != 1) {
        p = p->next;
        i--;
    }
    DNode *s = (DNode*)malloc(sizeof(DNode));
    s->data = e;
    if(index != (l->data+1)) {
        p->next->prior = s;
    }
    s->next = p->next;
    p->next = s;
    s->prior = p;
    l->data++;
}


/**
 建立双向链表

 @param l 头结点
 @return 头结点
 */
DLinkList createDLinkList(DLinkList l) {
    l = (DLinkList)malloc(sizeof(DNode));
    l->data = 0;
    l->next = NULL;
    int x;
    printf("输入-1表示输入完成！\n");
    while (1) {
        scanf("%d", &x);
        if (x==-1) {
            break;
        }
        insertElem(l, l->data+1, x);
//        用insertElem代替一下代码，使代码简洁一点点
//        DNode *n = (DNode*)malloc(sizeof(DNode));
//        n->data = x;
//        n->next = p->next;
//        n->prior = p;
//        p->next = n;
//        p = n;
//        l->data++;
    }
    return l;
}


/**
 打印链表长度及数据

 @param l 需要打印的链表
 */
void print(DLinkList l) {
    if (l->data == 0) {
        printf("链表长度为0！\n");
    } else {
        printf("链表长度为：%d\n", l->data);
        printf("链表中的数据为：");
        DNode *s = l->next;
        while(1) {
            printf("%d ", s->data);
            if(s->next==NULL) {
                printf("\n");
                break;
            }
            s = s->next;
        }
    }
}

/**
 按序号删除某个结点

 @param l 要删除结点的链表
 @param index 要删除的结点的序号
 @return 返回被删除的结点
 */
DNode *deleteElemBySerial(DLinkList l, int index) {
    DNode *p = l;
    if (index<1 || index>l->data) {
        printf("The INDEX is NOT resonable!\n");
        return l;
    }
    while (index--!=0) {
        p = p->next;
    }
    p->next->prior = p->prior;
    p->prior->next = p->next;
    free(p);
    l->data--;
    return p;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    DLinkList l;
    l = createDLinkList(l);
    print(l);
    

    
    
    return 0;
}







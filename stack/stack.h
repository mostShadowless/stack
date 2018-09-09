#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Stack{
	DataType data;
	struct Stack *next;
}Stack;

//��ʼ��ջ
void StackInitial(Stack **s)
{
	(*s)=(Stack *)malloc(sizeof(Stack));
	(*s)->next=NULL;
	if(!(*s)){
		printf("�����ڴ�ռ�ʧ��!\n");
		exit(0);
	}
}
//�ж�ջ�Ƿ�Ϊ��
int StackNotEmpty(Stack *s)
{
	if(s->next==NULL)
		return 0;
	else
		return 1;
}

//��ջ
int StackPush(Stack *s,DataType x)
{
	Stack *p;
	p=(Stack *)malloc(sizeof(Stack));
	if(!p){
		printf("�����ڴ�ռ�ʧ��!\n");
		exit(0);
	}
	p->data=x;
	p->next=s->next;
	s->next=p;
	return 1;
}

//��ջ
int StackPop(Stack *s,DataType *d)
{
	Stack *p=s->next;
	if(s->next==NULL){
		printf("��ջ�ѿգ�������Ԫ�س�ջ!\n");
		return 0;
	}
	else{
		s->next=p->next;
		*d=p->data;
		free(p);
		return 1;
	}
}

//ȡջ��Ԫ��
int StackTop(Stack *s,DataType *d)
{
	if(s->next==NULL){
		printf("��ջ�ѿ�!\n");
		return 0;
	}
	else{
		*d=s->next->data;
		return 1;
	}
}

//�ͷ�������ڴ�ռ�
void Destroy(Stack *s)
{
	Stack *p,*p1;
	p=s;
	while(p!=NULL){
		p1=p;
		p=p->next;
		free(p1);
	}
}
#endif
#include "stack.h"

int main()
{
	Stack *myStack;
	int i,x;

	//��ʼ��ջ
	StackInitial(&myStack);

	//��1-10��Ԫ������ջ
	for(i=1;i<=10;i++){
		StackPush(myStack,i);
	}

	//��ȡջ��Ԫ��
	StackTop(myStack,&x);
	printf("��ǰջ������Ԫ��Ϊ:%d\n",x);

	//��ջ�ڵ�Ԫ���Ƴ�ջ
	printf("���γ�ջ������Ԫ����������:\n");
	while(StackNotEmpty(myStack)){
		StackPop(myStack,&x);
		printf("%d   ",x);
	}

	//���������ͷ��ڴ�
	Destroy(myStack);

	getchar();
	getchar();
	return 0;
}
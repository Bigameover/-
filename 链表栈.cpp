#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int value;
	struct Node *last;
}Node;
typedef struct Stack{
	Node *top;
	int  size,occupy; 
}Stack;
Stack* Initialize_stack(Stack *temp);
void Printf_stack(Stack *temp);
int  Pop(Stack *temp);
void Push(Stack *temp);
void Clear_stack(Stack *temp);
void Min_max(int *min,int *max);
void Destroy(Stack *temp);
int main(){
	Stack *first_stack;
	int number;
	first_stack = Initialize_stack(first_stack);
	Printf_stack(first_stack);
	number = Pop(first_stack);
	printf("��ջ��ֵΪ��%d��\n",number);
	Push(first_stack);
	Printf_stack(first_stack);
	Clear_stack(first_stack);
	Printf_stack(first_stack);
	Destroy(first_stack);
return 0;} 
Stack* Initialize_stack(Stack *temp){//��ͷ�ڵ������ջ 
	int x,min,max,cnt; 
	Node *substitutions;
	substitutions = NULL;
	temp = (Stack*)malloc(sizeof(Stack));
	printf("������ջ�Ĵ�С:\n");
	scanf("%d",&x);
	temp->size = x;
	printf("������ȡֵ��Χ:\n");
	Min_max(&min,&max);
	scanf("%d %d",&min,&max);
	x = (min+max)/2;
	cnt = -1;
	printf("�������ʼ��ջ�ڵ�ֵ:\n"); 
	while(min<=x&&x<=max){
		Node *surrenal;
		scanf("%d",&x);
		surrenal = (Node*)malloc(sizeof(Node));
		surrenal->last  = substitutions;
		surrenal->value = x;
		substitutions = surrenal;
		cnt++;
		if(cnt==temp->size){
			x = max+10;
		}
	} 
	temp->top = substitutions->last;
	temp->occupy = cnt;
	free(substitutions);
return temp;}
void Printf_stack(Stack *temp){
	Node *surrenal;
	surrenal = temp->top;
	while(surrenal){
		printf("%d\t",surrenal->value);
		surrenal = surrenal->last;
	}
	printf("\n");
}
int Pop(Stack *temp){
	int number;
	if(temp->occupy = 0){
		printf("ջ�����޷���ջ��\n");
	}
	else{
		temp->occupy-=1;
		Node *surrenal;
		surrenal = temp->top;
		number = surrenal->value;
		temp->top = temp->top->last;
		free(surrenal);
	}
return number;}
void Push(Stack *temp){
	if(temp->occupy==temp->size){
		printf("ջ�����޷���ջ��\n");
	}
	else{
		int number;
		printf("��������ջ��ֵ:\n");
		scanf("%d",&number);
		Node *more_node;
		more_node = (Node*)malloc(sizeof(Node));
		more_node->value = number;
		more_node->last = temp->top;
		temp->top = more_node;
		temp->occupy++;
	}
}
void Min_max(int *min,int *max){
	int surrenal;
	surrenal = *min;
	if(*min>=*max){
		*min = *max;
		*max = surrenal;
	}
}
void Clear_stack(Stack *temp){
	Node *surrenal,*substitutions;
	surrenal = temp->top;
	substitutions = surrenal;
	while(surrenal){
		substitutions = surrenal->last;
		free(surrenal);
		surrenal = substitutions;
	}
	temp->top = NULL;
	temp->occupy = 0;
	printf("occupy:%d\n stack_size:%d\ntemp->top:%p\n",temp->occupy,temp->size,temp->top);
}
void Destroy(Stack *temp){
	 temp->size = 0;
	 free(temp);
	 printf("ջ�ѱ����١�\n");
	 printf("%d\n",sizeof(temp)); 
}

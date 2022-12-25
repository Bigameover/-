#include<stdio.h>
#include<stdlib.h>
//有头节点 
typedef struct Node{
	struct Node *prior;
	int value;
	struct Node *next;
}Node;
void  Min_max(int *min,int *max);
Node* Create_double_list(Node *head,int min,int max);//有头节点 
void  Printf_double_list(Node *head);
int main(){
	Node *head;
	int min,max;
	printf("请输入取值范围：\n");
	scanf("%d %d",&min,&max);
	Min_max(&min,&max);
	//head=initNode(head,min,max);
	head = Create_double_list(head,min,max);
	Printf_double_list(head);
	for(min=0;min<4;min++){
		printf("\nwhile 可以多次判断,然而if只能进行一次判断。\n");
	}
return 0;}
void Min_max(int *min,int *max){
	int surrenal = *min;
	if(*min>=*max){
		*min =*max;
		*max = surrenal;
	}
}
Node* Create_double_list(Node *head,int min,int max){
	int i;
	Node *list;
	head = (Node*)malloc(sizeof(Node));
	head->prior = NULL;
	head->next = NULL;
	list = head; 
	scanf("%d",&i);
	head->value = i;
	while(min<=i&&i<=max){
		Node *body;
        scanf("%d",&i);
		body = (Node*)malloc(sizeof(Node));
		body->prior = NULL;
		body->next  = NULL;
		body->value = i;
		list->next = body;
		body->prior = list;
		list = list->next;
	} 
return head;}
void Printf_double_list(Node *head){
	Node *substitutions;
	substitutions = head;
	while(substitutions){
		printf("%d\t",substitutions->value);
		substitutions = substitutions->next;
	}
}

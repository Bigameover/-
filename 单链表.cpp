#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int number;
	struct Node *next;
}Node;
void Printf_tail_linklist(Node *head);//头叉法 从末尾开始 建立节点 (有头节点)
void Printf_head_linklist(Node *tail);//尾叉法 从头开始建立节点 （没有头节点） 
void Min_max(int *min,int *max);
int main(){
	Node *head,*surrenal,*tail,*substitutions;
	int x,y,min,max;
	surrenal = (Node*)malloc(sizeof(Node));
	substitutions = NULL;
	head = surrenal;
	surrenal->next = NULL;
	printf("请输入最低分和最高分:\n");
	scanf("%d %d",&min,&max);
	Min_max(&min,&max);
	scanf("%d",&y);
	surrenal->number = y;
	while(min<=y&&y<=max){
		Node *p,*q;
		p = (Node*)malloc(sizeof(Node));
		q = (Node*)malloc(sizeof(Node));
		q->next = substitutions;
		q->number = y;
		substitutions = q;
		p->next = NULL;
		p->number = y;
		surrenal->next = p;
		surrenal = surrenal->next; 
		scanf("%d",&y);
	}
	tail = substitutions;
	printf("尾插法输出：\n");
	Printf_tail_linklist(head);
	printf("\n");
	printf("头插法输出：\n");
	Printf_head_linklist(tail);
return 0;}	//substitutions = (Node*)malloc(sizeof(Node));
void Min_max(int *min,int *max){
	int surrenal = *min;
	if(*min>=*max){
		*min = *max;
		*max = surrenal;
	}
}
void Printf_tail_linklist(Node *head){
	Node *surrenal;
	Node *substitutions;
	int cnt = 0;
	surrenal = head;
	while(surrenal->next!=NULL){
		substitutions = surrenal->next;
		printf("%d\t",substitutions->number);
		cnt++;
		if(cnt%6==0) printf("\n");
		surrenal = surrenal->next;
	}
}
void Printf_head_linklist(Node *tail){
	Node *surrenal;
	Node *substitutions;
	int cnt = 1;
	surrenal = tail;
	printf("%d\t",surrenal->number);
	while(surrenal->next!=NULL){
		substitutions = surrenal->next;
		printf("%d\t",substitutions->number);
		cnt++;
		if(cnt%6==0) printf("\n");
		surrenal = surrenal->next;
	}
}


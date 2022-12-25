#include<stdio.h>
#include<stdlib.h>
typedef struct Order_queue{
	int size,occupy;
	int *front,*rear;
}Order_queue;
typedef struct Node{
	int value;
	struct Node *next;
}Node;
typedef struct Double_node{
	Node *last,*next;
	int data;
}Double_node;
typedef struct Double_queue{
	Double_queue *empty_double_node;
}Double_queue;
typedef struct Circulate_queue{//��β�ڵ���ȷ������Դ�ڵ����� 
	Node *empty_node,*tail_node;
	int size,ocuupy;
}Circulate_queue;
void Min_max(int *min,int *max);
Circulate_queue* Initialize_circulate_queue(Circulate_queue *temp);
void Printf_circulate_queue(Circulate_queue *temp);
void Input_circulate_queue(Circulate_queue *temp);
void Output_circulate_queue(Circulate_queue *temp);
Order_queue* Initialize_order_queue(Order_queue *temp);
void Min_max(int *min,int *max);
void Printf_order_queue(Order_queue *temp);
void Input_order_queue(Order_queue *temp);
void Output_order_queue(Order_queue *temp); 
int main(){
//˳����е�ʵ�֡�	
	Order_queue *first_queue;
	first_queue = Initialize_order_queue(first_queue);
    Input_order_queue(first_queue); 
    Output_order_queue(first_queue);
    Printf_order_queue(first_queue);
//���������ʵ�֡�����Ϊѭ��������������⣬����Circulate_queue��������У� 
      Circulate_queue *second_queue;    
      second_queue = Initialize_circulate_queue(second_queue);
      Input_circulate_queue(second_queue);
      Output_circulate_queue(second_queue);
      Printf_circulate_queue(second_queue);
return 0;} 
Circulate_queue* Initialize_circulate_queue(Circulate_queue *temp){//����ͷ�ڵ��ѭ������ (�Ľ����Խ��սڵ�ĳ�˫)
	Node *head,*mark;
	temp = (Circulate_queue*)malloc(sizeof(Circulate_queue));
	head = (Node*)malloc(sizeof(Node));
	head->next  = NULL;
	temp->empty_node  = head;
	mark = head;
	int x,min,max,data,cnt;
	printf("������������еĴ�С��\n");
	scanf("%d",&x);
	temp->size = x;
	printf("������������е�ȡֵ��Χ:\n");
	scanf("%d %d",&min,&max);
	head->value = min-10;
	printf("�������ʼ��������е�ֵ��\n");
	scanf("%d",&data);
	cnt = 0;
	while(min<=data&&data<=max){
		Node *new_node;
		new_node = (Node*)malloc(sizeof(Node));
		new_node->next = NULL;
		new_node->value = data;
		mark->next = new_node;
		mark = mark->next;
		scanf("%d",&data);
		cnt++;
		if(cnt==x){
			data = max+10;
		}
	}
	temp->ocuupy = cnt;
	temp->tail_node = mark;
	mark->next   = head;
return temp;}
void Printf_circulate_queue(Circulate_queue *temp){
	Node *surrenal;
	int  judgment,cnt;
	cnt = 0;
	surrenal = temp->empty_node;
	judgment = surrenal->value;
	surrenal = surrenal->next;
	while(surrenal->value!=judgment){
		printf("%d\t",surrenal->value);
		surrenal = surrenal->next;
		cnt++;
		if(cnt%10==0) printf("\n");
	}
}
void Output_circulate_queue(Circulate_queue *temp){
	if(temp->ocuupy==0){
		printf("����������������޷������\n");
	} 
	else{
		Node* surrenal;
	    surrenal = temp->empty_node->next;
	    temp->empty_node->next = surrenal->next;
	    printf("������������ֵ��:%d\n",surrenal->value);
	    free(surrenal);
	    temp->ocuupy--;
	}
}
void Input_circulate_queue(Circulate_queue *temp){
	if(temp->size==temp->ocuupy){
		printf("��������������޷��Զ��н������롣\n");
	}
	else{
		Node *new_node;
		new_node = (Node*)malloc(sizeof(Node));
		new_node->next  = temp->empty_node;
		temp->tail_node->next = new_node; 
		temp->tail_node  = new_node;
		int x;
		printf("�������������������е�ֵ��\n");
		scanf("%d",&x);
		new_node->value = x;
		temp->ocuupy++;
	}
} 
Order_queue* Initialize_order_queue(Order_queue *temp){
	temp = (Order_queue*)malloc(sizeof(Order_queue));
	int x,min,max,cnt;
	int *surrenal; 
	cnt = 0;
	printf("����˳������еĴ�С��\n");
	scanf("%d",&x);
	temp->size  = x;
	temp->front = (int*)malloc(sizeof(int)*x);
	surrenal = temp->front;
	printf("������˳�����ֵ��ȡֵ��Χ:\n");
	scanf("%d %d",&min,&max);
	Min_max(&min,&max);
	printf("������˳���ʼ���Ķ���\n");
	scanf("%d",&x);
	while(min<=x&&x<=max){
		cnt++;
		*surrenal = x;
		surrenal++;
		scanf("%d",&x);
		if(cnt==temp->size){
			x = max+10;
		}	
	}
	temp->rear = surrenal-1;
	temp->occupy = cnt;
return temp;}
void Min_max(int *min,int *max){
	int surrenal;
	surrenal = *min;
	if(*min>=*max){
		*min = *max;
		*max = surrenal;
	}
}
void Printf_order_queue(Order_queue *temp){
	int x;
	int *surrenal;
	surrenal = temp->front;
	for(x=0;x<temp->occupy;x++){
		printf("%d\t",*surrenal);
		surrenal++;
	}
	printf("\n");
}
void Input_order_queue(Order_queue *temp){
	if(temp->occupy==temp->size){
		printf("˳������������޷�������С�\n");
	}
	else{
		int value;
		printf("���������˳����е�ֵ:\n");
		scanf("%d",&value);
		temp->rear++;
		*temp->rear = value;
		temp->occupy++; 
	}
}
void Output_order_queue(Order_queue *temp){
	int x,value,*substitutions,*surrenal;
	value = *temp->front;
	printf("˳����������ֵ�ǣ�%d\n",value);
	for(x=1;x<temp->occupy;x++){
		substitutions = temp->front+x-1;
		surrenal = temp->front+x;
		*substitutions = *surrenal;
	}
	temp->occupy--;
	temp->rear--;
}

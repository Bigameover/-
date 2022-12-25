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
typedef struct Circulate_queue{//用尾节点来确定受首源节点链表 
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
//顺序队列的实现。	
	Order_queue *first_queue;
	first_queue = Initialize_order_queue(first_queue);
    Input_order_queue(first_queue); 
    Output_order_queue(first_queue);
    Printf_order_queue(first_queue);
//单向链表的实现。（因为循环链表出现了意外，所提Circulate_queue是链表队列） 
      Circulate_queue *second_queue;    
      second_queue = Initialize_circulate_queue(second_queue);
      Input_circulate_queue(second_queue);
      Output_circulate_queue(second_queue);
      Printf_circulate_queue(second_queue);
return 0;} 
Circulate_queue* Initialize_circulate_queue(Circulate_queue *temp){//创建头节点的循环链表 (改进可以将空节点改成双)
	Node *head,*mark;
	temp = (Circulate_queue*)malloc(sizeof(Circulate_queue));
	head = (Node*)malloc(sizeof(Node));
	head->next  = NULL;
	temp->empty_node  = head;
	mark = head;
	int x,min,max,data,cnt;
	printf("请输入链表队列的大小：\n");
	scanf("%d",&x);
	temp->size = x;
	printf("请输入链表队列的取值范围:\n");
	scanf("%d %d",&min,&max);
	head->value = min-10;
	printf("请输入初始化链表队列的值：\n");
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
		printf("链表队列已无数据无法输出。\n");
	} 
	else{
		Node* surrenal;
	    surrenal = temp->empty_node->next;
	    temp->empty_node->next = surrenal->next;
	    printf("链表队列输出的值是:%d\n",surrenal->value);
	    free(surrenal);
	    temp->ocuupy--;
	}
}
void Input_circulate_queue(Circulate_queue *temp){
	if(temp->size==temp->ocuupy){
		printf("链表队列已满已无法对队列进行输入。\n");
	}
	else{
		Node *new_node;
		new_node = (Node*)malloc(sizeof(Node));
		new_node->next  = temp->empty_node;
		temp->tail_node->next = new_node; 
		temp->tail_node  = new_node;
		int x;
		printf("请输入你想进入链表队列的值。\n");
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
	printf("请输顺序入队列的大小：\n");
	scanf("%d",&x);
	temp->size  = x;
	temp->front = (int*)malloc(sizeof(int)*x);
	surrenal = temp->front;
	printf("请输入顺序队列值的取值范围:\n");
	scanf("%d %d",&min,&max);
	Min_max(&min,&max);
	printf("请输入顺序初始化的队列\n");
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
		printf("顺序队列已满已无法进入队列。\n");
	}
	else{
		int value;
		printf("请输入输进顺序队列的值:\n");
		scanf("%d",&value);
		temp->rear++;
		*temp->rear = value;
		temp->occupy++; 
	}
}
void Output_order_queue(Order_queue *temp){
	int x,value,*substitutions,*surrenal;
	value = *temp->front;
	printf("顺序队列输出的值是：%d\n",value);
	for(x=1;x<temp->occupy;x++){
		substitutions = temp->front+x-1;
		surrenal = temp->front+x;
		*substitutions = *surrenal;
	}
	temp->occupy--;
	temp->rear--;
}

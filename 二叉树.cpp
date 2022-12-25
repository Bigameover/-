#include<stdio.h>
#include<stdlib.h>
typedef struct Double_node{
	struct Double_node *lchild,*rchild;
	char data;
}Double_node; 
typedef struct Point_node{
	Double_node *value;
	struct Point_node *next;
}Point_node;
typedef struct Queue{
	Point_node *front,*rear;
	int length;
}Queue;
Queue* Create_queue(Queue*interim,Double_node*temp);
Queue* Output(Queue* interim);
Queue* Input(Queue* interim,Double_node* temp);
Double_node* Create_tree(Double_node*temp); 
void Precedence_tree(Double_node*temp);
void Mid_order_traversal(Double_node*temp);
void Subsequent_traversal(Double_node*temp);
void Hierarchical_traversal(Queue*interim,Double_node*temp);//我构造的存储二叉树的节点链表队列，从而实现层次遍历。 
int main(){
	Double_node *first_tree;
	printf("创建：\n"); 
	first_tree = Create_tree(first_tree);
	printf("先序遍历：\n");
	Precedence_tree(first_tree);
	printf("\n"); 
	printf("中序遍历：\n");
	Mid_order_traversal(first_tree);
	printf("\n");
	printf("后续遍历：\n");
	Subsequent_traversal(first_tree);
	printf("\n");
	printf("层次遍历：\n");
	Queue* first_queue;
	Hierarchical_traversal(first_queue,first_tree);
return 0;}
Queue* Create_queue(Queue*interim,Double_node*temp){
	Point_node *surrenal;
	surrenal = (Point_node*)malloc(sizeof(Point_node));
	surrenal->value = temp;
	surrenal->next = NULL;
	interim = (Queue*)malloc(sizeof(Queue));
	interim->front = surrenal;
	interim->rear = surrenal;
	interim->length = 1;
return interim;} 
Queue* Output(Queue* interim){
	printf("%c ",interim->front->value->data);
	interim->front = interim->front->next;
	interim->length--;
return interim;} 
Queue* Input(Queue* interim,Double_node* temp){
	Point_node *surrenal;
	surrenal = (Point_node*)malloc(sizeof(Point_node));
	surrenal->value = temp;
	surrenal->next = NULL;
	interim->rear->next = surrenal;
	interim->rear = interim->rear->next;
	interim->length++; 
return interim;}
Double_node* Create_tree(Double_node*temp){
	char value;
	scanf("%c ",&value);
	if(value!='0'){
		temp = (Double_node*)malloc(sizeof(Double_node));
		temp->lchild = NULL;
		temp->rchild = NULL;
		temp->data = value;
		temp->lchild = Create_tree(temp->lchild);
		temp->rchild = Create_tree(temp->rchild); 
	}
	else{
		temp = NULL;
	}
return temp;}
void Precedence_tree(Double_node*temp){
	if(temp!=NULL){
		printf("%c ",temp->data);
		Precedence_tree(temp->lchild);
		Precedence_tree(temp->rchild);
	}
}
void Hierarchical_traversal(Queue*interim,Double_node*temp){
	int x,sum,cnt;
	interim = Create_queue(interim,temp);
	cnt = 1;
	while(interim->length!=0) {
		sum = interim->length;
		printf("第%d层：",cnt);
		for(x=0;x<sum;x++){
			if(interim->front->value->lchild!=NULL) interim = Input(interim,interim->front->value->lchild);
			if(interim->front->value->rchild!=NULL) interim = Input(interim,interim->front->value->rchild);
			interim = Output(interim);
		}
		printf("\n");
		cnt++;
	}
}
void Mid_order_traversal(Double_node*temp){
	if(temp!=NULL){
		Mid_order_traversal(temp->lchild);
		printf("%c ",temp->data);
		Mid_order_traversal(temp->rchild);
	}
} 
void Subsequent_traversal(Double_node*temp){
	if(temp!=NULL){
		Subsequent_traversal(temp->lchild);
		Subsequent_traversal(temp->rchild);
		printf("%c ",temp->data);
	}
}


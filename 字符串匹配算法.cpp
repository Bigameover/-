#include<stdio.h>
#include<stdlib.h>
typedef struct Sequentail_string{
	int  length;
	char *string;
}Sequentail_string;
Sequentail_string* Initailize_string(Sequentail_string*temp);
int Brute_force(Sequentail_string*first,Sequentail_string*second);
int* Create_next(Sequentail_string *temp);
int main(){
	printf("�ڵײ�ԭ���з����˳���ַ�������ǰ���ָ��ָ����ַ���\n\n");
	Sequentail_string *first,*second,*third;
	first  = Initailize_string(first);
	second = Initailize_string(second);
	third  = Initailize_string(third);
	printf("��ʼ�����:\n%s\n",first->string);
	printf("%s\n",second->string);
	printf("%s\n",third->string);
	printf("���⣺Ϊʲô�����ַ������׵�ַ����ͬ�ģ�������ͬһ���ַ������֡�\n"); 
	printf("һ�𣺲²����ǽ�һ����ַ�ֳ����������ݣ��м���ָ�룬��Ϊ�Ҵ����ĵ������ṹ����׵�ַ��������ǰ������ͬ��\n");
	printf("���𣺵�ַû����ΪBrute_force�ı���ı����Բ������ַ������Ƶ�����ĵ�ַ��ȥ��\n");
	printf("%c\n%p\n",*first->string,second->string);
	printf("%c\n%p\n",*second->string,second->string);
	printf("%c\n%p\n",*third->string,third->string);
	int locations,x,y,cnt,*next,*substitutions;
	char *surrenal;
	locations = Brute_force(first,third);
	cnt = 0;
	printf("����first��ʼ����\n");
	surrenal = first->string;
	for(x=0;x<first->length;x++){
		printf("%c\t",*surrenal);
		surrenal++; 
		cnt++;
		if(cnt%10==0) printf("\n");
	}
	printf("\n");
	cnt = 0;
	printf("����second��ʼ����\n");
	surrenal = second->string;
	for(y=0;y<second->length;y++){
		printf("%c\t",*surrenal);
		surrenal++;
		cnt++;
		if(cnt%10==0) printf("\n");
	} 
	printf("\n");
	next = Create_next(second);
	substitutions = next;
	for(y=0;y<second->length;y++){
		printf("%d ",*substitutions);
		substitutions++;
	}
	printf("\n");
	
return 0;}
Sequentail_string* Initailize_string(Sequentail_string*temp){
	temp = (Sequentail_string*)malloc(sizeof(Sequentail_string));
	int x,h;
	char *surrenal;
	printf("�������ַ����Ĵ�С��\n");
	scanf("%d",&x);
	temp->string = (char*)malloc(sizeof(char)*(x+1));
	surrenal = temp->string;
	temp->length = x;
	printf("���ʼ���ַ�����\n");
	for(h=0;h<x+1;h++){
		scanf("%c",temp->string);
		temp->string++;
	}
	temp->string = surrenal+1;
return temp;}
int Brute_force(Sequentail_string*first,Sequentail_string*second){
	int cnt,locations;
	cnt = 0;
	locations = 1;
	while(cnt!=second->length){
		if(*first->string==*second->string){
			cnt++;
			first->string++;
			second->string++;
		}
		else{
			locations++;
			first->string  = first->string-cnt+1;
			second->string = second->string-cnt;
			cnt = 0;
		}
		if(locations==first->length-second->length+2) break;
	}
	if(cnt==second->length){
		printf("Locations is %d��\n",locations);
	}
	else{
		printf("���Ӵ�ƥ�䡣\n");
	}
return locations;} 
int* Create_next(Sequentail_string*temp){
	printf("temp->length:%d\n",temp->length);
	int *next,*surrenal,cnt,value;
	next = (int*)malloc(sizeof(int)*temp->length);
	surrenal = next;
	*surrenal = 1;
	surrenal++;
	*surrenal = 1;
	value = 1;
	cnt = 2;
	char *former,*after;
	former = temp->string;
	after  = temp->string+1;
	printf("����former,after�Ƿ���ȷ��\n");
	printf("%c %c\n",*former,*after);
	printf("����nexts���飺\n"); 
	while(cnt<temp->length){
		while(*former!=*after){
			former = temp->string+value-1;
			value  = *(next+value-1);
			if(*former!=*after&&former==temp->string){
				printf(" NO:%c %c ",*former,*after);
				value=1;
				surrenal++;
				*surrenal =value;
				after++;
				cnt++;
				printf("next��%d cnt:%d value:%d\n",*surrenal,cnt,value);
				break;
			}
		} 
		if(*former==*after){
			printf("Yes:%c %c ",*former,*after);
			value++;
			surrenal++;
			*surrenal = value;
			after++;
			former++;
			cnt++;
			printf("next��%d cnt:%d value:%d\n",*surrenal,cnt,value);
		}
	}
	*next = 1;
return next;} 



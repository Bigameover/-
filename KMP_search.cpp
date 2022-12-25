#include<stdio.h>
#include<stdlib.h>
typedef struct Sequentail_string{
	int  length;
	char *string;
}Sequentail_string;
Sequentail_string* Initailize_string(Sequentail_string *temp);
int* Create_next(Sequentail_string *temp);
int KMP_search(Sequentail_string*first,Sequentail_string*second); 
int main(){
	Sequentail_string *first,*second;
	char *surrenal;
	int *next,useless;
	first  = Initailize_string(first);
	second = Initailize_string(second);
	int x,y,cnt;
	cnt = 0;
	printf("检验first初始化：\n");
	surrenal = first->string;
	for(x=0;x<first->length;x++){
		printf("%c\t",*surrenal);
		surrenal++; 
		cnt++;
		if(cnt%10==0) printf("\n");
	}
	printf("\n");
	cnt = 0;
	printf("检验second初始化：\n");
	surrenal = second->string;
	for(y=0;y<second->length;y++){
		printf("%c\t",*surrenal);
		surrenal++;
		cnt++;
		if(cnt%10==0) printf("\n");
	} 
	printf("\n");
	next = Create_next(second);
	KMP_search(first,second);
return 0;}
Sequentail_string* Initailize_string(Sequentail_string *temp){
	temp = (Sequentail_string*)malloc(sizeof(Sequentail_string));
	int x,y;
	char *surrenal;
	printf("请输入字符串的大小：");
	scanf("%d",&x);
	temp->length = x;
	temp->string = (char*)malloc(sizeof(char)*(x+1));
	surrenal = temp->string;
	printf("请初始化字符串：\n");
	for(y=0;y<x+1;y++){
		scanf("%c",surrenal);
		surrenal++;
	}
	temp->string++;
return temp;} 
int* Create_next(Sequentail_string*temp){
	int y;
	printf("temp->length:%d\n",temp->length);
	int *next,*surrenal,cnt,value,*substitutions;
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
	printf("检验former,after是否正确：\n");
	printf("%c %c\n",*former,*after);
	printf("检验next数组：\n"); 
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
				printf("next：%d cnt:%d value:%d\n",*surrenal,cnt,value);
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
			printf("next：%d cnt:%d value:%d\n",*surrenal,cnt,value);
		}
	}
	*next = 1;
	substitutions = next;
	for(y=0;y<temp->length;y++){
		printf("%d ",*substitutions);
		substitutions++;
	}
	printf("\n");
return next;} 
int KMP_search(Sequentail_string*first,Sequentail_string*second){
	int *pat_next,cnt,locations,*useless,sum;
	char*txt,*pat_string;
	txt = first->string;
	sum=0;
	pat_string = second->string;
	printf("second->string:%p\n",second->string);
	pat_next = Create_next(second);
	useless = pat_next;
	printf("检验：txt:%c pat_string:%c pat_next:%d\n",*txt,*pat_string,*pat_next);
	locations = 1;
	cnt = 0;
	while(locations<=first->length){
		while(*txt!=*pat_string){
			pat_string = second->string+*pat_next-1;
			pat_next = useless+*pat_next-1;
			cnt = *pat_next;
			sum++;
			printf("pat_next:%d txt:%c pat_string:%p sum:%d\n",*pat_next,*txt,pat_string,sum);
			if(*txt!=*pat_string&&pat_string==second->string){
				txt++;
				locations++;
				cnt = 0;
				pat_next = useless;
				printf(" No locations:%d pat_next:%d cnt:%d\n",locations,*pat_next,cnt);
				break;
			}
		}
		if(*txt==*pat_string){
			locations++;
			cnt++;
			txt++;
			pat_string++;
			pat_next++;
			printf("yes locations:%d pat_next:%d cnt:%d\n",locations,*pat_next,cnt);
		}
		if(cnt==second->length){
			printf("Location is %d。\n",locations-second->length);
			return locations;
		}
	}
	if(cnt!=second->length){
		printf("无法匹配。\n");
	}
return locations;} 

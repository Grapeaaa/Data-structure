#include<stdio.h>
#define MaxTree 20
#define Null -1
struct TreeNode{
	int Left;
	int Right;
	int Element;
}T1[MaxTree];
int N,check[MaxTree],Queue[MaxTree],Leaves[MaxTree];
int first = -1,last = -1;

void Push(int a);
int Pop();
void Print(int Root);
int BuildTree(struct TreeNode T[]);

int main()
{
	int Root;
	Root = BuildTree(T1);
	Print(Root);
	return 0;	
}

int BuildTree(struct TreeNode T[])
{
	int i,root=Null;
	char cl,cr;
	scanf("%d",&N);
	if(N){
		for(i=0;i<N;i++) check[i] = 0;
		for(i = 0;i<N;i++){
			T[i].Element = i;
			scanf("\n%c %c",&cl,&cr);
			if(cl!='-') {
			   T[i].Left = cl-'0';
			   check[T[i].Left] = 1;
			}
			else 
			   T[i].Left = Null;
			if(cr!='-') {
			   T[i].Right = cr-'0';	
			   check[T[i].Right] = 1;
			}
			else 
			   T[i].Right = Null;	
		}
	for(i = 0;i<N;i++)
		if(!check[i]) break;	   	
	root = i;		
	}
	
return 	root;	
}
void Push(int a){
	Queue[++last]=a;
}

int Pop()
{ 
	return Queue[++first] ;
}

void Print(int  Root)
{   
    int i=0,k=0;
    Push(Root);
    for(i=0;i<N;i++)
    {
    	int tn=Pop();
    	printf("%d\n",tn);
    	if((T1[tn].Left==-1)&&(T1[tn].Right==-1)) Leaves[++k]=T1[tn].Element;
    	if(T1[tn].Left!=-1)  Push(T1[tn].Left);
    	if(T1[tn].Right!=-1) Push(T1[tn].Right);
	}
	int j=0;
	for(j=1;j<k;j++)
	  printf("%d ",Leaves[j]);
	printf("%d",Leaves[k]);
}




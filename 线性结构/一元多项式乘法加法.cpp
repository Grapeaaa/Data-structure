#include<stdio.h>
#include<stdlib.h>

typedef struct LNode *List;
struct LNode{
	int xishu;
	int zishu;
	List Next;
};
List Read();
void Attach(int a,int b,List *L);
void Print(List L);
List Ride(List p1,List p2 );
List Sum(List p1,List p2);
int main(){ 
    List P1,P2,ps,pp;
	P1=Read();
	P2=Read();
	pp=Ride(P1,P2);
	Print(pp);
	ps=Sum(P1,P2);
	Print(ps)	;
	return 0;
}
List Read(){
	int a,b,n;
	List L,tmp,t;
	L=(List)malloc(sizeof(struct LNode));
	L->Next=NULL;
	tmp=L;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&a,&b);
		Attach(a,b,&tmp);
	}
t=L;
L=L->Next;
free(t);
return L;
}
void Attach(int a,int b,List *L){
	List  sult;
	sult=(List)malloc(sizeof(struct LNode));
	sult->Next=NULL;
	sult->xishu=a;
	sult->zishu=b;
	(*L)->Next=sult;
	*L=sult;
}
void Print(List L)
{
	if(L==NULL) printf("0 0");
	while(L)
	{
	    printf("%d %d",L->xishu,L->zishu);
		if(L->Next!=NULL) printf(" ");
		L=L->Next;	
	}
	printf("\n");
}
List Sum(List P1,List P2)
{
	if(!P1&&!P2){
		if(!P1) return P2;
		if(!P2) return P1;	
	}
	List P,Rear,tmp1,tmp2,tmp;
	tmp1=P1;
	tmp2=P2;
	P=(List)malloc(sizeof(struct LNode));
	P->Next=NULL;
	Rear=P;
	while(tmp1&&tmp2){
		if(tmp1->zishu==tmp2->zishu){
			if(tmp1->xishu+tmp2->xishu){
			    Attach(tmp1->xishu+tmp2->xishu,tmp1->zishu,&Rear);	
			}
		tmp1=tmp1->Next;
		tmp2=tmp2->Next;	
		}
		else if(tmp1->zishu>tmp2->zishu){
				Attach(tmp1->xishu,tmp1->zishu,&Rear);
			tmp1=tmp1->Next;
		}
		else {
		    	Attach(tmp2->xishu,tmp2->zishu,&Rear);
		    tmp2=tmp2->Next;
		}	    
	}
	while(tmp1){
		Attach(tmp1->xishu,tmp1->zishu,&Rear);
		tmp1=tmp1->Next;
	}
	while(tmp2){
		Attach(tmp2->xishu,tmp2->zishu,&Rear);
		tmp2=tmp2->Next;
	}    
    tmp=P;
    P=P->Next;
    free(tmp);
    return P;
 } 

List Ride(List P1,List P2 ){
	if(!P1 || !P2) return NULL;
	List P,Rear,tmp1,tmp2,tmp,temp;
	int c,e;
	P=(List)malloc(sizeof(struct LNode));
	P->Next=NULL;
	Rear=P;
	tmp1=P1;
	tmp2=P2;
	while(tmp2){
		c=tmp1->xishu*tmp2->xishu;
		e=tmp1->zishu + tmp2->zishu;
		if(c != 0){
			Attach(c,e,&Rear);
			tmp2=tmp2->Next;
			}	
	
		}
	tmp1=tmp1->Next;
	while(tmp1){
		Rear=P,tmp2=P2;
		while(tmp2){
			c=tmp1->xishu*tmp2->xishu;
			e=tmp1->zishu+tmp2->zishu;
			if(c != 0){
				while(Rear->Next && Rear->Next->zishu>e)
					Rear=Rear->Next;
				if(Rear->Next && Rear->Next->zishu == e){
					if(Rear->Next->xishu + c) 
						Rear->Next->xishu += c;
					else {
						tmp=Rear->Next;
						Rear->Next=tmp->Next;
						free(tmp);	
				       }
					   }
				else{
					tmp=(List)malloc(sizeof(struct LNode));
					tmp->zishu=e;
					tmp->xishu=c;
					tmp->Next=Rear->Next;
					Rear->Next=tmp;
					Rear=Rear->Next;		
				    }
				}
				tmp2=tmp2->Next;
			}
		tmp1=tmp1->Next;	
		}
    Rear->Next=NULL;	
	temp=P;
	P=P->Next;
	free(temp);
	return P;
}	


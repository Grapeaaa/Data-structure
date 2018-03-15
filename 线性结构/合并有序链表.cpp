List Merge( List L1, List L2)
{
	List tmp,head;//建立头节点 
	tmp = (List) malloc(sizeof(struct Node));
	List p = L1->Next;
    List q = L2->Next;
	tmp->Next = NULL;
	head = tmp;
	while (p!=NULL && q!=NULL){
		if (p->Data < q->Data){
			tmp->Next = p;
			p = p->Next;
			tmp = tmp->Next;
		}  
		else {
			tmp->Next = q;
			q = q->Next;
			tmp = tmp->Next;	
		}	
	}
	tmp->Next = NULL;
	if(p)  tmp->Next = p;
	if(q)  tmp->Next = q;
	L1->Next=NULL;//释放内存 
    L2->Next=NULL;
	return head;
 } 

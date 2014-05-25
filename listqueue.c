#include<stdio.h>
struct node{
   int info;
   struct node *next;
};
void insert_node(struct node **lp,int x){
   struct node *p,*r,*s;
   p=(struct node *)malloc(sizeof(struct node *));
   p->info=x;
   p->next=NULL;
   if(*lp==NULL){
       *lp=p;
   }
   else{
       r=s=*lp;        //node to be inserted at the end of list
       while(r!=NULL){
           s=r;
           r=r->next;
       }
       s->next=p;
   }
}
int delete_node(struct node **lp){
   struct node *s;
   s=*lp;
   int x;
   x=s->info;
   *lp=s->next;
   return x;
}
void show_node(struct node **lp){
    struct node *r,*s;
    r=*lp;
    while(r!=NULL){
        printf("%d\t",r->info);
        r=r->next;
    }
    printf("\n");
}
int main(){
   struct node *ls;
   ls=NULL;
   int choice,ele;
   while(1){
       printf("Enter 1 to insert into list\n2 to delete from list\n3 to show\n4 to exit\n");
       scanf("%d",&choice);
       switch(choice){
       case 1:
           printf("Enter a no. to insert\n");
           scanf("%d",&ele);
           insert_node(&ls,ele);
           break;
       case 2:
           if(ls!=NULL){
               ele=delete_node(&ls);
               printf("Deleted No. is %d\n",ele);
           }
           else
               printf("empty queue\n");
           break;
       case 3:
           show_node(&ls);
           break;
       case 4:
           exit(0);
       }
   }
   return 0;
}


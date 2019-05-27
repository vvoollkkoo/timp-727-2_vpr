#include <stdio.h> 
#include <stdlib.h> 

typedef struct node 
{ 
    int value; 
    struct node *next; 
    struct node *prev; 
} node; 

void init(node * a){ 
    a = (node *)malloc(sizeof(node)); 
} 

void printNode(node *a){ 
    while (a){ 
        printf("%d ", a->value); 
        a = a->next; 
    }  
    printf("\n"); 
}  
void print_invers(node *a){ 

    while (a->next){ 
         
        a = a->next; 
    }  
  
    while (a){ 
        printf("%d ", a->value); 
        a = a->prev; 
    }  
    printf("\n"); 
}  

void clear(node * a){ 
    node * b = a; 
    node * next = b->next;
    while (b->next != NULL){
        free(b); 
        b = b->next;

        *a = *b;
       
    }     
    free(a);
} 

int isEmpty(node *a){ 
    if (a == NULL){ 
        return 1;  
    } else { 
        return 0; 
    } 
} 
 
node * find (node * a, int value){ 
    node * b = a; 
    while (b){ 
      if (b->value == value){ 
          return b; 
      } 
      b = b->next; 
    } 
    return NULL; 
} 


int push_back(node **a, int value) { 
    node *b = (node*) malloc(sizeof(node)); 
    b->value = value; 

    if (*a == NULL){ 
        b->next = NULL; 
        b->prev = NULL;
    } else { 
        b->next = (*a);
        b->prev = NULL;
        (*a)->prev = b; 
    } 

    *a = b; 
    return 0;
} 
 
int push_front(node **a, int value) { 
    node * b = (node *) malloc(sizeof(node)); 
    b->value = value; 
    b->next = NULL; 

    if (*a == NULL){
      b->prev = NULL;
      *a = b;
    } else {
      node * c = *a; 
      while (c->next != NULL){ 
           c = c->next; 
      } 
      c->next = b;
      b->prev = c;
    }

    return 0;
} 

int insertAfter (node * n, int value){
    node * next = n->next;

    node * b = (node *) malloc(sizeof(node)); 
    b->value = value;
    b->prev = n;

    n->next = b;
    //next = b;

    if (next != NULL){
      b->next = next;
      next->prev = b;
    } else {
      b->next = NULL;
    }
    return 0;
}

int insertBefore (node * n, int value){
    node * prev = (n)->prev;

    node * c = n;


    node * b = (node *) malloc(sizeof(node)); 
    b->value = value;
    b->next = c;
    

    (n)->prev = b;

    if (prev != NULL){
      prev->next = b;
      b->prev = prev;
    } else {
      b->prev = NULL;
 
    }

    return 0;
}

int removeFirst (node * a, int value){

    node * b = a; 
    node * last = NULL;

    while (b){ 
      if (b->value == value){ 
          node * next = b->next;  
                   
          
          free(b);
          
          if (last != NULL){
            last->next = next;
            if (next != NULL){
              next->prev = last;
            } 
          } else {
            *a = *next;
          }
          

                  
          return 0; 
      } 
      last = b;
      b = b->next; 
    } 

    return 1;
}
  
int removeLast (node * a, int value){

    node * b = a; 
    node * last = NULL;

    node * toDelete = NULL;


    while (b){ 
      if (b->value == value){ 
        toDelete = b;
      } 
      last = b;
      b = b->next; 
    } 


    b = toDelete;
    
    node * next = b->next;  
    node * prev = b->prev;         
    
    free(b);
    if (next != NULL){
      next->prev = prev;
    }
  
    if (prev != NULL){
      prev->next = next;
    } else {
      *a = *next;
    }

    return 0;
}

int main() 
{ 

    int n;
    scanf("%d", &n);

    node* a = NULL; 
    init(a); 

    for (int i = 0; i < n; i++){
      int ni;
      scanf("%d", &ni);
      push_front(&a, ni);
    }

    printNode(a);

    int k;
    for (int i = 0; i < 3; i++){
      scanf("%d", &k);
      node * f = find(a, k);
      if (f == NULL){
        printf("0");
      } else {
        printf("1");
      }
    }

    printf("\n");

    int m;
    scanf("%d", &m);
    push_front(&a, m);
    print_invers(a);

    int t;
    scanf("%d", &t);
    push_back(&a, t);
    printNode(a);


    int j, x;
    scanf("%d %d", &j, &x);

    node * b = a;
    for (int i = 1; i < j; i++){
      b = b->next;
    }
    insertAfter(b, x);
    print_invers(a);

    int u, y;
    scanf("%d %d", &u, &y);

    node * c = a;
    for (int i = 1; i < u; i++){
      c = c->next;
    }
    insertBefore(c, y);
    printNode(a);



    
    int z;
    scanf("%d", &z);
    removeFirst(a, z);
    print_invers(a);


    int r;
    scanf("%d", &r);
    removeLast(a, r);
    printNode(a);

    return 0; 

} 

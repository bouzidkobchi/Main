// to do later :
    // delete item                                                                  (done)
    // merge two trees
    // find the smallest/greatest k number
    // is_bst function                                                              (done)
    // random insertion                                                             (done)
    // tree to table                                                                (done)
    // counting the sum                                                             (done)
    // get the max/min in not bst tree
    // calculate profendor                                                          (done)
    // calculate how many node in every layer (vertical)                            (done)
    // compare between two BSTs with defferent situation and the some values
    // make algorithme to turn table to linear bst
    // calculate bst layers sum                                                     (done)
    // count how many 'aghsan' (branches)
    // make is linear function                                                      (done)


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct tree tree ;

struct tree{
    int value ;
    tree *left ;
    tree *right ;
};

typedef struct list list ;

struct list{
    int value ;
    list *next ;
};

// work
int is_empty(tree *a){
    if(a == NULL)
        return 1 ;
    return 0 ;
}
// work
tree *create_tree() {
    return NULL ;
}
// work
tree *enracine(int value , tree *left , tree *right){
    tree *ptr = malloc(sizeof(tree)) ;
    ptr->value = value ;
    ptr->left = left ;
    ptr->right = right ;

    return ptr ;
}
// work
tree *insert_item(tree *a , int value){
    if(a==NULL)
        a = enracine(value,NULL,NULL) ;
    else {
        if (value < a->value)
            a->left = insert_item(a->left,value) ; 
        else
            a->right = insert_item(a->right,value) ; 
    }
    return a ;
}
// work
tree *insert_table(tree *a , int t[] ,int length){

    a = insert_item(a,t[length-1]) ;

    if(length == 1 ) 
        return a ;

    a =  insert_table(a , t , length-1) ;
}
// work
void print_grd(tree *a){
    if(a==NULL)
        printf("empty tree ");

    print_grd(a->left) ;
    printf("%d ",a->value) ;
    print_grd(a->right) ;

}
// work
int map(tree *a , int value){
    // this function return integer that could help to find the direction exactly

    // 1 => left
    // 2 => right 
    // -1 => not found
    // 0 => the head of the tree

    if(a==NULL)
        return -1 ;

    tree *ptr = a ;
    int index = 0 ;

    while(ptr!=NULL){
        if(ptr->value == value)
            return index ;

        if(value < ptr->value && index == 0){
            index = 1 ;
            ptr = ptr->left ;
            continue;
        }

        if(value > ptr->value && index == 0){
            index = 2 ;
            ptr = ptr->right ;
            continue;
        }

        if(value<ptr->value){
            index = index*10 + 1 ;
            ptr = ptr->left ;
        }

        else{
            index = index*10 + 2 ;
            ptr = ptr->right ;
        }
    }
    return -1 ;
}

int replace(tree *a , int value1 , int value2){
    // replace value by another one , return 1 if the action run seccufuly , 0 if the value not found
    if(a==NULL)
        return 0 ;
    tree *ptr = a ;
    while(ptr!=NULL){
        if(ptr->value==value1){
            ptr->value = value2 ;
            return 1 ;
        }
        else 
            if(value1 < ptr->value)
                ptr = ptr->left ;
            else
                ptr = ptr->right ;
    }
    return 0 ;
}
// work
int is_found(tree *a , int value){
    // 1 if found else 0
    tree *ptr = a ;
    while(ptr!=NULL){
        if(ptr->value == value)
            return 1 ;
        else 
            if (value < ptr->value)
                ptr = ptr->left ;
            else 
                ptr = ptr->right ;
    }
    return 0 ;
}
// work
int length(tree *a){
    if (a==NULL)
        return 0 ;
    return 1 + length(a->left) + length(a->right) ;
}
// work
tree *parent(tree *a,int value){
    // return NULL if the value not found
    // return the same value if it is in the head
    // else return the parent

    if(a==NULL)
        return NULL ;

    tree *ptr = a ;
    tree *previous = a ;

    while(ptr!=NULL){
        if(value == ptr->value)
            return previous ;

        previous = ptr ;

        if(value < ptr->value)
            ptr = ptr->left ;

        else
            ptr = ptr->right ;
            
    }
    return previous ;
}
// work
tree *adress(tree *a , int value){
    if(a==NULL)
        return NULL ;
    tree *ptr = a ;
    while(ptr!=NULL){
        if(value == ptr->value)
            return ptr ;
        if(value < ptr->value)
            ptr = ptr->left ;
        else
            ptr = ptr->right ;
    }
    return NULL ;
}
// work
int is_paper(tree *a,int value){
    // return 1 if value is paper value
    // return 0 if not
    // return -1 if tree is empty
    // return -2 if value not found

    if(a==NULL)
        return -1 ;
    tree *ptr = a ;
    while(ptr!=NULL){
        if(value == ptr->value){
            if(ptr->left==NULL &&ptr->right==NULL)
                return 1 ;
            return 0 ;
        }
        if(value < ptr->value)
            ptr=ptr->left ;
        else
            ptr=ptr->right ;
    }
    return -2 ;
}

void print_table(int t[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",t[i]) ;
    }
}

int compare(tree *a,tree *b){
    if(a!=NULL && b!=NULL){
        if(a->value==b->value)
            return compare(a->left,b->left) && compare(a->right,b->right) ;

        else return 0;
    }
    else
        if(a==NULL && b==NULL)
            return 1 ;
        else
            return 0 ;
}
// work
tree *max(tree *a){
    if(a==NULL)
        return NULL ;
    tree *ptr = a ;
    while(ptr->right!=NULL){
        ptr=ptr->right ;
    }
    return ptr ;
}
// work
tree *min(tree *a){
    if(a==NULL)
        return NULL ;
    tree *ptr = a ;
    while(ptr->left!=NULL){
        ptr=ptr->left ;
    }
    return ptr ;
}
// finally it's work !
int delete_item(tree *a, int value){
    // get the item :
    tree *ptr = adress(a,value) ;
    int left = 0 , right = 0 ;
    tree *par = parent(a,value) ;
    if(ptr->left)
        left = 1 ;
    if(ptr->right)
        right = 1 ;
    // ----------------------------- if had no child --------------------------------------------------------------------//
    if(left+right == 0){
        // testing where the child is collected with his father then delete it using free :
        if(par->left==ptr){
            par->left = NULL ;
            free(ptr) ;
        }
        else{
            par->right = NULL ;
            free(ptr) ;
        }
        return value ;
    }
    // ------------------------------- if had single child ----------------------------------------------------------------//
    if(left+right == 1){
        // if the child in the left side of his father :
        if(par->left==ptr){
            // if the child son in the left :
            if(left){
                par->left = ptr->left ;
                free(ptr) ;
            }
            // if the child son in the right :
            else{
                par->left = ptr->right ;
                free(ptr) ;
            }
        }
        // if the child in the right side of his father :
        else{
            // if the child son in the left :
            if(left){
                par->right = ptr->left ;
                free(ptr) ;
            }
            // if the child son in the right :
            else{
                par->right = ptr->right ;
                free(ptr) ;
            }
        }
        return value ;
    }
    // --------------------------- if had two childern ------------------------------------------------------------------//
    int pred = max(a->left)->value ;
    delete_item(a,pred) ;
    a->value = pred ;
    return value ;
}

// not really :
tree *random_insertion(tree *a , int len , int random ){
    if(random)
        srand(time(NULL)) ;

    int childs = rand()%3 ;
    int child_left=0 , child_right=0 ;
    int value=rand()%100 ;

    if(!len)
        return a ;
    else if(len == 1) return enracine(value,NULL,NULL) ;

    switch (childs)
    {
    case 0 : child_left = len-1 ;
    case 1 : child_right = len-1 ;
    case 2 : child_left = len/2 ; child_right = len - child_left -1 ;
    }

    return enracine(value,random_insertion(a,child_left,0),random_insertion(a,child_right,0)) ;
}
// work
int sum(tree *a){
    if(a==NULL)
        return 0 ;
    return a->value + sum(a->left) + sum(a->right) ;
}
// work
int how_many_positive(tree *a){
    if(a==NULL)
        return 0 ;
    else{
        if(a->value > 0)
            return 1 + how_many_positive(a->left) + how_many_positive(a->right) ;
        else
            return how_many_positive(a->left) + how_many_positive(a->right) ;
    }
}
// work
int sum_positive(tree *a){
    if(a==NULL)
        return 0 ;
    else {
        if(a->value > 0)
            return a->value + sum_positive(a->left) + sum_positive(a->right) ;
        else
            return sum_positive(a->left) + sum_positive(a->right) ;
    }
}
// work
int max_int(int a ,int b){
    if(a>b)
        return a ;
    return b ;
}
// work
int profendor(tree *a){
    if(a==NULL)
        return 0 ;
    if(a->left==NULL && a->right==NULL)
        return 1 ;
    else{
        int left = profendor(a->left) ;
        int right = profendor(a->right) ;
        return 1 + max_int(left,right) ;
    }
}
// not really
tree *item_by_map(tree*a , int map_index){
    tree *ptr = a ;
    while(map_index!=0){
        int now = map_index%10 ;
        switch (now)
        {
        case 0 : return ptr ;
        case -1 : return NULL ;
        case 1 : ptr = ptr->left ;
        case 2 : ptr = ptr->right ;
        }
        map_index = map_index/10 ;
    }
    return ptr ;
}
// work
int layer_length(tree *a , int layer){
    if(a==0)
        return 0 ;
    if(layer==0)
        return 1 ;
    return layer_length(a->left,layer-1) + layer_length(a->right,layer-1) ;
}
// work
int layer_sum(tree *a , int layer){
    if(a==0)
        return 0 ;
    if(layer==0)
        return a->value ;
    return layer_sum(a->left,layer-1) + layer_sum(a->right,layer-1) ;
}
// work
int sum_before_layer(tree *a, int layer){
    if(a==0 || layer==0)
        return 0 ;
    if(layer==1)
        return a->value ;
    return a->value + sum_before_layer(a->left,layer-1) + sum_before_layer(a->right,layer-1) ;
}

void print_rgd(tree *a){
    if(a!=NULL){
        printf("%d ",a->value) ;
        print_rgd(a->left) ;
        print_rgd(a->right) ;
    }
}

void dir(tree *a,int value){
    if(a!=NULL){
        if(value < a->value){
            printf("%d ",a->value) ;
            dir(a->left,value);
        }
        else
            if(value > a->value){
                printf("%d ",a->value) ;
                dir(a->right,value);
            }
            else
                printf("%d ",a->value) ;
    }
}

int papers(tree *a){
    if(a==NULL)
        return 0 ;
    if(a->left==NULL && a->right==NULL)
        return 1 ;
    return papers(a->left)+papers(a->right) ;
}

int internals(tree *a){
    if(a==NULL)
        return 0 ;

    if(!(a->left==NULL && a->right==NULL))
        return 1 + internals(a->right)+internals(a->left) ;
}

int max3(int a, int b, int c) {
    int t[] = {a,b,c} ;
    for (int i = 0; i < 3 ; i++)
    {
    if(t[i]>=b && t[i]>=c && t[i]>=a)
        return t[i] ;
    }
    return a ;
}


int is_linear(tree *a){
    if(a==NULL)
        return 1 ;

    tree *ptr = a ;
    if(a->left){
        while(ptr!=NULL){
            if(ptr->right)
                return 0 ;
            ptr = ptr->left ;
        }
    }

    else{
        while(ptr!=NULL){
            if(ptr->left)
                return 0 ;
            ptr = ptr->right ;
        }
    }
    return 1 ;
}

// work : don't forget to create i=0 and send its adress in first call :
void tree_to_table(tree *a, int t[] , int *index){
    
    if(a!=NULL){
    tree_to_table(a->left,t,index) ;
    t[*index] = a->value ;
    *index = *index +1 ;
    tree_to_table(a->right,t,index) ;
    }

}

tree *random_bst(tree *a ,int length){
    if(length < 1)
        return a ;
    tree *ptr = create_tree() ;
    srand(time(NULL)) ;
    for (int i = 0; i < length; i++)
    {   
        int value = rand()%100 ; 
        a = insert_item(a,value) ;
    }
    return a ;
}

tree *random_bst_rec(tree *a , int length){
    srand(time(NULL)) ;
    if(length<1)
        return a ;
    a = insert_item(a,rand()%100) ;
    return random_bst(a,length-1) ;
}

int is_bst(tree *a){
    if(a==NULL)
        return 1 ;

    int ordred = 1 ;

    if(a->left)
        if(a->value < a->left->value)
            ordred = 0 ;

    if(a->right)
        if(a->value > a->right->value)
            ordred = 0 ;

    return ordred && is_bst(a->left) && is_bst(a->right) ;
}

tree *insert_range(tree *a , int start , int stop , int step){
    for (int i = start; i < stop ; i+=step)
    {
        a = insert_item(a,i) ;
    }
    return a ;
    
}

list *insert_item_to_list(list *ptr , int value){
    if(ptr==NULL){
        ptr = malloc(sizeof(list)) ;
        ptr->value = value ;
        ptr->next = NULL ;
        return ptr ;
    }
    list *ptr2 = ptr ;
    while(ptr2->next!=NULL){
        ptr2 = ptr->next ;
    }
    ptr2->next = insert_item_to_list(ptr2->next,value) ;
    return ptr ;

}

list *smallest_k_number(tree *a , int k , list *ptr){
    if(k==0 || a==NULL)
        return NULL ;
    // smallest_k_number(a->left,k-1,ptr) ;
    // ptr = insert_item_to_list(ptr,a->value) ;
    // smallest_k_number(a->right,k-2,ptr) ;
    // int deleted = delete_item(a,min(a)->value) ;
    // ptr = insert_item_to_list(ptr,deleted) ;
    // a = insert_item(a,deleted) ;
    // return ptr ;
    for (int i = 0; i < k ; i++)
    {
        int deleted = delete_item(a,min(a)->value) ;
        ptr = insert_item_to_list(ptr,deleted) ;
    }
    return ptr ;
    
}

list *tree_to_list(tree*a , list *ptr){
    if(a==NULL)
        return NULL ;

    if(a->left!=NULL)
        tree_to_list(a->left,ptr) ;
    ptr = insert_item_to_list(ptr,a->value) ;
    tree_to_list(a->right,ptr) ;
    return ptr ;
}
// int branches(){

// }

// int compare_values(tree *a , tree *b){
//     int t1[100] ;
//     int t2[100] ;
//     int k = 0 ;
//     tree_to_table(a,t1,&k) ;
//     int j = 0 ;
//     tree_to_table(b,t2,&j) ;
//     for (int i = 0; i < length(a) - 1; i++)
//     {
//         if(t1[i]!=t2[i])
//             return 0 ;
//     }
    
//     // if(t1 == t2)
//     //     return 1 ;
//     // return 0 ;
//     return 1 ;
// }

void sep(){
    printf("\n") ;
}

int main(){


    // tree *head = create_tree() ;
    // // int t[] = {9,6,4,7,5,-2,-6,-5,1} ;
    // // // int t[] = {9,8,7,6,5,4,3,2,1} ;
    // // head = insert_table(head , t , 9) ;
    // head = insert_range(head,4,50,6) ;
    // // head = insert_range(head,1,50,5) ;
    // // print_grd(head) ;

    // list *ptr = NULL ;
    // // ptr = insert_item_to_list(ptr,1) ;
    // // ptr = insert_item_to_list(ptr,2) ;
    // // ptr = insert_item_to_list(ptr,3) ;

    // ptr = smallest_k_number(head,2,ptr) ;
    // list *ptr = NULL ;
    // ptr = tree_to_list(head,ptr) ;
    // while(ptr!=NULL){
    //     printf("%d ",ptr->value) ;
    //     ptr = ptr->next ;
    // }
    tree *ptr =NULL ;
    ptr = random_insertion(ptr,5,1) ;
    print_grd(ptr) ;
    
    return 0 ;
}

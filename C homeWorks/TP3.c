//  _                         _      _         _            _            _      _
// | |__    ___   _   _  ____(_)  __| |       | | __  ___  | |__    ___ | |__  (_)
// | '_ \  / _ \ | | | ||_  /| | / _` |       | |/ / / _ \ | '_ \  / __|| '_ \ | |
// | |_) || (_) || |_| | / / | || (_| |       |   < | (_) || |_) || (__ | | | || |
// |_.__/  \___/  \__,_|/___||_| \__,_| _____ |_|\_\ \___/ |_.__/  \___||_| |_||_|
//                                     |_____|
//
//                                     ____   _____
//   __ _  _ __   ___   _   _  _ __   | __ ) |___ /
//  / _` || '__| / _ \ | | | || '_ \  |  _ \   |_ \
// | (_| || |   | (_) || |_| || |_) | | |_) | ___) |
//  \__, ||_|    \___/  \__,_|| .__/  |____/ |____/
//  |___/                     |_|
// 

// the project features :
//  - easy to add student , delete , read from csv file , search and more to descover
//  - beatiful colored terminal interface to get access to all data
//  - binary search tree and graph data structure builtin to choose from
//  - readable code to debug , understand , and copy/paste from/to it 


// libraries used

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// colors :
char *cyan = "\033[96m" ;
char *green = "\033[92m" ;
char *endcolor = "\033[0m" ;
char *yellow = "\033[93m" ;
char *red = "\033[91m" ;

// ------------------------------------------------------------------------------ BST part ---------------------------------------------------------------------- //

// data structure named tree :
struct node {
    int code;
    char last_name [20];
    float mark;
    struct node *left;
    struct node * right;
};
typedef struct node* tree;      // simplified structure named tree


// create node

tree create_node (int code,char last_name [], float mark,tree left, tree right){
    tree root = malloc (sizeof(struct node));       // reserve space memory
    root->code = code;
    root->mark = mark;
    strcpy(root->last_name,last_name);              // use strcpy to make a copy of last_name
    root->left = left;
    root->right = right;
    return root;
}


// insert node to BST

tree insert_node (tree root ,int code ,char last_name [], float mark){
    if(root==NULL)
        root = create_node (code,last_name,mark,NULL,NULL) ;        // case empty tree
    else {
        if (mark < root->mark)      // left side
            root->left = insert_node(root->left,code,last_name,mark) ;
        else                        // right side
            root->right = insert_node(root->right,code,last_name,mark) ;
    }
    return root ;
}

// display DRG (from higher to smaller)

void DRG (tree root){
    if(root!=NULL){
        DRG (root->right);          // move to right side
        printf("\t%s %04d %s %s%s%s \t %.2f\n",cyan , endcolor, root->code, yellow , root->last_name , endcolor, root->mark);   // %04d to appear code with 4 digits     
        // print the information of node
        DRG (root->left);
    }
}

// display GRD (from smaller to higher)

void GRD (tree root){
    if(root!=NULL){
        GRD (root->left);
        printf("\t%s %04d %s  %s%s%s \t %.2f\n", cyan , root->code , endcolor , yellow , root->last_name , endcolor,root->mark);   // print the information of node
        GRD (root->right);      // move to right side
    }
}


// display RDG

void RDG (tree root){
    if(root!=NULL){
        printf("\t%s %04d %s  %s%s%s \t %.2f\n", cyan , root->code , endcolor , yellow , root->last_name , endcolor,root->mark);   // print the information of node
        RDG (root->right);      // move to right side
        RDG (root->left);       //  move to the left side
    }
}


// display RGD

void RGD (tree root){
    if(root!=NULL){
        printf("\t%s %04d %s  %s%s%s \t %.2f\n", cyan , root->code , endcolor , yellow , root->last_name , endcolor,root->mark);   // print the information of node
        RGD (root->left);       //  move to the left side
        RGD (root->right);      // move to right side
    }
}

// display GDR

void GDR (tree root){
    if(root!=NULL){
        GDR (root->left);       //  move to the left side
        GDR (root->right);      // move to right side
        printf("\t%s %04d %s  %s%s%s \t %.2f\n", cyan , root->code , endcolor , yellow , root->last_name , endcolor,root->mark);   // print the information of node
    }
}

// display GDR

void DGR (tree root){
    if(root!=NULL){
        DGR (root->right);      // move to right side
        DGR (root->left);       //  move to the left side
        printf("\t%s %04d %s  %s%s%s \t %.2f\n", cyan , root->code  , endcolor , yellow , root->last_name , endcolor,root->mark);   // print the information of node
    }
}

// display Largueur

void Largueur (tree root){
    if(root!=NULL){
        Largueur (root->right); // move to right side
        Largueur (root->left);  //  move to the left side
        printf("\t%s %04d %s  %s%s%s \t %.2f\n", cyan , root->code  , endcolor , yellow , root->last_name , endcolor,root->mark);   // print the information of node
    }
}



// search node depend mark

tree search_node (tree root , float mark){
    while(root != NULL && root->mark != mark){
        if (mark < root->mark)      // left side
            root = root->left ;     // move one step in the left side
        else        // right side
            root = root->right ;        // move one step in the right side
    }
    return root;
}



// find student insert before me

tree father_node (tree root, float mark){
    if (root ==NULL)
        return NULL;
    tree ptr = root, previous = root;
    while(ptr!=NULL){
        if(mark == ptr->mark)
            return previous ;
        previous = ptr ;
        if(mark < ptr->mark)
            ptr = ptr->left ;
        else
            ptr = ptr->right ;
    }
    return previous ;
}



// delete node from BST

tree delete_student (tree root, float mark) {
    tree ptr = search_node (root,mark);   // Find the node to be deleted
    if (ptr == NULL)           // case empty tree
        return ptr;
    if (ptr->right==NULL && ptr->left == NULL)      // case node without children
        free (ptr);
    else {
        if (ptr->right!=NULL && ptr->left != NULL){     // case node have two children
        }
        else {          // case node have one child
            tree ptr_2 = father_node (root,mark);
            if (ptr->left == NULL){
                if(mark < ptr_2->mark)
                    ptr_2->left =ptr->right;
                else
                    ptr_2->right = ptr->right;
            }
            else{
                if(mark < ptr_2->mark)
                    ptr_2->left =ptr->left;
                else
                    ptr_2->right = ptr->left;
            }
            ptr->left=NULL;
            ptr->right=NULL;
            free (ptr);
        }
    }
    return root;
}






// your name
void your_name (char name []){
	printf ("give me your name : ");
	scanf ("%s",name);              // puts name from user
}



// welcome
void welcome (char name[]){
    char *yellow = "\033[93m" ;
    char *endcolor = "\033[0m" ;
	printf ("%swelcome %s%s%s to our app%s\n", cyan , yellow , name , cyan ,endcolor);        // welcome message
}

// goodbye

void goodbye (char name []){
    char *yellow = "\033[93m" ;
    char *endcolor = "\033[0m" ;
	printf ("goodbye %s%s%s , I hope you find what you wish (^_^)", yellow ,name , endcolor);    // goodbye message
}


// length of tree

int length_tree (tree root){
    if (root == NULL)
        return 0;       // case empty tree
    else
        return 1+length_tree (root->left)+length_tree(root->right); // 1 for root + number of nodes right + number of nodes left
}

// first menu :

void menu_1 (int *answer,tree root){

    int number_of_student = length_tree (root);     // find number of nodes in the tree
    if (number_of_student > 1){
        printf ("\tpress %s1%s if you %swant insert new student%s\n", cyan , endcolor , green , endcolor);
        printf ("\tpress %s2%s if you %slooking for student :%s modified, deleted or display\n", cyan , endcolor , green , endcolor);
        printf ("\tpress %s3%s if you %swant see smart student and stupid one%s\n", cyan , endcolor , green , endcolor);
        printf ("\tpress %s4%s if you %swant see all students%s\n", cyan , endcolor , green , endcolor);
        printf ("\tpress %s5%s if you %swant exit program%s\n", cyan , endcolor , green , endcolor);
        printf ("\tpress %s6%s if you %swant see the graph (adjacent list)%s \n", cyan , endcolor , green , endcolor );
        printf ("\tpress %s7%s if you %swant clean terminal%s \n", cyan , endcolor , green , endcolor );
        do{
            scanf ("%d",answer);
            if (*answer < 1 || *answer > 7)
                printf ("enter number between 1 and 7\n");              // message appear when you insert wrong number
        }while(*answer < 1 || *answer > 7); // check you enter a correct number
    }
    else {
        printf ("\tpress %s1%s if you want insert new student\n", cyan , endcolor);
        printf ("\tpress %s2%s if you looking for student : modified, deleted or display\n", cyan , endcolor);
        printf ("\tpress %s3%s if you want see all students\n", cyan , endcolor);
        printf ("\tpress %s4%s if you want exit program\n", cyan , endcolor);
        do{
            scanf ("%d",answer);
            if (*answer < 1 || *answer > 4)
                printf ("enter number between 1 and 4\n");              // message appear when you insert wrong number
        }while(*answer < 1 || *answer > 4); // check you enter a correct number
    }
}

// second menu :


void menu_2 (int *answer,char name[]){

	printf ("\tpress %s1%s if you want modified %s%s%s", cyan , endcolor ,yellow,name,endcolor);
	printf ("\tpress %s2%s if you want deleted %s%s%s \n", cyan , endcolor ,yellow,name,endcolor);
	printf ("\tpress %s3%s if you want display %s%s%s\n", cyan , endcolor ,yellow,name,endcolor);
	printf ("\tpress %s4%s if you want back to menu 1\n");
	do{
		scanf ("%d",answer);
		if (*answer < 1 || *answer > 4)
			printf ("enter number between 1 and 4\n");              // message appear when you insert wrong number
	}while(*answer < 1 || *answer > 4); // check you enter a correct number
}

// method to fill list

int method_to_fill (){

    int answer;
    printf ("\tpress %s1%s to %sfill list by user%s\n", cyan , endcolor , green , endcolor );                  // option 1 : fill list by user
	printf ("\tpress %s2%s to %sfill from csv_file%s\n", cyan , endcolor , green , endcolor );                 // option 2 : fill list from csv file
	do{
		scanf ("%d",&answer);
		if (answer != 1 && answer != 2)
			printf ("enter 1 or 2\n");       // if you enter wrong number appear this message
	}while(answer != 1 && answer != 2);     // check you enter a correct number
    return answer;
}


// insert new student

tree insert_new_student (tree root){
    int code;
    char last_name [20];
    float mark;
    printf ("give me the %sname%s of student ", cyan , endcolor);
    scanf ("%s",last_name);                             // insert last_name type char []
    printf ("give me the %scode%s of %s%s%s ", cyan , endcolor , yellow ,last_name , endcolor);
    do{
		scanf ("%d",&code);                                 // insert code type int
		if (code < 0 || code > 9999)
			printf ("enter code formed from 4 digits\n");       // if you enter wrong number appear this message
	}while(mark < 0 || mark > 20);     // check you enter a correct number
    printf ("give me the mark of %s%s%s ", yellow , last_name , endcolor);
    do{
		scanf ("%f",&mark);                             // insert mark type float
		if (mark < 0 || mark > 20)
			printf ("enter mark between 0 and 20\n");       // if you enter wrong number appear this message
	}while(mark < 0 || mark > 20);     // check you enter a correct number
    root = insert_node (root,code,last_name, mark);         // fill the node
    return root;
}




// fill tree

tree fill_tree (tree *root){
    char last_name [20];
    float mark;
    int answer,code;
    int fill_answer = method_to_fill ();
    if (fill_answer == 1){      // fill tree by user
        do {
            printf ("give me the %sname%s of student ",cyan , endcolor);
            scanf ("%s",last_name);                             // insert last_name type char []
            printf ("give me the %scode%s of %s%s%s ", cyan , endcolor , yellow ,last_name , endcolor);
            
            do{
                scanf ("%d",&code);                                 // insert code type int
                if (code < 0 || code > 9999)
                    printf ("enter code formed from 4 digits\n");       // if you enter wrong number appear this message
            }while(code < 0 || code > 9999);     // check you enter a correct number

            printf ("give me the mark of %s ",last_name);
            do{
                scanf ("%f",&mark);                             // insert mark type float
                if (mark < 0 || mark > 20)
                    printf ("enter mark between 0 and 20\n");       // if you enter wrong number appear this message
            }while(mark < 0 || mark > 20);     // check you enter a correct number

            root = insert_node (root,code,last_name, mark);         // fill the node
            printf ("do you want add another student ? (0/1)");
            scanf ("%d",&answer);
        }while (answer !=0);
    }
    else{               // fill tree from csv file
        FILE *csv_file;
        csv_file = fopen ("les notes.txt","r"); // read from file
        if (csv_file==NULL){
            printf ("%serror opening file %s\"les notes.txt\"%s ! %s",red , endcolor , red , endcolor);      // this message appear case of error
            exit (1);
        }
        //char delimiter [3]= " ;|"
        char *part,row [40];
        while (!feof(csv_file)){
            fgets(row,40,csv_file);     // take from file line by line
            part = strtok (row,";"); //split string  named row into a series of tokens separated by ";"
            code = atoi (part);     // convert string to int
            part = strtok (NULL,";");  //split string separated by ";"
            strcpy(last_name,part);      // copy content of part and put if in last_name
            part = strtok (NULL,";");       //split string separated by ";"
            mark = atof (part);     // convert string to float
            root = insert_node (root,code,last_name, mark);     // fill node
        }
        fclose(csv_file);           // close the file
    }
    return root;
}

// menu 3

void menu_3(int *answer){
    printf ("\tpress %s1 %sif you want display %sRGD%s\n" , cyan , green , yellow , endcolor );
	printf ("\tpress %s2 %sif you want display %sRDG%s\n" , cyan , green , yellow , endcolor );
	printf ("\tpress %s3 %sif you want display %sGRD%s (from smaller to higher)\n" , cyan , green , yellow , endcolor );
	printf ("\tpress %s4 %sif you want display %sDGR%s (from higher to smaller)\n" , cyan , green , yellow , endcolor );
	printf ("\tpress %s5 %sif you want display %sGDR%s\n" , cyan , green , yellow , endcolor );
	printf ("\tpress %s6 %sif you want display %sDGR%s\n" , cyan , green , yellow , endcolor );
	printf ("\tpress %s7 %sif you want display %sLargueur%s\n" , cyan , green , yellow ,endcolor );
    do{
		scanf ("%d",answer);
		if (*answer < 1 || *answer > 7)
			printf ("enter number between 1 and 7\n");              // message appear when you insert wrong number
	}while(*answer < 1 || *answer > 7); // check you enter a correct number
}


// display tree

void display_tree (tree root, int answer){
    printf("----------------------------------------------------------\n") ;
    switch (answer){        // depend value enter choose method of print
        case 1 :
            RGD (root);     // print root left right
            break;
        case 2:
            RDG (root);             // print root right left
            break;
        case 3 :
            GRD (root);         // print left root right
            break;
        case 4 :
            DRG (root);         // right root left
            break;
        case 5 :
            GDR (root);         // left right root
            break;
        case 6 :
            DGR (root);         // right left root
            break;
        case 7 :
            Largueur (root);        // largueur
            break;
    }
    printf("----------------------------------------------------------\n") ;
}






// smart student

tree smart_student (tree root){
    if (root ==NULL)
        return NULL;        // case empty tree
     while(root->right!=NULL){
        root=root->right ;      // move one step in right side
    }
    return root ;       // return node have student have best mark
}



// stupid student

tree* stupid_student (tree root){
    if (root ==NULL)
        return NULL;        // case empty tree
     while(root->left != NULL){
        root=root->left ;       // move one step in left side
    }
    return root;        // return node have student have best mark
}



// ------------------------------------------------------------------------------ graph part ---------------------------------------------------------------------- //

// data structure named list

struct mylist {
    int code;
    char last_name [20];
    float mark;
    struct mylist* next;
};
typedef struct mylist* list;

// data structure named graph

struct graph {
    int nbr_vertices;
    //int* visited;
    list* adjacent_list;
};


// Create a node of adjacent list

list create_node_adjlist(tree root) {
  list new_node = malloc(sizeof(struct mylist));
  new_node->code = root->code;
  strcpy (new_node->last_name,root->last_name);
  new_node->mark = root->mark;
  new_node->next = NULL;
  return new_node;
}

// Create a graph

struct graph* create_graph(int nbr_vertices) {
  struct graph* my_graph = malloc(sizeof(struct graph));
  my_graph->nbr_vertices = nbr_vertices;
  my_graph->adjacent_list = malloc(nbr_vertices * sizeof(list));
  for (int i = 0; i < nbr_vertices; i++)
    my_graph->adjacent_list[i] = NULL;
  return my_graph;
}

void BST_to_array(tree root, float* array, int* i) {
    if (root != NULL){
    BST_to_array(root->left, array, i);     // recursion call of left side
    array[(*i)++] = root->mark;             // fill the array and increment i
    BST_to_array(root->right, array, i);    // recursion call of right side
    }
}


int index_of_mark (float array [],float mark){
    int index = 0;
    while (array [index]!=mark)
        index++;
    return index;
}

// Add edge

void add_edge(struct graph* my_graph, tree root,float array [],int index_s,int index_d) {
  tree ptr_s,ptr_d;
  // Add edge from source to distination
  ptr_d = search_node(root,array[index_d]);             // find node of distination
  list new_node = create_node_adjlist(ptr_d);           // create node of adjlist
  new_node->next = my_graph->adjacent_list[index_s];    // add the value of node to adjlist
  my_graph->adjacent_list[index_s] = new_node;

}


// fill adjlist

struct graph* fill_adjlist (struct graph* my_graph,float array [],tree root){
    tree ptr,ptr_father, ptr_right,ptr_left;
    int j,n = length_tree(root);        // find the number of nodes in tree
    for (int i = 0;i<n;i++){
        ptr_father = father_node(root,array[i]);        // find the father of node
        if (ptr_father!=NULL){                         // case node have a father
            j = index_of_mark (array,ptr_father->mark); // get the index of node from array
            add_edge(my_graph,root,array,i,j);       // add edge (node, father) to graph
        }
        ptr = search_node (root,array[i]);      // find the node
        ptr_right = ptr->right;                 // find the right child
        if (ptr_right!=NULL){                   // case node have a right child
            j = index_of_mark (array,ptr_right->mark);     // get the index of node from array
            add_edge(my_graph,root,array,i,j);          // add edge (node, right child) to graph
        }
        ptr_left = ptr->left;                   // find the left child
        if (ptr_left!=NULL){                    // case node have a left child
            j = index_of_mark (array,ptr_left->mark);       // get the index of node from array
            add_edge(my_graph,root,array,i,j);      // add edge (node, right child) to graph
        }
    }
    return my_graph;
}

// print_adjlist

void print_adjlist(struct graph* my_graph, float array []) {
  for (int i = 0; i < my_graph->nbr_vertices; i++) {
    list temp = my_graph->adjacent_list[i];
    printf("%.2f : ", array[i]);        // print mark
    while (temp != NULL) {
      printf("{ %s%04d%s , %s%s%s , %.2f } %s->%s ", cyan , temp->code , endcolor , yellow ,temp->last_name , endcolor , temp->mark , green , endcolor); // display value of node
      temp = temp->next;        // move temp one step
    }
    printf("\n");
  }
}



// ------------------------------------------------------------------------------ main part ---------------------------------------------------------------------- //

int main(){
    
    system("cls") ;

    printf("%s  _                         _      _         _            _            _      _ \n",green);
    printf(" | |__    ___   _   _  ____(_)  __| |       | | __  ___  | |__    ___ | |__  (_)\n");
    printf(" | '_ \\  / _ \\ | | | ||_  /| | / _` |       | |/ / / _ \\ | '_ \\  / __|| '_ \\ | |\n");
    printf(" | |_) || (_) || |_| | / / | || (_| |       |   < | (_) || |_) || (__ | | | || |\n");
    printf(" |_.__/  \\___/  \\__,_|/___||_| \\__,_| _____ |_|\\_\\ \\___/ |_.__/  \\___||_| |_||_|\n");
    printf("                                     |_____|                                    \n%s",endcolor);

    char name [20];
    your_name (name);       // insert your name
    welcome (name);         // welcome message
    int answer_1,answer_2,answer_3;
    tree root = NULL;       // initialization of tree
    root = fill_tree (root);        // fill tree by user or from file
    do{
        menu_1(&answer_1,root);          // appear first menu
        if (answer_1 ==1)
            root = insert_new_student (root);       // fill new student
        if (answer_1 ==2){
            float mark;
            printf ("\n\tgive me the mark : ");
            scanf ("%f",&mark);
            tree ptr = search_node (root,mark);     // find node have mark x
            if (ptr == NULL)
                printf ("%sno student have mark %s%.2f%s\n", red , yellow ,mark , endcolor );
            else {
                do{
                    menu_2(&answer_2,ptr->last_name);       // appear second menu
                    if (answer_2 ==1){       // modified the mark
                        float new_mark;
                        printf ("give me the new mark of %s ",ptr->last_name);
                        scanf ("%f",&new_mark);     // insert new mark
                        ptr->mark = new_mark;
                    }
                    if (answer_2 ==2)       // deleted student
                        /*printf ("not deleted\n");*/root = delete_student(root,mark);
                    if (answer_2 ==3)       // display node
                        printf("code : %04d\nlast name : %s\nmark : %.2f\n",ptr->code,ptr->last_name,ptr->mark);
                }while(answer_2 != 4);
            }
        }
        if (answer_1 ==3){

            tree smart ,stupid;
            smart = smart_student(root);        // find smart student
            stupid = stupid_student(root);      // find stupid student
            printf("\nsmart student is %s%s%s , he get %s%.2f%s\n", green , smart->last_name , endcolor , yellow , smart->mark , endcolor);
            printf("stupid student is %s%s%s , he get %s%.2f%s\n\n", red , stupid->last_name , endcolor , yellow , stupid->mark , endcolor);
        }
        if (answer_1 ==4){
            menu_3(&answer_3);      // appear third menu
            display_tree (root,answer_3);       // print tree
        }
        if (answer_1 ==5){
            // goodbye(name);      // goodbye message
            tree *head = NULL ;
            system("cls") ;
            printf("%sThank you to use This app => for More : %sBOUZID KOBCHI%s - %sLinkedIn %s", green , yellow , endcolor , cyan , endcolor) ;
        }
        if(answer_1 == 6){
            printf("\n") ;
            // Convert the BST to an array
            int i = 0, n = length_tree (root);
            float* array = malloc(n * sizeof(float));
            BST_to_array(root, array, &i);
            struct graph* my_graph = create_graph(n);
            my_graph = fill_adjlist (my_graph,array,root);
            print_adjlist(my_graph,array);
            printf("\n") ;
        }
        if(answer_1 == 7){
            system("cls");
        }
    }while(answer_1 != 5);
    return 0;
}

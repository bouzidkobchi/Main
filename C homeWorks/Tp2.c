//   _                         _      _         _            _            _      _         ____   _____ 
//  | |__    ___   _   _  ____(_)  __| |       | | __  ___  | |__    ___ | |__  (_)       | __ ) |___ / 
//  | '_ \  / _ \ | | | ||_  /| | / _` |       | |/ / / _ \ | '_ \  / __|| '_ \ | |       |  _ \   |_ \ 
//  | |_) || (_) || |_| | / / | || (_| |       |   < | (_) || |_) || (__ | | | || |       | |_) | ___) |
//  |_.__/  \___/  \__,_|/___||_| \__,_| _____ |_|\_\ \___/ |_.__/  \___||_| |_||_| _____ |____/ |____/ 
//                                      |_____|                                    |_____|

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *cyan = "\033[96m" ;
char *green = "\033[92m" ;
char *endcolor = "\033[0m" ;
char *yellow = "\033[93m" ;
char *red = "\033[91m" ;

int belongs_to_l1(char *word){
    // return False if it is empty string
    if(*word == '\0') return 0 ;

    // required variables
    // save word pointer (from changing)
    char *where_am_i = word ;
    int count_a = 0 ;
    int count_b = 0 ;

    while (*where_am_i != '\0'){
        // add 1 to count_a when you get it :
        if(*where_am_i == 'a')
            count_a ++ ;

        // add 1 to count_b when you get it :
        else if(*where_am_i == 'b')
            count_b ++ ;

        // return False if you get symbole doesn't belong to {a,b}
        else
            return 0 ;
        where_am_i ++ ;
    }
    // return True if a occurency equal b occurency otherwise False
    return count_a == count_b ;
}

int belongs_to_l2(char *word){
    // save word pointer (from changing)
    char *where_am_i = word ;
    while (*where_am_i != '\0')
    {   
        // if current letter not equal a or its next not equal b return False
        if(*where_am_i != 'a' || *(where_am_i+1) != 'b')
            return 0 ;
        where_am_i += 2 ;
    }
    return 1 ;
    
}

int belongs_to_l3(char *word){
    // save word pointer (from changing)
    char *where_am_i = word ;
    int count_a = 0 ;

    // return False if it is empty string :
    if (*where_am_i == '\0')
        return 0 ;


    while (*where_am_i !='b'){
        // if current letter not equal a or its next not equal b return False
        if(*where_am_i != 'a' || *(where_am_i+1) == '\0')
            return 0 ;

        // increase count_a for counting , where_am_i for iterate inside that string
        count_a ++ ;
        where_am_i ++ ;
    }

    // if count_a is odd number return False
    if(count_a % 2 != 0) return 0 ;

    // otherwise if there a different letter return False
    while (*where_am_i != '\0')
    {
        if (*where_am_i != 'b')
            return 0 ;
        where_am_i ++ ;
    }
    return 1 ;
    
}

int belongs_to_l4(char *word){
    // save word pointer (from changing)
    char *where_am_i = word ;

    // empty string not acceptable
    if (*where_am_i == '\0')
        return 0 ;

    while (*where_am_i != '\0')
    {   
        // if current letter not equal a or its next not equal b return False
        if(*where_am_i != 'a' || *(where_am_i+1) != 'b')
            return belongs_to_l3 (where_am_i) ;

        where_am_i += 2 ;
    }
    return 1 ;
    
}

int length(char *text){
    if (*text == '\0')
        return 0 ;
    return 1 + length(text+1) ;
}

char *input(char *text){
    printf("%s",text);
    char *t = malloc(sizeof(char)*100);
    gets(t);
    return t ;
}

void print_header(){
    printf("%s _                         _      _         _            _            _      _         ____   _____  \n",green); 
    printf("| |__    ___   _   _  ____(_)  __| |       | | __  ___  | |__    ___ | |__  (_)       | __ ) |___ /  \n"); 
    printf("| '_ \\  / _ \\ | | | ||_  /| | / _` |       | |/ / / _ \\ | '_ \\  / __|| '_ \\ | |       |  _ \\   |_ \\  \n"); 
    printf("| |_) || (_) || |_| | / / | || (_| |       |   < | (_) || |_) || (__ | | | || |       | |_) | ___) | \n");  
    printf("|_.__/  \\___/  \\__,_|/___||_| \\__,_| _____ |_|\\_\\ \\___/ |_.__/  \\___||_| |_||_| _____ |____/ |____/  \n");  
    printf("                                    |_____|                                    |_____|               \n%s",endcolor);
}

void print_choices(){
    printf("%s1%s     - %sL1\n",yellow , endcolor , cyan) ;
    printf("%s2%s     - %sL2\n",yellow , endcolor , cyan) ;
    printf("%s3%s     - %sL3\n",yellow , endcolor , cyan) ;
    printf("%s4%s     - %sL4\n",yellow , endcolor , cyan) ;
    printf("%s5%s     - %sAll\n",yellow , endcolor , cyan) ;
    printf("%s6%s     - %sclear\n",yellow , endcolor , cyan) ;
    printf("%s>= 7 %s -%s quit%s\n\n",yellow , endcolor , cyan , endcolor) ;
}

void clean_word(char *word , int length){
    for (int i = 0; i < length ; i++)
    {
        word[i] = '\0' ;
    }
    
}

void main(){
    char word[1000] = "\0" ;
    int choice = -1 ;
    char appname[20] = "bouzid app" ;

    print_header() ;
    print_choices() ;
    
    while (choice < 7){

        // get choice :
        printf("%s> ",appname) ;
        scanf("%d",&choice) ;

        switch (choice)
        {
            case 1 :
                printf("%sword : %s",yellow , endcolor) ;
                scanf("%s",&word) ;

                if(belongs_to_l1(word))
                    printf("%sTrue%s\n" , green , endcolor) ;
                else
                    printf("%sFalse%s\n" , red , endcolor) ;
                break ;

            case 2 :
                printf("%sword : %s",yellow , endcolor) ;
                scanf("%s",&word) ;

                if(belongs_to_l2(word))
                    printf("%sTrue%s\n" , green , endcolor) ;
                else
                    printf("%sFalse%s\n" , red , endcolor) ;
                break ;

            case 3 :
                printf("%sword : %s",yellow , endcolor) ;
                scanf("%s",&word) ;

                if(belongs_to_l3(word))
                    printf("%sTrue%s\n" , green , endcolor) ;
                else
                    printf("%sFalse%s\n" , red , endcolor) ;
                break ;

            case 4 :
                printf("%sword : %s",yellow , endcolor) ;
                scanf("%s",&word) ;

                if(belongs_to_l4(word))
                    printf("%sTrue%s\n" , green , endcolor) ;
                else
                    printf("%sFalse%s\n" , red , endcolor) ;
                break ;

            case 5 :
                printf("%sword : %s",yellow , endcolor) ;
                scanf("%s",&word) ;

                if(belongs_to_l1(word))
                    printf("  L1 : %sTrue%s\n" , green , endcolor) ;
                else
                    printf("  L1 : %sFalse%s\n" , red , endcolor) ;

                if(belongs_to_l2(word))
                    printf("  L2 : %sTrue%s\n" , green , endcolor) ;
                else
                    printf("  L2 : %sFalse%s\n" , red , endcolor) ;

                if(belongs_to_l3(word))
                    printf("  L3 : %sTrue%s\n" , green , endcolor) ;
                else
                    printf("  L3 : %sFalse%s\n" , red , endcolor) ;

                if(belongs_to_l4(word))
                    printf("  L4 : %sTrue%s\n" , green , endcolor) ;
                else
                    printf("  L4 : %sFalse%s\n" , red , endcolor) ;

                break ;
            
            case 6 :
                // clear
                system("cls") ;
                print_header() ;
                print_choices() ;
                break;

        }
        printf("\n") ;
        clean_word(word , length(word)) ;
    }

    system("cls") ;
    printf("%sThanks to use %s!%s\n", yellow ,appname , yellow) ;
    print_header() ;

}
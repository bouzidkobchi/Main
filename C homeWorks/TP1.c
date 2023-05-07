//   _                         _      _         _            _            _      _         ____   _____ 
//  | |__    ___   _   _  ____(_)  __| |       | | __  ___  | |__    ___ | |__  (_)       | __ ) |___ / 
//  | '_ \  / _ \ | | | ||_  /| | / _` |       | |/ / / _ \ | '_ \  / __|| '_ \ | |       |  _ \   |_ \ 
//  | |_) || (_) || |_| | / / | || (_| |       |   < | (_) || |_) || (__ | | | || |       | |_) | ___) |
//  |_.__/  \___/  \__,_|/___||_| \__,_| _____ |_|\_\ \___/ |_.__/  \___||_| |_||_| _____ |____/ |____/ 
//                                      |_____|                                    |_____|

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *cyan = "\033[96m" ;
char *green = "\033[92m" ;
char *endcolor = "\033[0m" ;
char *yellow = "\033[93m" ;
char *red = "\033[91m" ;

int length(char *text){
    if (*text == '\0')
        return 0 ;
    return 1 + length(text+1) ;
}

int count_duplicate(char *text , char letter){
    if (*text != '\0'){
        if (*text == letter)
            return 1 + count_duplicate(text + 1 , letter) ;
        return count_duplicate(text + 1 , letter) ;
    }
    return 0 ;
}

void concatenate(char *text1 , char*text2){
    // text1 = text1+text2
    if(*text2 != '\0'){
        if(*text1 == '\0'){
            *text1 = *text2 ;
            text2 ++ ;
        }
        concatenate(text1+1 , text2) ;
    }
}

int compare(char *text1 , char *text2){
    if(*text1=='\0' && *text2=='\0')
        return 1 ;
    else if(*text1 == *text2)
        return 1 && compare(text1+1 , text2+1) ;
    return 0 ;
}

int is_palindrome(char *text , int l){
    if(l==0) return 1 ;
    if (*text == *(text+l-1)){
        return 1 && is_palindrome(text+1 , l-2) ;
    }
    return 0; 
}

void reverse(char *text, int length){
    if(length < 2) return ;
    char t = *text ;
    *text = *(text+length-1) ;
    *(text+length-1) = t ;
    reverse(text+1 , length-2) ;
}

void power(char *text , char *initial_value , int n){
    // copy initial_value to keep it save :
    char t[100] ; 
    strcpy(t,initial_value) ;

    if (n > 1){
        concatenate(text , t) ;
        power(text , t , n-1) ;
    }
}

void clean_word(char *word , int length){
    for (int i = 0; i < length ; i++)
    {
        word[i] = '\0' ;
    }
    
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
    printf("%s1%s     - %slength\n",yellow , endcolor , cyan) ;
    printf("%s2%s     - %scount duplicates\n",yellow , endcolor , cyan) ;
    printf("%s3%s     - %sconcatenate\n",yellow , endcolor , cyan) ;
    printf("%s4%s     - %scompare\n",yellow , endcolor , cyan) ;
    printf("%s5%s     - %sis_palindrome\n",yellow , endcolor , cyan) ;
    printf("%s6%s     - %sreverse\n",yellow , endcolor , cyan) ;
    printf("%s7%s     - %spower\n",yellow , endcolor , cyan) ;
    printf("%s8%s     - %sclear\n",yellow , endcolor , cyan) ;
    printf("%s>= 9 %s -%s quit%s\n\n",yellow , endcolor , cyan , endcolor) ;
}

void main(){

    // methods :
        // 1 - length
        // 2 - count duplicate
        // 3 - concatenate
        // 4 - compare
        // 5 - is_palindrome
        // 6 - reverse
        // 7 - power
        // 8 - clear
        // 9 or greater - quit
    
    // global variables :
    char word1[1000] ;
    char word2[1000] ;
    int choice = -1 ;
    char appname[20] = "bouzid app" ;

    // check gets for space support
    print_header() ;
    print_choices() ;
    while (choice < 9)
    {
        // get choice :
        printf("%s> ",appname) ;
        scanf("%d",&choice) ;

        switch (choice)
        {
        case 1 :
            printf("word : ") ;
            scanf("%s",word1) ;
            printf("%d\n",length(word1)) ;
            break;

        case 2 :
            printf("word : ") ;
            scanf("%s",word1) ;
            printf("character : ") ;
            char c ;
            scanf(" %c",&c) ;
            printf("%d\n",count_duplicate(word1 , c )) ;
            break;

        case 3 : 
            printf("word 1 : ") ;
            scanf("%s",word1) ;
            // gets(&word1) ;
            printf("word 2 : ") ;
            scanf("%s",word2) ;
            // gets(&word2) ;
            concatenate(word1 , word2) ;
            printf("%s\n",word1) ;
            break;

        case 4 :
            printf("word 1 : ") ;
            scanf("%s",word1) ;
            printf("word 2 : ") ;
            scanf("%s",word2) ;
            printf("%d\n",compare(word1 , word2)) ;
            break;

        case 5 :
            printf("word 1 : ") ;
            scanf("%s",word1) ;
            printf("%d\n",is_palindrome(word1 , length(word1))) ;
            break;

        case 6 :
            printf("word 1 : ") ;
            scanf("%s",word1) ;
            reverse(word1 , length(word1)) ;
            printf("%s\n",word1) ;
            break;

        case 7 :
            printf("word 1 : ") ;
            scanf("%s",word1) ;
            printf("n : ") ;
            int n ;
            scanf("%d",&n) ;
            power(word1 , word1 , n) ;
            printf("%s\n",word1) ;
            break;

        case 8 :
            system("cls") ;
            print_header() ;
            print_choices() ;
            break;

        default:
            break;
        }
        clean_word(word1 , length(word1)) ;
        clean_word(word2 , length(word2)) ;
    }
    system("cls") ;
    printf("Thanks to use %s!\n",appname) ;
    print_header() ;

}
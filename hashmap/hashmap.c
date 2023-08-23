#include <stdio.h>
#include <string.h>

typedef struct {
    char name[256];
    int age;

} person;

person * hash_table[10];

void init_hash_table(){
    for(int i=0; i<10; i++){
        hash_table[i] = NULL;
    }
}

void display_hash_table(){
    printf("START!\n");
    for(int i=0; i<10; i++){
        printf("%d    ", i+1);
        if(hash_table[i]->name == NULL){
            printf("----\n");
        }else{
            printf("%s\n", hash_table[i]->name);
        }
    }
    printf("END!\n");
}

int hash(char *name){
    int length = strlen(name);
    int hashnum = 0;

    for(int i=0; i<length; i++){
        hashnum += name[i];
    }

    hashnum = hashnum%10;
    return hashnum;
}



int main(){

    printf("Jacob=> %d\n", hash("Jacob"));
    printf("Natalie=> %d\n", hash("Natalie"));
    printf("Sara=> %d\n", hash("Sara"));
    printf("Mpho=> %d\n", hash("Mpho"));
    printf("Tebogo=> %d\n", hash("Tebogo"));
    printf("Ron=> %d\n", hash("Ron"));
    printf("Jane=> %d\n", hash("Jane"));
    printf("Maren=> %d\n", hash("Maren"));
    printf("Bill=> %d\n", hash("Bill"));

    init_hash_table();
    display_hash_table();


    return 0;

    
}
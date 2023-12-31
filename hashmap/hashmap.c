//Implementation of a hash table without collision handling
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[256];
    int age;
    
}person;

person * hash_table[10];

int hash(char *name){
    int length = strlen(name);
    int hashnum = 0;

    for(int i=0; i<length; i++){
        hashnum += name[i];
    }

    hashnum = hashnum%10;
    return hashnum;
}

void init_hash_table(){
    for(int i=0; i<10; i++){
        hash_table[i] = NULL;
    }
}

void display_hash_table(){
    printf("START!\n");
    for(int i=0; i<10; i++){
        printf("%d    ", i);
        if(hash_table[i]->name == NULL){
            printf("----\n");
        }else{
            printf("%s\n", hash_table[i]->name);
        }
    }
    printf("END!\n");
}

bool insert(person * person){
    int index = hash(person->name);
    if(hash_table[index] == NULL){
        hash_table[index] = person;
        return true;
    }else{
        return false;
    }
}

//assuming name is unique for every single person and treating it as a key
person* search(char * name){
    int index = hash(name); 
    if(hash_table[index] == NULL){
        return NULL;
    }else if(strcmp(hash_table[index]->name, name) == 0){
        return hash_table[index];
    }else{
        return NULL;
    }
}

person* delete(char * name){
    int index = hash(name);
    if(hash_table[index] == NULL){
        return NULL;
    }else if(strcmp(hash_table[index]->name, name) == 0){
        person* temp = hash_table[index];
        hash_table[index] = NULL;
        return temp;
    }else{
        return NULL;
    }
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

    //insert Jacob, Bill, Ron
    person jacob = {"Jacob", 28};
    person bill = {"Bill", 18};
    person ron = {"Ron", 30};
    insert(&jacob);
    insert(&bill);
    insert(&ron);
    display_hash_table();

    //search Jacob
    if(search("Jacob") == NULL){
        printf("Jacob not found\n");
    }else{
        printf("Jacob found\n");
    }

    //search Jane
    if(search("Jane") == NULL){
        printf("Jane not found\n");
    }else{
        printf("Jane found\n");
    }

    //delete Jane
    if(delete("Jane") == NULL){
        printf("Jane not found\n");
    }else{
        printf("Jane deleted\n");
    }

    //delete Jacob
    if(delete("Jacob") == NULL){
        printf("Jacob not found\n");
    }else{
        printf("Jacob deleted\n");
    }

    display_hash_table();

    return 0;

    
}
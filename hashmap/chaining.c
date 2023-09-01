#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct person
{
    char name[256];
    int age;
    struct person *next;
} person;

person *hash_table[10];

int hash(char *name)
{
    int length = strlen(name);
    int hashnum = 0;

    for (int i = 0; i < length; i++)
    {
        hashnum += name[i];
    }

    hashnum = hashnum % 10;
    return hashnum;
}

void init_hash_table()
{
    for (int i = 0; i < 10; i++)
    {
        hash_table[i] = NULL;
    }
}

void display_hash_table()
{
    printf("START!\n");
    for (int i = 0; i < 10; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("%d   ----\n", i);
        }
        else
        {
            person *ptr = hash_table[i];
            printf("%d   ", i);
            while (ptr->next != NULL)
            {
                printf("%s-> ", ptr->name);
                ptr = ptr->next;
            }
            printf("%s-> \n", ptr->name);
        }
    }
    printf("END!\n");
}

bool insert(person *new_person)
{
    int index = hash(new_person->name);
    if (hash_table[index] == NULL)
    {
        hash_table[index] = new_person;
        return true;
    }
    else
    {
        person *ptr = hash_table[index];
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_person;
        return true;
    }
}

// assuming name is unique for every single person and treating it as a key
person *search(char *name)
{
    int index = hash(name);
    if (hash_table[index] == NULL)
    {
        return NULL;
    }
    else
    {
        person *ptr = hash_table[index];
        while (ptr->next != NULL)
        {
            if (strcmp(ptr->name, name) == 0)
            {
                break;
            }
            ptr = ptr->next;
        }
        if (strcmp(ptr->name, name) == 0)
        {
            return ptr;
        }
        else
        {
            return NULL;
        }
    }
}

// some problem is there in this delete function that I have to fix
person *delete(char *name)
{
    int index = hash(name);
    if (hash_table[index] == NULL)
    {
        return NULL;
    }
    else
    {
        person *ptr = hash_table[index];
        while (strcmp(ptr->name, name) != 0 && ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        // Not found
        if (ptr->next == NULL && strcmp(ptr->name, name) != 0)
        {
            return NULL;
        }
        // Found and deleting
        if (ptr = hash_table[index])
        {
            hash_table[index] = ptr->next;
            return ptr;
        }
        else if (ptr->next == NULL)
        {
            person *temp = ptr;
            ptr = hash_table[index];
            while (ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = NULL;
            return temp;
        }
        else
        {
            person *temp = hash_table[index];
            while (temp->next != ptr)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            return ptr;
        }
    }
}

int main()
{

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

    // insert Jacob, Bill, Ron
    person jacob = {"Jacob", 28, NULL};
    person bill = {"Bill", 18, NULL};
    person ron = {"Ron", 30, NULL};
    person natalie = {"Natalie", 18, NULL};
    person sara = {"Sara", 25, NULL};
    person mpho = {"Mpho", 32, NULL};
    person tebogo = {"Tebogo", 45, NULL};
    person jane = {"Jane", 30, NULL};
    person maren = {"Maren", 50, NULL};

    insert(&jacob);
    insert(&bill);
    insert(&ron);
    insert(&natalie);
    insert(&sara);
    insert(&mpho);
    insert(&tebogo);
    insert(&jane);
    insert(&maren);

    display_hash_table();

    // search Jacob
    if (search("Jacob") == NULL)
    {
        printf("Jacob not found\n");
    }
    else
    {
        printf("Jacob found\n");
    }

    // search Jane
    if (search("Jane") == NULL)
    {
        printf("Jane not found\n");
    }
    else
    {
        printf("Jane found\n");
    }

    // delete Jane
    if (delete ("Jane") == NULL)
    {
        printf("Jane not found\n");
    }
    else
    {
        printf("Jane deleted\n");
    }

    // delete Jacob
    if (delete ("Jacob") == NULL)
    {
        printf("Jacob not found\n");
    }
    else
    {
        printf("Jacob deleted\n");
    }

    display_hash_table();

    return 0;
}
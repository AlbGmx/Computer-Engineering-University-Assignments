#include <stdio.h>

const char **menu = NULL;

void populateMenu(){
    static const char *items[] = {
        "New item A",
        "New item B",
        NULL
    };
    menu = items;
}

int menuLen(const char **menu){
    int len = 0;
    if(!menu) return 0;
    while(*menu++)
        ++len;
    return len;
}

int main(int argc, const char * argv[]){
    // 1. print inicial menu

    int menuAlen = menuLen(menu);
    int i;
    for(i = 0; i < menuAlen; i++){
        printf("%s\n", menu[i]);
    }

    // 2. populate the menu
    populateMenu();

    // 3. print it again with new values
    int menuBlen = menuLen(menu);
    for(i = 0; i < menuBlen; i++){
        printf("%s\n", menu[i]);
    }

    return 0;
}
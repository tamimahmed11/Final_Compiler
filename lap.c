#include <stdio.h>
#include<string.h>

int main() {
    char str[100];
    // Take the input from the user
    scanf("%s",&str);
    int len = strlen(str);
    // Check if the string starts with 'a' and ends with 'b'
    if(str[0]=='a' && str[len-1] =='b')
    {
        printf("Accepted");
    }
    else
    {
        printf("Rejected");
    }
    return 0;
}
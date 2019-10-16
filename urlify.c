#include<stdio.h> 
  
int urlify(char str[]) 
{ 
    int space_count = 0, i; 
    for (i = 0; str[i]; i++) 
        if (str[i] == ' ') 
            space_count++; 
    //printf("%d %d\n",i,space_count);
    while (str[i-1] == ' ') 
    { 
       space_count--; 
       i--; 
    } 
    //printf("%d %d\n",i,space_count);
    int new_length = i + space_count * 2 + 1 ; 
    
    int index = new_length - 1; 
    //printf("%d\n",index);

    str[index--] = '\0'; 
    //printf("%d\n",index);
    for (int j=i-1; j>=0; j--) 
    { 
        if (str[j] == ' ') 
        { 
            str[index] = '0'; 
            str[index - 1] = '2'; 
            str[index - 2] = '%'; 
            index = index - 3; 
        } 
        else
        { 
            str[index] = str[j]; 
            index--; 
        } 
    } 
    //printf("%d\n",index);
    return new_length; 
} 
  
int main() 
{ 
    char str[50];
    fgets(str,50,stdin);
  
    int new_length = urlify(str); 
    for (int i=0; i<new_length; i++) 
        printf("%c", str[i]); 
    return 0; 
} 

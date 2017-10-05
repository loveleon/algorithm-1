#include <stdio.h>
#include <string.h>

void main()
{
    char* p="111";
    char name[20]="ABCDEFGHIJKLMNOPQRS";
    strcpy(name, p); //name¸Ä±äÎª"how are you ? OPQRS " ====>´íÎó£
    int i = 0;
    printf("the name 7 is:%c.\n", 0x00);
    printf("the name is:");
    for (i = 0; i < sizeof(name); i++)
    {
        printf("%x", name[i]); //how\0EFGHIJKLMNOPQRS
    }
    printf("\n");

    char name11[20]="ABCDEFGHIJKLMNOPQRS";
    strncpy(name11, p, sizeof(name11)); //name¸Ä±äÎª"how are you ? " ====>ÕıÈ·£¡
    printf("the name11 is:");
    for (i = 0; i < sizeof(name11); i++)
    {
        printf("%x", name11[i]); //how\0
    }
    printf("\n");

//*************************************************
    char* p22="111";
    char name23[20] = {0};
    strcpy(name23, p22); 
    printf("the name23 is:");
    for (i = 0; i < sizeof(name23); i++)
    {
        printf("%x", name23[i]); //how\0
    }
    printf("\n");
    

    char name24[20] = {0};
    strncpy(name24, p22, sizeof(name24)); //name¸Ä±äÎª"how are you ? " ====>ÕıÈ·£¡
    printf("the name24 is:");
    for (i = 0; i < sizeof(name24); i++)
    {
        printf("%x", name24[i]); //how\0
    }
    printf("\n");


//***************************************************
    printf("the blow is dangerous!!!!!!\n");

    char* p44="012345678912";

    char name44[10] = {0};
    strncpy(name44, p44, sizeof(name44)); //name¸Ä±äÎª"how are you ? " ====>ÕıÈ·£¡
    printf("the name44 is in 0x traversally:");
    for (i = 0; i < sizeof(name44); i++)
    {
        printf("%x", name44[i]); //how\0
    }
    printf("\n");
    printf("the name44 is:%s.\n", name44); 


    char name45[10] = {0};
    strcpy(name45, p44); 
    printf("the name45 is in 0x traversally:");
    for (i = 0; i < sizeof(name45); i++)
    {
        printf("%x", name45[i]); //how\0
    }
    printf("\n");
    printf("buffer overflow!!the name45 is:%s.\n", name45); //buffer overflow

    char name46[10] = {0};
    strncpy(name46, p44, sizeof(name46)); //name¸Ä±äÎª"how are you ? " ====>ÕıÈ·£¡
    printf("the name46 is in ox traversally:");
    for (i = 0; i < sizeof(name46); i++)
    {
        printf("%x", name46[i]); //how\0
    }
    printf("\n");
    printf("the name46 is:%s.\n", name46); //
}

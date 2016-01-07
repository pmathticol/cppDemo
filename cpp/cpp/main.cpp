//
//  main.cpp
//  cpp
//
//  Created by 潘志舟 on 16/1/8.
//  Copyright © 2016年 pmathticol. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//先遍历一遍，将遇到的数字先用str2指针变量保存，同时j自增。再从头遍历一遍，将遇到的字母从*(str2+j)位置开始保存字母，最后打印出str2指向的字符串
void change(char *str1,char *str2)
{
    int j=0;
    char *temp=str1;
    while(*temp!='\0'){
        if(*temp>='0'&&*temp<='9'){
            *(str2+j)=(*temp);
            j++;
        }
        temp++;
    }
    
    temp=str1;
    
    while(*temp!='\0'){
        if((*temp>='a'&&*temp<='z')||(*temp>='A'&&*temp<='Z')){
            *(str2+j)=(*temp);
            j++;
        }
        temp++;
    }
    *(str2+j)='\0';
    
    puts(str2);
}

int main()
{   char str1[]="hell123df";
    char str2[100]={'\0'};
    //printf("请输入一行字符串:");
    //gets(str1);
    change(str1,str2);
    //	system("pause");
    
}
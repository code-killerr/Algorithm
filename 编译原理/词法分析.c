#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char *Key[10] = {"main","void","int","char","printf","scanf","else","if","return"}; //关键字
char Word[20],ch;  //存储数据(句子)
int IsAlpha(char c){ //判断是否字母
    if(((c <= 'z')&&(c >= 'a'))||((c >= 'A'&&c <= 'Z'))) return 1;
    else return 0;
}

int IsNum(char c){
    if(c >= '0' && c <= '9')return 1;
    else return 0;
}

int IsKey(char *Word){ //判断关键字
    int m,i;
    for(i = 0;i < 9;i ++){
        if((m = strcmp(Word,Key[i])) == 0)
        {
            if(i == 0) //判断是否main函数
                return 2;
            return 1;     //判断是否关键字
        }
    }
    return 0;  //不是关键字
}

void scanner（FILE*fp）{
    char Word[20] = {'\0'};
    char ch;
    int i,c;
    ch = fgetc(fp);
    if(IsAlpha(ch)){ //判断读入字符类型是否字母
        Word[0] = ch;
        ch = fgetc(fp);
        i = 1;
        while(IsNum(ch)||IsAlpha(ch)){ //判断再次读入的是字母或数字而不是符号
            Word[i] = ch;
            i++;
            ch = fgetc(fp);
        }
        word[i] = '\0';//当前字段结束为一个词
        fseek(fp,-1,1) //回退到'\0'之前
        c = IsKey(Word);
        if(c == 0)printf("%s\t$普通标识符\n\n",Word);
        else if(c == 2) printf("%s\t$主函数\n\n",Word);
        else printf("%s\t$关键字\n\n",Word);
    }
    else if(IsNum(ch)){
        Word[0] = ch;
        ch = fgetc(fp);
        i = 1;
        while(IsNum(ch)){
            Word[i] = ch;
            i ++;
            ch = fgetc(fp);
        }
        Word[i] = '\0';
        fseek(fp,-1,1);
        printf("%s\t$无符号实数\n\n",Word);
    }
    else{
        Word[0] = ch;
        switch(ch){
            case'[':
            case']':
            case'(':
            case')':

        }
    }
}


int main(){
    return 0;
}

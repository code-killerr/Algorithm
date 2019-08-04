#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int sum = 0,start = 0,sign = 0,totle = 0;
struct ccsp1
{
    char name;
    int num;
    struct ccsp1 *point[100];
    struct ccsp1 *next;
};
ccsp1* creat(char pointname,int num){
    struct ccsp1 *point;
    point = (struct ccsp1 *)malloc(sizeof(struct ccsp1));
    point ->name = pointname;
    point->num = num;
    return point;
}
void search(ccsp1* head,int ban1,int ban2,int ban3,int ban4,int s,int c,int pp){
    struct ccsp1 *p,*q;
    int flag = 0,sign = 0;
    p = head;
    if(p ->name =='C'&&c<2){
        c += 1;
        flag = 1;
    }
    else if(p ->name =='S'&&s<1) {
        s += 1;
        flag = 1;
    }
    else if(p ->name =='P'&&pp<1) {
        pp += 1;
        flag = 1;
    }
    sign = 0;
    if(c == 2&&s ==1 &&pp==1){
        if(p->num > start){
            for(int i = 0;p->point[i]!=NULL;i++){
                cout <<p->point[i]->num<<" "<<ban3<<ban2<<ban1<<endl;
                if(p->point[i]->num == ban3)
                    q = p->point[i];
                else if(p->point[i]->num == ban2){
                    totle+=1;
                    break;
                }
                else if(p->point[i]->num == ban1){
                    for(int j = 0;p->point[j]!=NULL;j++)
                        if(p->point[j]->num == ban2){
                            totle+=1;
                            sign = 0;
                        }else sign = 1;
                        break;
                    }

                }
                if(sign){
                    cout <<"bbb";
                    for(int i = 0;q->point[i]!=NULL;i++)
                        if(p->point[i]->num == ban1)
                            sum+=1;
                }
        }


        flag = 0;
    }
    if(flag){
        for(int i = 0;p->point[i]!=NULL;i++){
            cout<<p->num<<" "<<p->point[i]->num<<" "<<s<<" "<<c<<" "<<pp<<endl;
            if(p->point[i]->num!=ban1&&p->point[i]->num!=ban2&&p->point[i]->num!=ban3&&p->point[i]->num!=ban4)
                {
                    if(ban1 == 0)
                        search(p->point[i],p->num,ban2,ban3,ban4,s,c,pp);
                    else if(ban2 == 0)
                        search(p->point[i],ban1,p->num,ban3,ban4,s,c,pp);
                    else if(ban3 == 0)
                        search(p->point[i],ban1,ban2,p->num,ban4,s,c,pp);
                    else if(ban4 == 0)
                        search(p->point[i],ban1,ban2,ban3,p->num,s,c,pp);
                }
        }
    }
    else return;

}
int main(){
    int n,m,ui,vj,t,uip = 0,vjp = 0;
    char *pointdata;
    struct ccsp1 *head = NULL,*q = NULL,*p=NULL,*fvj =NULL,*fui = NULL;
    cin >> n >>m;
    pointdata = new char[n];
    cin >> pointdata;
    head = creat(pointdata[0],1);
    p = head;
    for(int i = 1;i<n;i++){
        q = creat(pointdata[i],i+1);
        p->next = q;
        p = q;
    }
    for(int i = 0;i<m;i++){//点位记录
        cin >> ui >> vj;
        if(ui>vj){
            t = ui;
            ui = vj;
            vj =t;
        }//判断ui是否大于vj,大于则转换作为单向链表//必须为双向
        p = head;
        fvj = NULL;
        uip = 0;
        while(p != NULL)
        {
            if(p->num == vj){
                fvj = p;//如果遇到vj进行记录地址
                for(int k=0;k<100;k++)
                    if(p->point[k] == NULL){
                        vjp = k;//记录空余连接点位置
                        break;
                        }
            }
            if(p->num == ui){//遇到ui记录空余边
                fui = p;//记录位置地址
                for(int k=0;k<100;k++)
                    if(p->point[k] == NULL){
                        uip = k;//记录空余连接点位置
                        break;
                        }
            }
            if(fui == NULL||fvj == NULL)
                p = p->next;
            else{
                fui ->point[uip] = fvj;
                fvj ->point[vjp] = fui;
                p = NULL;
            }
        }
    }//点位记录完成
    //搜索阶段
    p = head;
    for(int i=0;p!=NULL;i++){
        start = p->num;
        sign = 1;
        search(p,0,0,0,0,0,0,0);
        p = p->next;
    }
    sum += totle/2;
    cout << sum<<endl;
    return 0;
}

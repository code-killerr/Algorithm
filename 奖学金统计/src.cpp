#include<stdio.h>
#include<string.h>
int main(){
	int num = 0,fGrade = 0,cGrade = 0,paper = 0,sumPrize = 0,i,j;
	char name[20] = {0},hName[20] = {0},cadre = 0,sport = 0,nchar = 0;
	int prize = 0,hPrize = 0;
	scanf("%d",&num);
	for(i = 0;i < num;i++){
	    prize = 0;
		scanf("%s %d %d %c %c %d",name,&fGrade,&cGrade,&cadre,&sport,&paper);
		if(fGrade > 80&&paper > 0){
			sumPrize +=8000;
			prize += 8000;
			}
		if(fGrade > 85&&cGrade > 80){
			sumPrize += 4000;
			prize += 4000;
		}
		if(fGrade > 90){
			sumPrize += 2000;
			prize += 2000;
		}
		if(fGrade > 85&&sport == 'Y')
		{
			sumPrize += 1000;
			prize += 1000;
		}
		if(cGrade > 80&&cadre == 'Y'){
			sumPrize += 850;
			prize += 850;
		}
		if(hPrize < prize){
			hPrize = prize;
			strcpy(hName,name);
		}
	}
	printf("%s\n%d\n%d",hName,hPrize,sumPrize);
	printf("\n");
	return 0;
}

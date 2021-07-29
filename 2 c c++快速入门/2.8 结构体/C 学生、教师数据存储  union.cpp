#include<stdio.h>
#include<string.h>

struct person {
    int num;
    char name[10];
    char sex;
    char job;//s或t
    union {
        int clas;//改名，class是cpp关键字
        char position[10];
    }category;
};

int main(){
    struct person per[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %s %c %c",&per[i].num,per[i].name,&per[i].sex,&per[i].job);
    if(per[i].job=='s')
        scanf("%d",&per[i].category.clas);
    if(per[i].job=='t')
        scanf("%s",per[i].category.position);
    }

    for(int i=0;i<n;i++){
        printf("%d %s %c %c",per[i].num,per[i].name,per[i].sex,per[i].job);
    if(per[i].job=='s')
        printf(" %d\n",per[i].category.clas);
    if(per[i].job=='t')
        printf(" %s\n",per[i].category.position);
    }

    return 0;

}

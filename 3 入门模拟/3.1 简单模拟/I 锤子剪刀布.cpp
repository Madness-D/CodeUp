/*
C代表“锤子”、J代表“剪刀”、B代表“布”
*/

#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    int a[3]={0};//记录甲获胜情况，乙的直接由此计算
    int aa[3]={0},bb[3]={0};//记录获胜手势
    char aF,bF;
    for(int i=0;i<N;i++){
        //scanf会将空格作为字符输入
        cin >> aF >> bF;
        //scanf("%c %c", &aF, &bF);
        if(aF==bF){a[1]++;}
        if(aF=='C' && bF=='J'){
            aa[0]++;a[0]++;
        }
        if(aF=='J'&&bF=='B'){
            a[0]++;aa[1]++;
        }
        if(aF=='B'&&bF=='C'){
            a[0]++;aa[2]++;
        }
        if(bF=='C' && aF=='J'){
            bb[0]++;a[2]++;
        }
        if(bF=='J'&&aF=='B'){
            a[2]++;bb[1]++;
        }
        if(bF=='B'&&aF=='C'){
            a[2]++;bb[2]++;
        }
    }
    printf("%d %d %d\n",a[0],a[1],a[2]);
    printf("%d %d %d\n",a[2],a[1],a[0]);
    int AmaxFlag,BmaxFlag;
    if(aa[1]>=aa[2]&&aa[1]>=aa[0]){AmaxFlag=1;}
    if(aa[0]>=aa[1]&&aa[0]>=aa[2]){AmaxFlag=0;}
    if(aa[2]>=aa[0]&&aa[2]>=aa[1]){AmaxFlag=2;}
    if(bb[1]>=bb[2]&&bb[1]>=bb[0]){BmaxFlag=1;}
    if(bb[0]>=bb[1]&&bb[0]>=bb[2]){BmaxFlag=0;}
    if(bb[2]>=bb[0]&&bb[2]>=bb[1]){BmaxFlag=2;}
    char str[4]="CJB";
    printf("%c %c\n",str[AmaxFlag],str[BmaxFlag]);
    return 0;
}
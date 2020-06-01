#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double kai(double a1, double a2, double b1, double b2);

int main()
{
    srand(time(NULL));
    double a1, a2, b1, b2, k;
    a1 = rand() % 1000 +1;
    a2 = rand() % 1000 +1;
    b1 = rand() % 1000 +1;
    b2 = rand() % 1000 +1;
    printf("%lf\n%lf\n%lf\n%lf\n", a1, a2, b1, b2); 
    //乱数によりデータ決定
    //k = kai(a1, a2, b1, b2);
    
    //自分でデータ数を決定した(1%では棄却されないが5%で棄却される場合)
    //k = kai(435, 165, 265, 135);
    //自分でデータ数を決定した(5%で棄却されない場合)
    k = kai(304, 98, 574, 200);
    
    //自由度1より3.84と6.63を設定
    printf("%lf\n", k);
    if(k < 3.84){
        printf("not rejected at 5%%");
    }
    else if(3.83 < k && k < 6.63){
        printf("rejected at 5%%, but not rejected at 1%%");
    }
    else{
        printf("rejected at 1%%");
    }

}

//a1a2はF店のおにぎり，お茶
//b1b2はS店のおにぎり，お茶
double kai(double a1, double a2, double b1, double b2){
    double kitai_a1 = (a1+a2) * (a1+b1) / (a1+a2+b1+b2);
    double kitai_a2 = (a1+a2) * (a2+b2) / (a1+a2+b1+b2);
    double kitai_b1 = (b1+b2) * (a1+b1) / (a1+a2+b1+b2);
    double kitai_b2 = (b1+b2) * (a2+b2) / (a1+a2+b1+b2);

    double sum = (a1 - kitai_a1)*(a1 - kitai_a1)/kitai_a1 + (a2 - kitai_a2)*(a2 - kitai_a2)/kitai_a2 
    + (b1 - kitai_b1)*(b1 - kitai_b1)/kitai_b1 + (b2 - kitai_b2)*(b2 - kitai_b2)/kitai_b2;
    return sum;
}
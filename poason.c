#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 100  //Nは事象の数
#define P 0.02    //Pは確率(N＊P=λ)
#define K 3     //成功回数
#define NN 100  //シミュレーション回数


int main(void)
{
    int success_count=0;
    int i, count;
    double success;

    FILE *fp;
        fp = fopen("poason.dat", "w");
    if( fp == NULL ) {
        perror("ファイルの読み込みに失敗！\n");
        return 1;
        }


    
    srand(time(NULL));

    for(int j=1; j <= NN;  j++)
    {

        
        success = count = 0;

        
        
        for (i = 0;i <= N;i++) {
            success = (double)rand()/RAND_MAX;
            if(success <= P){
                count++;
            }
        }

        if(count==K){
            success_count++;
        }
        fprintf(fp, "%i\t", j);
        fprintf(fp, "%lf\n", (double)success_count/j);

    }
        
    

    fclose(fp);

    
	
	return 0;
}
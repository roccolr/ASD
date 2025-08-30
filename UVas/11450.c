#include <stdio.h>
#include <string.h>
#define INF 50000

int M, C, price[25][25];
int memo[210][25];

int max(int, int);
int shop(int, int);

int max(int a, int b){
    return a>b? a:b;
}

int main(){
    int i, j, TC, score;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d %d", &M, &C);
        for(i=0; i<C; i++){
            scanf("%d", &price[i][0]);
            for(j=1; j<=price[i][0]; j++){
                scanf("%d", &price[i][j]);
            }
        }
        
        memset(memo, -1, sizeof(memo));
        
        score = shop(M, 0);
        if(score<0) printf("no solutions\n");
        else printf("%d\n", score);
    }
    return 0;
}

int shop(int money, int g){
    if(money<0) return -INF;
    if(g == C) return M-money;
    if(memo[money][g] != -1) return memo[money][g];

    int ans = -1;
    for (int model = 1; model<= price[g][0]; model++) ans = max(ans, shop(money-price[g][model], g+1));
    return memo[money][g] = ans;
}
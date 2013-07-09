#include <stdio.h>
int n,i,j,s[100000];
int main(){
    while(scanf("%d", &n) != EOF && n!=0){
        for(i=0;i<n;i++)
            scanf("%d", &s[i]);
        for(j=0;j<n;j++){
            if(s[s[j]-1] != j+1)
            {
                break;
            }
        }
        if(j==n)
            printf("ambiguous\n");
        else
            printf("not ambiguous\n");
    }
    return 0;
}

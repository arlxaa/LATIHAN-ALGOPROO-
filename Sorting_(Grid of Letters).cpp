#include <stdio.h>
#include <string.h>

int main (){
    int row, col;
    char s[220][220];
    char tempStr[220]; 
    char t;            

    scanf("%d %d", &row, &col); 
    getchar();

    for (int i = 0 ; i < row; i++){
        scanf("%s", s[i]);
        
        for (int j = 0; j < col - 1; j++){       
            for (int k = 0; k < col - j - 1; k++){ 
                if(s[i][k] > s[i][k+1]){
                    t = s[i][k];
                    s[i][k] = s[i][k+1];
                    s[i][k+1] = t;
                }
            }
        }
    }
    
    for (int i = 0; i < row - 1 ; i++){          
        for (int j = 0; j < row - i - 1; j++) {    
            if(strcmp(s[j], s[j+1]) < 0){
                strcpy(tempStr, s[j]);
                strcpy(s[j], s[j+1]);
                strcpy(s[j+1], tempStr);
            }
        }
    }
    
    for (int i = 0 ; i < row ; i++){
        printf("%s\n", s[i]);
    }

    return 0;
}

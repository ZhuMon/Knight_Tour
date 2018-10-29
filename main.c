//
//  hw2.c
//  dshw2
//
//  Created by 林郁翔 on 2017/11/1.
//  Copyright © 2017年 林郁翔. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

void magic(int n){
    int i, j, m, z, v;  //z,v -> for loop
    int board[n][n];
    
    //(a) clear board[][]
    for(i = 0; i < n;i++){
        for(j = 0; j < n; j++){
            board[i][j] = 0;
        }
    }
    //(a)
    
    //ktmove
    int ktmove1[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int ktmove2[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    //ktmove
    
    //(b)  set starting position
    board[0][0] = 1;
    //(b)
    
    int nexti[8], nextj[8], npos, l, k;
    
    i = 0;
    j = 0;
    for(z = 0; z < 8; z++){   //clear nexti, nextj
        nexti[z] = 0;
        nextj[z] = 0;
    }
    
    //(c)  Loop
    for(m = 2; m <= n*n; m++){
        
        int nnx[8][8];           //next next step x's position
        int nny[8][8];           //next next step y's position
        int nnpos[8];            //next next step's posibility
        
        for(z = 0; z < 8; z++){   //clear nexti, nextj, nnx, nny, nnpos
            for (v = 0; v < 8; v++) {
                nexti[v] = 0;
                nextj[v] = 0;
                nnx[y][v] = 0;
                nny[y][v] = 0;
                nnpos[v] = 0;
                
            }
        }
        
        //(d)  form a set of possible next squares
        npos = 0;
        for(k = 0, l = 0; k < 8; k++){
            nexti[l] = i + ktmove1[k];
            nextj[l] = j + ktmove2[k];
            if(    nexti[l] >= 0 && nexti[l] <= n-1
               && nextj[l] >= 0 && nextj[l] <= n-1
               && board[nexti[l]][nextj[l]] == 0 ){
                npos++;
                l++;      
            }
            else{
                nexti[l] = 0;  //determine fault, so return original
                nextj[l] = 0;
            }
        }
        //(d)
        
        //(e)   test special cases
        int min;
        if(npos == 0){
            printf("no solution\n");
            goto noA;               //premature end
        }
        else if(npos == 1){
            min = 0;
            goto stepG;
        }
        //(e)
        //(f)   find next square with minimum number of exits
        for(l = 0; l < npos; l++){
            for(k = 0; k < 8; k++){
                nnx[l][k] = nexti[l] + ktmove1[k];
                nny[l][k] = nextj[l] + ktmove2[k];
                if(   nnx[l][k] >= 0 && nnx[l][k] <= n-1
                   && nny[l][k] >= 0 && nny[l][k] <= n-1
                   && board[nnx[l][k]][nny[l][k]] == 0 ){
                    nnpos[l]++;
                }
            }
        }
        int p;
        min = 0;
        for(p = 0; p < npos - 1; p++){    //find which is smaller
            if(nnpos[min] > nnpos[p+1]){
                min = p + 1;
            }
        }
        // (g)  move knight
    stepG:{
        i = nexti[min];
        j = nextj[min];
        board[i][j] = m;
    }
        // (g)
    }
    // (h)
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%3d ", board[i][j]);
        }
        printf("\n");
    }
    // (h)
noA:;  //if no solution, don't print array.
}
int main(void){
    int N;
    for(N = 1; N <= 8; N++){
        printf("%d.\n",N);
        magic(N);
        printf("\n\n");
    }
    return 0;
}



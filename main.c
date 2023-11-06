#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>

int matrixcomparisonv(int bl [3][3], int br[3][3]) {
    int allresult = '0';
    int successivep1 = 0,successivep2 = 0;
    int z1 , y , y2 ;
    for(z1 = 0; z1 < 3; z1++){
         y2 = 0;
        for (y = 1; y < 3; y++) {
            if (bl[(y-1)][z1] == bl[y][z1]) {
                successivep1++;
                successivep2 = 0;
            } else {
                if (y < 2) {
                    y++;
                }
                if (bl[(y-1)][z1] == bl[y][z1]) {
                    successivep2++;
                    successivep1 = 0;
                }
            }

        }/*end */
        /*//////////////////*/
        if (((successivep2 - successivep1) * (successivep2 - successivep1)) < 1) {
            continue;/*stop the comparison if there is no way to have a win in [r|h|c]*/
        }
        /*////////////////*/
        if (bl[2][z1] == br[0][z1]) {
            successivep1++;
            successivep2++;
        }

        for (y2 = 1; y2 < 3; y2++) {
            if (br[(y2-1)][z1] == br[y2][z1]) {
                if(successivep2 > successivep1){
                    successivep1 = successivep2;
                }
                successivep1++;
                successivep2 = 0;
                if (((successivep2 - successivep1) * (successivep2 - successivep1)) > 15)
                    allresult = br[(y2 - 1)][z1];
            } else if (allresult == '0'){
                if (y2 < 2) {
                    y2++; /*2*/
                }
                if (br[(y2-1)][z1] == br[y2][z1]) {
                    successivep1 = 0;
                    successivep2++;
                }
                if (((successivep2 - successivep1) * (successivep2 - successivep1)) > 15)
                    allresult = br[(y2 - 1)][z1];
            }


        }/*end*/
    }
    return allresult;
}
int matrixcomparisonh(int bl [3][3], int br[3][3]) {
    int allresult = '0';
    int successivep1 = 0,successivep2 = 0;
    int z1 =0,y =0  ,y2 =0 ;
    for(z1 = 0; z1 < 3; z1++){
        y2 = 0; /* */
    /*/////////////////*/
    for (y = 1; y < 3; y++) {
        if (bl[z1][(y - 1)] == bl[z1][y]) {
            successivep1++;
            successivep2 = 0;
        } else {
            if (y < 2) {
                y++; /*2*/
            }
            successivep1 = 0;
            if (bl[z1][(y - 1)] == bl[z1][y]) {
                successivep2++;

            }
        }

    }/*/end for loop*/
    /*//////////////////*/
    if (((successivep2 - successivep1) *(successivep2 - successivep1) ) < 1) {/**/
        continue;
    }
    /*////////////////*/
    if (bl[z1][2] == br[z1][0]) {/**/
        successivep1++;
        successivep2++;
    }

    for (y2 = 1; y2 < 3; y2++) {
        if (br[z1][(y2 - 1)] == br[z1][y2]) {
           if(successivep2 > successivep1){
                successivep1 = successivep2;
            }
            successivep1++;
            successivep2 = 0;
            if (((successivep2 - successivep1) * (successivep2 - successivep1)) > 15)/**/
                allresult = br[z1][(y2 - 1)];
        } else if(allresult == '0'){/**/
            if (y2 < 2) {
                y2++; /*/2*/
            }
            if (br[z1][(y2 - 1)] == br[z1][y2]) {
                successivep1 = 0;/**/
                successivep2++;
            }
            if (((successivep2 - successivep1) * (successivep2 - successivep1)) > 15)/**/
                allresult = br[z1][(y2 - 1)];
        }


    }/*end*/
    /*exit loop if is winner*/
    if (allresult != '0')
        break;

}
    return allresult;
}
int matrixcomparisond(int bl [3][3], int br[3][3]) {
    int alllresult = '0';
    int successivep1 = 0, successivep2 = 0;
    int i , x , y = 1, j = 1;
for (i = 1; i< 3; i++,j++){
    if (bl[(i-1)][(j-1)] == bl[i][j]) {
        successivep1++;
        successivep2 = 0;
    } else {
        if (i < 2) {
            i++;
            j++;/*2*/
        }
        if (bl[(i-1)][(j-1)] == bl[i][j]) {
            successivep2++;
            successivep1 = 0;
        }
    }
     /**/
}
    if (((successivep2 - successivep1) * (successivep2 - successivep1)) < 1) {
        return '0';/*stop the comparison if there is no way to have a win in [r|h|c]*/
    }
    /*////////////////*/
    if (bl[2][2] == br[0][0]) {
        successivep1++;
        successivep2++;
    }
    for (x = 1; y < 3; y++,x++) {
        if (br[(x-1)][(y - 1)] == br[x][y]) {
            if(successivep2 > successivep1){
                successivep1 = successivep2;
            }
            successivep1++;
            successivep2 = 0;
            if (((successivep2 - successivep1) * (successivep2 - successivep1)) > 15)
                alllresult = br[(x - 1)][(y - 1)];
        } else if (alllresult=='0'){
            if (y < 2) {
                y++; /*/2*/
                x++;
            }
            if (br[(x-1)][(y - 1)] == br[x][y]) {
                successivep1 = 0;
                successivep2++;
            }
            if (((successivep2 - successivep1) * (successivep2 - successivep1)) > 15)
                alllresult = br[(x - 1)][(y - 1)];
        }


    }/*/end*/

    return alllresult;
}
int matrixcomparisondu(int bl [3][3], int br[3][3]) {
    int alllresult = '0';
    int successivep1 = 0, successivep2 = 0;
    int i , x , y = 0, j = 0;
    for (i = 2; i>=0; i--,j++){
        if (bl[i][j] == bl[(i-1)][(j+1)]) {
            successivep1++;
            successivep2 = 0;
        } else {
            if (j < 2) {
                i--;
                j++;/*2*/
            }

            if (bl[i][j] == bl[(i-1)][(j+1)]) {
                successivep2++;
                successivep1 = 0;
            }
        }

    }
    if (((successivep2 - successivep1) * (successivep2 - successivep1)) < 1) {
        return '0';/*stop the comparison if there is no way to have a win in [r|h|c]*/
    }
    /*////////////////*/
    if (bl[0][2] == br[2][0]) {
        successivep1++;
        successivep2++;
    }

    for (x = 2; x >=0 ; y++,x--) {
        if (br[x][y] == br[(x-1)][(y+1)]) {
            if(successivep2 > successivep1){
                successivep1 = successivep2;
            }
            successivep1++;
            successivep2 = 0;
            if (((successivep2 - successivep1) * (successivep2 - successivep1)) > 15)
                alllresult =
                        br[x][y];
        } else if (alllresult=='0'){
            if (y < 2) {
                y++; /*/2*/
                x--;
            }
            if (br[x][y ] == br[(x-1)][(y+1)]) {
                successivep1 = 0;
                successivep2++;
            }
            if (((successivep2 - successivep1) * (successivep2 - successivep1)) > 15)
                alllresult = br[x][y];
        }


    }/*/end*/

    return alllresult;
}
void display(int b1[3][3], int b2[3][3], int b3[3][3], int b4[3][3] ){

    int i , j , y ,l =1;
    /*arrange block numbers*/
  for(i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++,l++) {
            if((b2[i][j] - '0') <10){
                b2[i][j] = (l + '0');
            }
            if((b1[i][j] - '0') <10){
                b1[i][j] = (l + '0');
            }
            if((b4[i][j] - '0') <10){
                b4[i][j] = (l + '0');
            }
            if((b3[i][j] - '0') <10){
                b3[i][j] = (l + '0');
            }


        }
    }
    /*end*/
    /*A-B*/
    /*header B2 -B1*/
    printf("    %s      %s\n", "B2","B1");
    printf("%s\n","+-------+-------+");
    for(i = 0; i < 3; i++) {
        printf("%c ",'|');
        for (j = 0; j < 3; j++) {
        printf("%c ",b2[i][j]);
        }
        printf("%c ",'|');
        for (y = 0; y < 3; y++) {
            printf("%c ",b1[i][y]);
        }
        printf("%c\n",'|');
    }


    /*B3 - B4*/
    printf("%s\n","+-------+-------+");
    for(i = 0; i < 3; i++) {
        printf("%c ",'|');
        for (j = 0; j < 3; j++) {
            printf("%c ",b3[i][j]);
        }
        printf("%c ",'|');
        for (y = 0; y < 3; y++) {
            printf("%c ",b4[i][y]);
        }
        printf("%c\n",'|');
    }
    printf("%s\n","+-------+-------+");
    printf("    %s      %s\n", "B3","B4");
    /*exit program*/
}
void insertmove(char playerV, int block[3][3],int position ){
int x = 0, y =0;
switch(position){
    case 1: x = 0;y = 0; break;
    case 2: x = 0; y = 1; break;
    case 3: x = 0; y = 2;break;
    case 4:
        x = 1;
        y = 0;
        break;
    case 5:
        x = 1;
        y = 1;
        break;
    case 6:
        x = 1;
        y = 2;
        break;
    case 7:
        x = 2;
        y = 0;
        break;
    case 8:
        x = 2;
        y = 1;
        break;
    case 9:
        x = 2;
        y = 2;
        break;
    default:
        printf("%s","errormatchcoordonate");
        break;
}
block[x][y] = (unsigned char)playerV;


}
int gameoutcome(int  b1[3][3], int b2[3][3], int b3[3][3], int b4[3][3], int twist) {
    int allresult ;
    int rcount = 0;
    int gcount = 0;
    int result1 , result2 , result3 , result4 , result5 ;
    allresult = matrixcomparisonh(b2, b1);
   switch(twist) {
       case 0:

          if (allresult == '0') {
           allresult = matrixcomparisonv(b2, b3);
           }
           if (allresult == '0') {
               allresult = matrixcomparisond(b2, b4);/**/
           }
          if (allresult == '0') {
           allresult = matrixcomparisonv(b1, b4);
           }

          if (allresult == '0'){
           allresult = matrixcomparisondu(b3, b1);
           }
           if(allresult == '0'){
               allresult = matrixcomparisonh(b3, b4);
           }
           /*there is a winner*/
           if(allresult == 'R'){
               allresult = 'R';
           }else if(allresult == 'G'){
               allresult = 'G';
           }
           break;
       case 1:
           result1 = matrixcomparisonh(b3, b4);
           result2 = matrixcomparisonv(b2, b3);
           result3 = matrixcomparisonv(b1, b4);
           result4 = matrixcomparisond(b2, b4);
           result5 = matrixcomparisondu(b3, b1);
           if(allresult == 'R'|| result1 == 'R' ||result2 == 'R' ||  result3 == 'R' || result4 == 'R' || result5 == 'R' ){
               rcount++;
           }
           if(allresult == 'G'|| result1 == 'G' ||result2 == 'G' ||  result3 == 'G' || result4 == 'G' || result5 == 'G' ){
               gcount++;
           }
           if(rcount > 0 && gcount == 0){
               allresult = 'R';
           }else if(gcount > 0 && rcount == 0){
               allresult = 'G';
           }else if(gcount > 0 && rcount > 0){
               allresult = 'T';
           }
           break;
       default:
           printf("%s","error ouput");
           break;


   }

   return allresult;
}
void counterclockwise(int tboard[3][3] ){
 /*transpose matrix*/
int i , j ;
int temp ;
int x , left , right ;
for(i = 0; i < 3; i++){
    for (j = i; j< 3; j++){
        temp = (unsigned char)tboard[i][j];
        tboard[i][j] = tboard[j][i];
        tboard[j][i] = temp;
    }
}
/*reversal*/
for(x = 0; x < 3; x++){
    left = 0;
    right = 2;
    while(left < right){
        temp = tboard[left][x];
        tboard[left][x] = tboard[right][x];
        tboard[right][x] = temp;
        left++;
        right--;
    }
}
}
void clockwise(int tboard[3][3] ){
    int i , j = 0;
    int  temp ;
    int x , left , right  ;

    for(x = 0; x < 3; x++){
        left = 0;
        right = 2;
        while(left < right){
            temp = (unsigned char) tboard[left][x];
            tboard[left][x] = tboard[right][x];
            tboard[right][x] = (unsigned char)temp;
            left++;
            right--;
        }
    }

    /*transpose matrix*/

    for(i = 0; i < 3; i++){
        for (j = i; j< 3; j++){
            temp = (unsigned char)tboard[i][j];
            tboard[i][j] = tboard[j][i];
            tboard[j][i] = temp;
        }
    }

}

int main(int argc, char *argv[]){
FILE *fp;
int ch ;
char *filename = argv[(argc-1)];
int trackplayer = 0;
int blockplayed = 0;
int move = 0;
char player ;
int blocktwisted = 0;
char twistdirection ='0';
int outcome;
/*implement has boolean value*/
int blockassigned = 0;
int moveassigned = 0;
int blocktwistedassigned = 0;
/*int twistdirectionassign = 0;*/
/*end boolean*/

int block1[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'}};
int  block2[3][3]=  { {'1','2','3'},{'4','5','6'},{'7','8','9'}};
int block3[3][3] =  { {'1','2','3'},{'4','5','6'},{'7','8','9'}};
int block4[3][3] =  { {'1','2','3'},{'4','5','6'},{'7','8','9'}};

/*printf("%s",filename);*/
fp = fopen(filename, "r");
/*Execute programm until EOF*/
while((ch = fgetc(fp) ) != EOF) {
    ungetc(ch,fp);

    /*Define current player*/
    if ((trackplayer % 2) == 0){
        player = 'R';
    }else{
        player = 'G';
    }
    trackplayer++;
    /*Get the game record on a line*/

    while((ch = fgetc(fp) ) != '\n'){
        if( (blockassigned == 0) && isdigit(ch)){
            blockplayed = (ch - '0');
            blockassigned = 1;
        }else if((moveassigned == 0) && isdigit(ch)){
            move = (ch -'0') ;
            moveassigned = 1;
        }else if((blocktwistedassigned == 0)&& isdigit(ch)){
            blocktwisted = (ch -'0');
            blocktwistedassigned = 1;
        }else if(ch == '+'){
            twistdirection = '+';
        }
       if(ch == EOF){
           break;
       }
    }

/*end of read line*/
/*insert move by block*/
    switch(blockplayed){
        case 1:
            insertmove(player,block1,move);
            break;
        case 2:
            insertmove(player,block2,move);
            break;
        case 3:
            insertmove(player,block3,move);
            break;
        case 4:
            insertmove(player,block4,move);
            break;
        default:
            printf("error");
    }
   if ( (outcome = gameoutcome( block1, block2, block3, block4,0)) != '0'){
       display(block1, block2, block3, block4);
       switch(outcome){
           case 'R':
               printf("%s\n","Red wins!");
               break;
           case 'G':
               printf("%s\n","Green wins!");
               break;
           default:
               printf("%s\n","error");
       }
       exit(0);
   }
    /*end*/
    /*Block twisted and test for outcome*/
    /*blocktwisted = 5;*/
    switch(blocktwisted){
        case 1:
            if(twistdirection == '+'){
                counterclockwise(block1);
            }else{
                clockwise(block1);
            }
            break;
        case 2:
            if(twistdirection == '+'){
                counterclockwise(block2);
            }else{
                clockwise(block2);
            }
            break;
        case 3:
            if(twistdirection == '+'){
                counterclockwise(block3);
            }else{
                clockwise(block3);
            }
            break;
        case 4:
            if(twistdirection == '+'){
                counterclockwise(block4);
            }else{
                clockwise(block4);
            }
            break;
        default:
            printf("%s \n","errortwist");
    }
    if ( (outcome = gameoutcome( block1, block2, block3, block4,1)) != '0'){
        display(block1, block2, block3, block4);

        switch(outcome){
            case 'R':
                printf("%s\n","Red wins !");
                break;
            case 'G':
                printf("%s\n","Green wins !");
                break;
            case 'T':
                printf("%s\n","It's a tie.");
                break;
            default:
                printf("%s\n","error");
                break;
        }
        exit(0);
    }
    /*end*/
    /*reset bool value*/
    blockassigned = 0;
    moveassigned = 0;
    blocktwistedassigned = 0;
    twistdirection = '0';
    /*end reset*/
}
display(block1, block2, block3, block4);
if(trackplayer == 36){
    printf("%s\n","It's a tie.");
}
fclose(fp);
return 0;
}


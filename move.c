#include <stdio.h>
char move_value(double value);

int main(void){
    int x,y;
    char c[100];

    printf("please input x and y\n\n>>> ");
    fgets(c,sizeof(c),stdin);
    sscanf(c,"%d %d",&x,&y);

    if(x==-64) x = -63;
    if(y==64) y = 63;

    printf("x:%d y:%d\n",x,y);

    double value_ru,value_rs,value_ls,value_lu;  //右上と左下,右下と左上
    char data_ru;
    char data_rs;
    char data_lu;
    char data_ls;

    //右回転を正としたときのベクトル値計算
    value_ru = 0.7071*((double)y-(double)x)*-1;//逆転
    value_ls = 0.7071*((double)y-(double)x);   //正転
    value_rs = 0.7071*((double)y+(double)x)*-1;//逆転
    value_lu = 0.7071*((double)y+(double)x);   //正転



    printf("\nru:%f\nrs:%f\nls:%f\nlu:%f\n\n",value_ru,value_rs,value_ls,value_lu);

    data_ru = move_value(value_ru);
    data_rs = move_value(value_rs);
    data_ls = move_value(value_ls);
    data_lu = move_value(value_lu);

    printf("\n%x %x %x %x",data_ru,data_rs,data_ls,data_lu);
    
}


char  move_value(double value){
    double uv=value;
    int rate,move;
    char resulte;

    if(value<0) uv = uv*-1;
    rate = (double)uv/89.0954*100+0.5;//63.0

    printf("%d ",rate);
    
    //if(rate>100) rate = 100;
    rate = (double)rate/100.0*123.0;

    printf("%d ",rate);
    
    if(!value) move = 128;
    else if(value<0) move = 124-rate;
    else move = rate+ 132;

    printf("%d\n",move);

    resulte = (char)move;

  if(resulte == (char)0x97) printf("Yes\n");  

    return resulte;
}
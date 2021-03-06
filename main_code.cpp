#include "mbed.h"
#include "PS3.h"
DigitalIn button(USER_BUTTON);
I2C i2c(D14,D15);
Serial pc(USBTX,USBRX);
PS3 ps3 (D8,D2);


//プロトタイプ宣言
void get_data(void);
void send(char add,char data);
char move_value(int value);

//変数の初期化
int Ry;            //ジョイコン　右　y軸
int Rx;            //ジョイコン　右　x軸
int Ly;            //ジョイコン　左　y軸
int Lx;            //ジョイコン　左　x軸
int L;             //L1
int R;             //R1
int button_ue;     // ↑
int button_sita;   // ↓
int button_migi;   // →
int button_hidari; // ←

int button_maru;    // 〇
int button_sankaku; // △
int button_sikaku;  // ☐
int button_batu;    // ✕

char address_migi_ue;     //右上
char address_hidari_ue;   //左上
char address_migi_sita;   //右下
char address_hidari_sita; //左下

char data;

//main関数
int main(void){
    address_migi_ue=0x14;
    address_migi_sita = 0x16;
    address_hidari_ue=0x60;
    address_hidari_sita =0x40;
    while(true){
        get_data();
        pc.printf("m:%d L:%d R:%d Lx%d Ly%d\n",button_maru,L,R,Lx,Ly);

        //ジョイコン処理
        if(!Lx || !Ly){
            double value_ru,value_rs,value_lu,value_ls;   //右上,右下,左上,左下
            char data_ru,data_rs,data_lu,data_ls;

            if(Lx==-64) Lx = -63;
            if(Ly==64) Ly = 63;

            //右回転を正としたときのベクトル値計算
            value_ru = 0.7071*((double)Ly-(double)Lx)*-1;//逆転
            value_ls = 0.7071*((double)Ly-(double)Lx);   //正転
            value_rs = 0.7071*((double)Ly+(double)Lx)*-1;//逆転
            value_lu = 0.7071*((double)Ly+(double)Lx);   //正転

            data_ru = move_value(value_ru);
            data_rs = move_value(value_rs);
            data_lu = move_value(value_lu);
            data_ls = move_value(value_ls);

            send(address_migi_ue,data_ru);
            send(address_migi_sita,data_rs);
            send(address_hidari_sita,data_ls);
            send(address_hidari_ue,data_lu);

            wait(0.05);

            data = 0x80;
            send(address_migi_ue,data);
            send(address_migi_sita,data);
            send(address_hidari_sita,data);
            send(address_hidari_ue,data);

        }

        //●ボタン
        if(button_maru ==1){
            data = 0xff;
            send(address_migi_sita,data);
            wait(0.05);
            data = 0x80;
            send(address_migi_sita,data);
        }

        //左に旋回
        if(L==1){
            data = 0x01;
            send(address_migi_ue,data);
            send(address_migi_sita,data);
            //send(address_hidari_ue);
            //send(address_hidari_sita);

            wait(0.05);

            data = 0x80;
            send(address_migi_ue,data);
            send(address_migi_sita,data);
            //send(address_hidari_ue);
            //send(address_hidari_sita);

        }

        //右に旋回
        if(R==1){
            data = 0xff;
            send(address_migi_ue,data);
            send(address_migi_sita,data);
            //send(address_hidari_ue);
            //send(address_hidari_sita);

            wait(0.05);

            data = 0x80;
            send(address_migi_ue,data);
            send(address_migi_sita,data);
            //send(address_hidari_ue);
            //send(address_hidari_sita);
        }

    }
}

//データ取得のための関数
void get_data(void){
    //ボタン取得
    button_ue = ps3.getButtonState(ue);
    button_sita= ps3.getButtonState(sita);
    button_migi = ps3.getButtonState(migi);
    button_hidari = ps3.getButtonState(hidari);

    L = ps3.getButtonState(L1);
    R = ps3.getButtonState(R1);

    button_maru = ps3.getButtonState(maru);

    //スティックの座標取得
    Ry = ps3.getRightJoystickYaxis();
    Rx = ps3.getRightJoystickXaxis();
    Ly = ps3.getLeftJoystickYaxis();
    Lx = ps3.getLeftJoystickXaxis();
}

//I2C送信用関数
void send(char address, char data){
    wait(0.015);
    i2c.start();
    i2c.write(address);
    i2c.write(data);
    i2c.stop();
}

//取得座標から回転速度を求める関数
char  move_value(double value){
    double uv=value;
    int rate,move;
    char resulte;

    //絶対値化
    if(value<0) uv = uv*-1;

    //割合計算(小数点以下四捨五入=>整数)
    //座標の絶対値の最高値が63と64になるので小さいほうの63に合わせて割合を出す
    rate = (double)uv/89.0954*100+0.5;
    
    //64だと100%を超えるのでその調整
    //if(rate>100) rate = 100;

    //割合をもとに出力するパワーを計算(整数)
    rate = (double)rate/100.0*123.0;
    
    //正転と逆転の処理
    //引数がマイナスの時は逆転、プラスの時は正転、0の時には静止
    if(!value) move = 128;
    else if(x<0) move = 124-rate;
    else move = rate+ 132;

    //型変更
    resulte = (char)move;

    return resulte;
}
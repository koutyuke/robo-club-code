# 部活動におけるモーターの制御コード

## モーターの配置図

![](https://user-images.githubusercontent.com/75959529/137630187-3db6e2a3-9cfa-41cb-8887-9cf5d0d3379e.jpg)

###### ※正面を上としたときにモーターの正転は右回転にしています。



## モーターのパワー計算

### 警告：ベクトルと三角関数が出てきます。気分を害するかもしれないので閲覧には十分にご注意ください。

### (言ったからな、あとは知らんぞ)



### コントローラーから座標が渡されたら

##### コントローラから座標(a,b)が送られてきた場合、ロボットの移動ベクトルは次の赤のベクトルと考えられます。この際、モーターの回転方向(モーターによる移動ベクトルの)は青のベクトルと言えるでしょう。(詳細は省く)

![](https://user-images.githubusercontent.com/75959529/137630275-bd2c12b1-b8b6-4821-81b1-adfa973154c0.jpg)

##### 平行移動させて

![](https://user-images.githubusercontent.com/75959529/137630287-431be732-2e27-4d92-b6ac-652d283c9512.jpg)

##### 識別させるためy=-xのほうを①、y=xのほうを②としましょう。①と②は直角に交差します。そのため、直角三角形ができました。

### ①を考える

##### 角度がなかったので書き足します。(ついでに①だけにする。ついでついでにｘと平行な緑色の補助線を書く)

![](https://user-images.githubusercontent.com/75959529/137630316-bcb17d8f-e7d0-4147-b0d3-831d214753d5.jpg)

##### 求めたいのは①の大きさです。座標のベクトルの大きさをdとでもしておきましょうか。

![image](https://user-images.githubusercontent.com/75959529/137631093-d520f3cc-eabc-406f-b75c-809a907f34d3.png)

##### ではsin(45°-θ)って何なんでしょうか？

![image](https://user-images.githubusercontent.com/75959529/137631117-048c5485-720a-482b-b95b-bb5fc1861048.png)

##### いい感じに分解できましたね。ではsin(θ)とcos(θ)は?というと座標が出ているので三角関数の定義にのっとって作れますね。

![image](https://user-images.githubusercontent.com/75959529/137631141-cf0c02a7-fa2e-49a5-aaf6-7c9a173049a1.png)


##### こいつらを連結させます。

![image](https://user-images.githubusercontent.com/75959529/137631162-1d9b0317-2c86-4e25-bfe3-f7f1a5cb8cf9.png)

##### いい感じにきれいになりましたね。つまり座標ベクトルとの角度は関係なく、座標自体に依存して①の大きさは変化するということなんですね。



##### おもしろい



###### ※この計算結果をプログラムの一部にしています。本当はmath.hを入れて計算をしたかったのですが、処理に時間がかかってしまうのでどうにかmath.hを使わない形になるまで自分で計算しました。まじで疲れた。



### ②を考える


# 部活動におけるモーターの制御コード

## モーターの配置図

![](\image\S__3383320.jpg)

###### ※正面を上としたときにモーターの正転は右回転にしています。



## モーターのパワー計算

### 警告：ベクトルと三角関数が出てきます。気分を害するかもしれないので閲覧には十分にご注意ください。

### (言ったからな、あとは知らんぞ)



### コントローラーから座標が渡されたら

##### コントローラから座標(a,b)が送られてきた場合、次の赤のベクトルが考えられます。この際、モーターの回転方向は青のベクトルと言えるでしょう。(詳細は省く)

![](\image\S__3383321.jpg)

##### 平行移動させて

![](\image\S__3383322.jpg)

##### 識別させるためy=-xのほうを①、y=xのほうを②としましょう。①と②は直角に交差します。そのため、直角三角形ができました。

### ①を考える

##### 角度がなかったので書き足します。(ついでに①だけにする。ついでついでにｘと平行な緑色の補助線を書く)

![](\image\S__3383323.jpg)

##### 求めたいのは①の大きさです。座標のベクトルの大きさをdとでもしておきましょうか。

$$
\begin{align}
|①|&=\sin(45°-\theta)\times(座標ベクトルの大きさ)\\
&=\sin(45°-\theta)\times d\\
\end{align}
$$

##### ではsin(45°-θ)って何なんでしょうか？

$$
\begin{align}
\sin(45°-\theta)&=\sin(45°)\cos(θ)-\cos(45°)\sin(θ)

\end{align}
$$

##### いい感じに分解できましたね。ではsin(θ)とcos(θ)は?というと座標が出ているので三角関数の定義にのっとって作れますね。

$$
\begin{align}
\sin(\theta)&=\frac{a}{d}\\
\cos(\theta)&=\frac{b}{d}

\end{align}
$$



##### こいつらを連結させます。

$$
\begin{align}
|①|&=\sin(45°-\theta)\times(座標ベクトルの大きさ)\\
&=\sin(45°-\theta)\times d\\
&=\bigl\{ \sin(45°)\cos(θ)-\cos(45°)\sin(θ)\bigl\}\times d\\
&=\bigl\{\frac{\sqrt{2}}{2}\frac{b}{d}-\frac{\sqrt{2}}{2}\frac{a}{d}\bigl\}\times d\\
&=\frac{\sqrt{2}}{2}\frac{1}{d}\times d\times (b-a)\\
&=(0.7071...)\times(b-a)\\
&=(0.7071...)\times(y座標-x座標)
\end{align}
$$

##### いい感じにきれいになりましたね。つまり座標ベクトルとの角度は関係なく、座標自体に依存して①の大きさは変化するということなんですね。



##### おもしろい



###### ※この計算結果をプログラムの一部にしています。本当はmath.hを入れて計算をしたかったのですが、処理に時間がかかってしまうのでどうにかmath.hを使わない形になるまで自分で計算しました。まじで疲れた。



### ②を考える

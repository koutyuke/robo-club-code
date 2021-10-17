# 部活動におけるモーターの制御コード

## モーターの配置図

![](https://user-images.githubusercontent.com/75959529/137630187-3db6e2a3-9cfa-41cb-8887-9cf5d0d3379e.jpg)

###### ※正面を上としたときにモーターの正転は右回転にしています。



## モーターのパワー計算

### 警告：ベクトルと三角関数が出てきます。気分を害するかもしれないので閲覧には十分にご注意ください。

### (言ったからな、あとは知らんぞ)



### コントローラーから座標が渡されたら

##### コントローラから座標(a,b)が送られてきた場合、次の赤のベクトルが考えられます。この際、モーターの回転方向は青のベクトルと言えるでしょう。(詳細は省く)

![](https://user-images.githubusercontent.com/75959529/137630275-bd2c12b1-b8b6-4821-81b1-adfa973154c0.jpg)

##### 平行移動させて

![](https://user-images.githubusercontent.com/75959529/137630287-431be732-2e27-4d92-b6ac-652d283c9512.jpg)

##### 識別させるためy=-xのほうを①、y=xのほうを②としましょう。①と②は直角に交差します。そのため、直角三角形ができました。

### ①を考える

##### 角度がなかったので書き足します。(ついでに①だけにする。ついでついでにｘと平行な緑色の補助線を書く)

![](https://user-images.githubusercontent.com/75959529/137630316-bcb17d8f-e7d0-4147-b0d3-831d214753d5.jpg)

##### 求めたいのは①の大きさです。座標のベクトルの大きさをdとでもしておきましょうか。



![\begin{align}
|①|&=\sin(45°-\theta)\times(座標ベクトルの大きさ)\\
&=\sin(45°-\theta)\times d\\
\end{align}](https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+%5Cbegin%7Balign%7D%0A%26%3D%5Csin%2845-%5Ctheta%29%5Ctimes%28%29%5C%5C%0A%26%3D%5Csin%2845-%5Ctheta%29%5Ctimes+d%5C%5C%0A%5Cend%7Balign%7D)

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


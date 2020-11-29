# ofxEpometrope
このアドオンはエポメトロープ専用です。センサーから値を取得して、エポメトロープが向いている方向を返します。  
This addon is dedicated to epometrope. It takes a value from the sensor and returns the direction epometrope is facing.   

## Epometrope
エポメトロープを知らない人は<a rel="license" href="https://github.com/yutaka-miki/Epometorope" target="_blank"> こちら </a>を読んでみてください。  
If you don't know about epometrope, read about it <a rel="license" href="https://github.com/yutaka-miki/Epometorope" target="_blank"> here </a>.  
  
https://youtu.be/bQH5cyU_22U   
<img src="images/IMG_5433.gif" width="500">  

## Instaration 1 (Recommendation)
openFrameworksやofxEpometrope、そのほかエポメトロープに関連するソフトウェアが一式用意されたimgデータをmicroSDカードに直接書き込む方法です。openFrameworksのインストールやその他の設定が煩雑であるため、現状この方法を推奨しています。

#### (1)microSDカードに書き込むための、imgファイルをダウンロードします。 
  
#### (2)imgファイルを「balenaEtcher」でmicroSD（16GB以上）2枚に書き込む。（書き込み用のソフトウェアは別のソフトウェアでも代用可です）
【参考】balenaEtcherダウンロードサイト
https://www.balena.io/etcher/
  
## Instaration 2
LinuxでのopenFrameworksの使用経験があり、自身で環境を構築したいという方はこちらの方法でインストールして下さい。

#### (1)ofxEpometrope をインストール - Install ofxEpometrope
ダウンロードしたファイルを「openFrameworks/addons/」下に配置します。  
Place the downloaded file under "openFrameworks/addons/".
  
#### (2)依存ライブラリをインストール - Install required libraries 
- <a rel="license" href="http://abyz.me.uk/rpi/pigpio/download.html" target="_blank"> pigpio </a>
- <a rel="license" href="https://github.com/apparentVJ/ofxRPiTouch" target="_blank"> ofxRPiTouch </a>

## Example 
#### example-test  
openFrameworksの3DCGを使った軽量でベーシックな例。  
A lightweight and basic example using openFrameworks 3DCG.  
  
#### example-MoviePlayer  
「<a rel="license" href="https://github.com/yutaka-miki/Movie-converter-for-epometrope" target="_blank">Movie-converter-for-epometrope</a>」で作成した「専用2D映像」を再生するためのツールです。アドオンに依存せず使用することができますが、動作や設定のしやすさが若干劣るため、現在は<a rel="license" href="https://github.com/yutaka-miki/epomeOMXPlayer" target="_blank">epomeOMXPlayer</a>の使用を推奨します。
A tool to play back "Dedicated 2D video" created by "<a rel="license" href="https://github.com/yutaka-miki/Movie-converter-for-epometrope" target="_blank">Movie-converter-for-epometrope</a>".  
## Setting
「Setting」内のテキストファイルを編集することでビルドしないで一部の設定を変更することができます。  
You can change some settings without building by editing the text file in "Settings".  
#### Master_or_Slave
「0」でマスター。「1」でスレーブに切り替えられます。  
If you enter an input of "0", it will be set as a master  
and if you enter an input of "1", it will be set as a slave.  
#### GPIOPhotoReflector
フォトリフレクタの信号を受け取るピンの番号を変更できます。  
You can change the number of the pin that receives the signal from the photo-reflector.

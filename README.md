# ofxEpometrope
このアドオンはエポメトロープ専用です。センサーから値を取得して、エポメトロープが向いている方向を返します。  
This addon is dedicated to epometrope. It takes a value from the sensor and returns the direction epometrope is facing.   

## Epometrope
エポメトロープを知らない人は<a rel="license" href="https://github.com/yutaka-miki/Epometorope" target="_blank"> こちら </a>を読んでみてください。  
If you don't know about epometrope, read about it <a rel="license" href="https://github.com/yutaka-miki/Epometorope" target="_blank"> here </a>.  
  
https://youtu.be/bQH5cyU_22U   
<img src="images/IMG_5433.gif" width="500">  
  
## Instaration
#### (1)ofxEpometropeをインストール - Install ofxEpometrope
ダウンロードしたファイルを「openFrameworks/addons/」下に配置します。  
Place the downloaded file under "openFrameworks/addons/".
  
#### (2)依存ライブラリをインストール - Install required libraries 
- <a rel="license" href="http://abyz.me.uk/rpi/pigpio/download.html" target="_blank"> pigpio </a>
- <a rel="license" href="https://github.com/apparentVJ/ofxRPiTouch" target="_blank"> ofxRPiTouch </a>

## Example 
#### example-test  

#### example-MoviePlayer  


## Setting
「Setting」内のテキストファイルを編集することでビルドしないで一部の設定を変更することができます。  
You can change some settings without building by editing the text file in "Settings".  
#### Master_or_Slave
「0」でマスター。「1」でスレーブに切り替えられる。  
If you enter an input of "0", it will be set as a master  
and if you enter an input of "1", it will be set as a slave.  
#### GPIOPhotoReflector
フォトリフレクタの信号を受け取るピンの番号を変更できます。  
You can change the number of the pin that receives the signal from the photo-reflector.

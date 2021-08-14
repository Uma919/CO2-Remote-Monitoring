# CO2-Remote-Monitoring
ESP-WROOM-32開発ボードにて二酸化炭素濃度を計測してAmbientへ送信し，M5StackではAmbientからデータを取得し表示させるものです．  
本リポジトリは[オープンデータとLPWAの活用・可視化コンテスト データ活用部門](https://sites.google.com/view/opendata-lpwa/)における成果の一部を公開しております．
# デモ
二酸化炭素濃度を可視化するAmbientチャンネルは[コチラ](https://ambidata.io/bd/board.html?id=11304)
# 必要なモノ
## 制御基板や電子部品
主にスイッチサイエンスや秋月電子でご購入いただけます．
 * [M5Stack Gray（9軸IMU搭載）](https://ssci.to/3648)
 * [ESP32-DevKitC ESP-WROOM-32開発ボード](https://akizukidenshi.com/catalog/g/gM-11819/)
 * [CO2センサモジュール MH-Z19C](https://akizukidenshi.com/catalog/g/gM-16142/)
 * ユニバーサル基板・配線類
## ライブラリやフォント
ライブラリ関係
* M5Stack
* Ticker
* ArduinoJson
* MHZ19_uart
* Ambient

フォント関係
* [源真ゴシック genshin-regular-32pt.vlw](https://qiita.com/ma2shita/items/fef1608fc9cf3a7bd46a)

# 注意事項
プログラム上でWi-FiおよびAmbientの設定をご自身のものに書き換えて下さい．
```
/*Wi-Fi*/
const char* ssid = "your ssid";
const char* password = "your password";

/*Ambient*/
unsigned int channelId = your channelId;
const char* writeKey = "your writeKey";
```
また，フォントファイル「genshin-regular-32pt.vlw」はM5Stack用microSDカード直下のフォルダ「font」に保存するようにしてください．

# ライセンス
本ソフトでは表示フォントに「源真ゴシック」(http://jikasei.me/font/genshin/) を使用しています。
Licensed under SIL Open Font License 1.1 (http://scripts.sil.org/OFL)
© 2015 自家製フォント工房, © 2014, 2015 Adobe Systems Incorporated, © 2015 M+
FONTS PROJECT

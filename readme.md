﻿# LZEe - LZE enhancement for Z80 by uniabis

  LZE Original Copyright (C)1995,2008 GORRY.

  Porting for Z80 by Kei Moroboshi 2017/SEP.

 License:zlib license or original LZE license

## Description

[LZEe](https://github.com/uniabis/lzee) is file compressor/decompressor derived from [LZE](http://gorry.haun.org/pw/?lze).

LZEe is designed to be effective with fast depacking on Z80 machines.

## Usage

```
lzee e infile outfile

 pack infile to outfile without header

lzee E infile outfile

 pack infile to outfile with header

lzee d infile outfile

 unpack infile without header to outfile

lzee D infile outfile

 unpack infile with header to outfile

 header is unpacked size in big endian 32bit integer

```


## [Benchmarks](https://github.com/uniabis/z80depacker)

### Compression rate

test data:DEOCM-PLD-CV BIOS(16x16KB)

|Packer|ALL|MEGASDHC.B00|MEGASDHC.B01|MEGASDHC.B02|MEGASDHC.B03|MSX2MAIN.B00|MSX2MAIN.B01|MSXMUSIC.B00|MSX2EXT.B00|KANJJ1.B00|KANJJ1.B01|KANJJ1.B02|KANJJ1.B03|KANJJ1.B04|KANJJ1.B05|KANJJ1.B06|KANJJ1.B07|
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
|ApLib|161,438<br />(61.58%)|9,367<br />(57.17%)|4,928<br />(30.08%)|12,595<br />(76.87%)|12,340<br />(75.32%)|12,836<br />(78.34%)|13,579<br />(82.88%)|10,048<br />(61.33%)|12,361<br />(75.45%)|6,223<br />(37.98%)|4,092<br />(24.98%)|10,835<br />(66.13%)|10,643<br />(64.96%)|10,521<br />(64.22%)|10,455<br />(63.81%)|10,817<br />(66.02%)|9,798<br />(59.80%)|
|Exomizer2<br />(-P0)|160,011<br />(61.04%)|9,373<br />(57.21%)|4,902<br />(29.92%)|12,494<br />(76.26%)|12,297<br />(75.05%)|12,740<br />(77.76%)|13,402<br />(81.80%)|10,068<br />(61.45%)|12,351<br />(75.38%)|6,097<br />(37.21%)|3,975<br />(24.26%)|10,688<br />(65.23%)|10,510<br />(64.15%)|10,415<br />(63.57%)|10,348<br />(63.16%)|10,650<br />(65.00%)|9,701<br />(59.21%)|
|Exomizer3<br />(-P7)|160,007<br />(61.04%)|9,373<br />(57.21%)|4,902<br />(29.92%)|12,494<br />(76.26%)|12,297<br />(75.05%)|12,739<br />(77.75%)|13,402<br />(81.80%)|10,068<br />(61.45%)|12,351<br />(75.38%)|6,097<br />(37.21%)|3,974<br />(24.26%)|10,688<br />(65.23%)|10,509<br />(64.14%)|10,415<br />(63.57%)|10,347<br />(63.15%)|10,650<br />(65.00%)|9,701<br />(59.21%)|
|hruST<br />(oh1c)|162,217<br />(61.88%)|9,369<br />(57.18%)|4,895<br />(29.88%)|12,563<br />(76.68%)|12,282<br />(74.96%)|12,768<br />(77.93%)|13,454<br />(82.12%)|10,079<br />(61.52%)|12,331<br />(75.26%)|6,434<br />(39.27%)|4,230<br />(25.82%)|10,940<br />(66.77%)|10,753<br />(65.63%)|10,679<br />(65.18%)|10,597<br />(64.68%)|10,906<br />(66.56%)|9,937<br />(60.65%)|
|lz4<br />(lz4ultra)|191,429<br />(73.02%)|10,834<br />(66.13%)|5,796<br />(35.38%)|14,743<br />(89.98%)|14,290<br />(87.22%)|14,837<br />(90.56%)|15,448<br />(94.29%)|11,632<br />(71.00%)|14,578<br />(88.98%)|8,089<br />(49.37%)|5,431<br />(33.15%)|13,003<br />(79.36%)|12,732<br />(77.71%)|12,675<br />(77.36%)|12,535<br />(76.51%)|12,975<br />(79.19%)|11,831<br />(72.21%)|
|lz48|198,227<br />(75.62%)|10,717<br />(65.41%)|5,752<br />(35.11%)|14,588<br />(89.04%)|14,250<br />(86.98%)|14,268<br />(87.08%)|15,305<br />(93.41%)|12,121<br />(73.98%)|14,074<br />(85.90%)|8,167<br />(49.85%)|5,532<br />(33.76%)|14,290<br />(87.22%)|14,024<br />(85.60%)|13,960<br />(85.21%)|13,952<br />(85.16%)|14,179<br />(86.54%)|13,048<br />(79.64%)|
|lz49|195,027<br />(74.40%)|10,628<br />(64.87%)|5,559<br />(33.93%)|14,512<br />(88.57%)|14,030<br />(85.63%)|14,196<br />(86.65%)|15,254<br />(93.10%)|11,980<br />(73.12%)|13,969<br />(85.26%)|7,824<br />(47.75%)|5,240<br />(31.98%)|13,985<br />(85.36%)|13,761<br />(83.99%)|13,717<br />(83.72%)|13,674<br />(83.46%)|13,920<br />(84.96%)|12,778<br />(77.99%)|
|lze|174,182<br />(66.45%)|10,092<br />(61.60%)|5,463<br />(33.34%)|13,472<br />(82.23%)|13,187<br />(80.49%)|13,698<br />(83.61%)|14,389<br />(87.82%)|10,830<br />(66.10%)|13,303<br />(81.20%)|7,027<br />(42.89%)|4,664<br />(28.47%)|11,696<br />(71.39%)|11,493<br />(70.15%)|11,373<br />(69.42%)|11,283<br />(68.87%)|11,634<br />(71.01%)|10,578<br />(64.56%)|
|lzee|174,118<br />(66.42%)|10,088<br />(61.57%)|5,459<br />(33.32%)|13,468<br />(82.20%)|13,183<br />(80.46%)|13,694<br />(83.58%)|14,385<br />(87.80%)|10,826<br />(66.08%)|13,299<br />(81.17%)|7,023<br />(42.86%)|4,660<br />(28.44%)|11,692<br />(71.36%)|11,489<br />(70.12%)|11,369<br />(69.39%)|11,279<br />(68.84%)|11,630<br />(70.98%)|10,574<br />(64.54%)|
|lzsa1|182,306<br />(69.54%)|10,339<br />(63.10%)|5,392<br />(32.91%)|14,044<br />(85.72%)|13,703<br />(83.64%)|14,087<br />(85.98%)|14,892<br />(90.89%)|11,049<br />(67.44%)|13,719<br />(83.73%)|7,317<br />(44.66%)|4,805<br />(29.33%)|12,544<br />(76.56%)|12,253<br />(74.79%)|12,190<br />(74.40%)|12,075<br />(73.70%)|12,508<br />(76.34%)|11,389<br />(69.51%)|
|lzsa2|167,895<br />(64.05%)|9,684<br />(59.11%)|5,101<br />(31.13%)|13,146<br />(80.24%)|12,823<br />(78.27%)|13,307<br />(81.22%)|14,074<br />(85.90%)|10,354<br />(63.20%)|12,825<br />(78.28%)|6,457<br />(39.41%)|4,265<br />(26.03%)|11,324<br />(69.12%)|11,085<br />(67.66%)|10,976<br />(66.99%)|10,884<br />(66.43%)|11,313<br />(69.05%)|10,277<br />(62.73%)|
|megalz|167,609<br />(63.94%)|9,718<br />(59.31%)|5,124<br />(31.27%)|12,965<br />(79.13%)|12,660<br />(77.27%)|13,072<br />(79.79%)|13,917<br />(84.94%)|10,407<br />(63.52%)|12,833<br />(78.33%)|6,514<br />(39.76%)|4,320<br />(26.37%)|11,362<br />(69.35%)|11,161<br />(68.12%)|11,016<br />(67.24%)|11,012<br />(67.21%)|11,281<br />(68.85%)|10,247<br />(62.54%)|
|pletter|167,494<br />(63.89%)|9,706<br />(59.24%)|5,083<br />(31.02%)|12,945<br />(79.01%)|12,700<br />(77.51%)|13,205<br />(80.60%)|13,909<br />(84.89%)|10,466<br />(63.88%)|12,858<br />(78.48%)|6,511<br />(39.74%)|4,269<br />(26.06%)|11,340<br />(69.21%)|11,105<br />(67.78%)|10,992<br />(67.09%)|10,908<br />(66.58%)|11,252<br />(68.68%)|10,245<br />(62.53%)|
|shrinkler|153,164<br />(58.43%)|8,984<br />(54.83%)|4,680<br />(28.56%)|12,148<br />(74.15%)|11,916<br />(72.73%)|12,276<br />(74.93%)|13,100<br />(79.96%)|9,536<br />(58.20%)|11,820<br />(72.14%)|5,728<br />(34.96%)|3,700<br />(22.58%)|10,212<br />(62.33%)|10,020<br />(61.16%)|9,876<br />(60.28%)|9,808<br />(59.86%)|10,148<br />(61.94%)|9,212<br />(56.23%)|
|zx7|170,296<br />(64.96%)|9,781<br />(59.70%)|5,080<br />(31.01%)|13,104<br />(79.98%)|12,784<br />(78.03%)|13,224<br />(80.71%)|14,021<br />(85.58%)|10,515<br />(64.18%)|12,943<br />(79.00%)|6,532<br />(39.87%)|4,401<br />(26.86%)|11,623<br />(70.94%)|11,436<br />(69.80%)|11,337<br />(69.20%)|11,331<br />(69.16%)|11,612<br />(70.87%)|10,572<br />(64.53%)|
|zx7b|170,425<br />(65.01%)|9,762<br />(59.58%)|5,091<br />(31.07%)|13,103<br />(79.97%)|12,810<br />(78.19%)|13,248<br />(80.86%)|14,002<br />(85.46%)|10,495<br />(64.06%)|12,964<br />(79.13%)|6,591<br />(40.23%)|4,424<br />(27.00%)|11,629<br />(70.98%)|11,451<br />(69.89%)|11,327<br />(69.13%)|11,341<br />(69.22%)|11,601<br />(70.81%)|10,586<br />(64.61%)|
|zx7mini|190,540<br />(72.69%)|10,580<br />(64.58%)|5,702<br />(34.80%)|14,358<br />(87.63%)|14,064<br />(85.84%)|14,015<br />(85.54%)|15,267<br />(93.18%)|12,073<br />(73.69%)|13,874<br />(84.68%)|7,390<br />(45.10%)|4,921<br />(30.04%)|13,428<br />(81.96%)|13,182<br />(80.46%)|13,091<br />(79.90%)|13,039<br />(79.58%)|13,311<br />(81.24%)|12,245<br />(74.74%)|


### Decompression speed

test data:ALL(16*16KB)

|packer|unpacker|unpacker size|packed size|unpacking clocks|
|---|---|---:|---:|---:|
|ApLib|aplib156b|            156|        161,438<br />(61.58%)|     59,951,437<br />(LDIR x 9.9)|
|ApLib|aplib247b|            249|        161,438<br />(61.58%)|     35,994,335<br />(LDIR x 5.9)|
|ApLib|aplib247b_180_minimal|            152|        161,438<br />(61.58%)|     45,108,903<br />(LDIR x 7.4)|
|ApLib|aplib247b_180_small|            171|        161,438<br />(61.58%)|     34,998,599<br />(LDIR x 5.8)|
|ApLib|aplib247b_180_fast|            234|        161,438<br />(61.58%)|     33,282,031<br />(LDIR x 5.5)|
|Exomizer2|deexo|            169|        160,011<br />(61.03%)|    108,490,817<br />(LDIR x 17.9)|
|Exomizer2|deexo_180|            166|        160,011<br />(61.03%)|    108,490,229<br />(LDIR x 17.9)|
|Exomizer2|deexo_180_fast_jp|            176|        160,011<br />(61.03%)|     92,969,945<br />(LDIR x 15.4)|
|Exomizer2|deexoopt_f3_180_p0|            242|        160,011<br />(61.03%)|     74,159,660<br />(LDIR x 12.2)|
|Exomizer3|deexo3p7|            176|        160,007<br />(61.03%)|     82,034,254<br />(LDIR x 13.6)|
|Exomizer3|deexo3p7_fast_jp|            181|        160,007<br />(61.03%)|     70,324,722<br />(LDIR x 11.6)|
|Exomizer3|deexoopt_p7|            219|        160,007<br />(61.03%)|     63,745,458<br />(LDIR x 10.5)|
|Exomizer3|deexoopt_f3_p7|            212|        160,007<br />(61.03%)|     61,265,322<br />(LDIR x 10.1)|
|Exomizer3|deexoopt_f3_180_p7|            219|        160,007<br />(61.03%)|     63,774,934<br />(LDIR x 10.5)|
|hrust|dehrust_ix|            234|        162,217<br />(61.88%)|     45,520,962<br />(LDIR x 7.5)|
|hrust|dehrust_stk|            209|        162,217<br />(61.88%)|     41,277,317<br />(LDIR x 6.8)|
|lz4|lz4dec|             97|        191,429<br />(73.02%)|     10,748,650<br />(LDIR x 1.7)|
|lz4|unlz4_spke|            103|        191,429<br />(73.02%)|      9,911,253<br />(LDIR x 1.6)|
|lz4|unlz4_spke_fast|             96|        191,429<br />(73.02%)|      9,547,736<br />(LDIR x 1.5)|
|lz4|unlz4_spke_small|             65|        191,429<br />(73.02%)|     10,007,673<br />(LDIR x 1.6)|
|lz48|lz48decrunch\_v006\_|             70|        198,227<br />(75.61%)|      9,987,125<br />(LDIR x 1.6)|
|lz48|lz48decrunch_v006__180|             73|        198,227<br />(75.61%)|      9,758,783<br />(LDIR x 1.6)|
|lz49|lz49decrunch_v001|            106|        195,027<br />(74.39%)|     11,349,204<br />(LDIR x 1.8)|
|lz49|lz49decrunch_v001_180|            101|        195,027<br />(74.39%)|     11,003,843<br />(LDIR x 1.8)|
|lze|lzdec|            119|        174,182<br />(66.44%)|     21,831,226<br />(LDIR x 3.6)|
|lze|dlze_fast|             91|        174,182<br />(66.44%)|     17,123,480<br />(LDIR x 2.8)|
|lze|dlze_small|             82|        174,182<br />(66.44%)|     21,740,981<br />(LDIR x 3.6)|
|lzee|dlzee_fast|             85|        174,118<br />(66.42%)|     16,484,450<br />(LDIR x 2.7)|
|lzee|dlzee_small|             76|        174,118<br />(66.42%)|     21,101,951<br />(LDIR x 3.4)|
|lzsa1|unlzsa1_fast|            111|        182,306<br />(69.54%)|     10,243,519<br />(LDIR x 1.6)|
|lzsa1|unlzsa1_small|             67|        182,306<br />(69.54%)|     11,434,642<br />(LDIR x 1.8)|
|lzsa2|unlzsa2_fast|            216|        167,895<br />(64.04%)|     15,844,525<br />(LDIR x 2.6)|
|lzsa2|unlzsa2_fast_180|            214|        167,895<br />(64.04%)|     16,113,389<br />(LDIR x 2.6)|
|lzsa2|unlzsa2_small|            139|        167,895<br />(64.04%)|     18,039,099<br />(LDIR x 2.9)|
|lzsa2|unlzsa2_small_180|            137|        167,895<br />(64.04%)|     18,307,963<br />(LDIR x 3.0)|
|MegaLZ|megalz_dec40|            110|        167,609<br />(63.93%)|     45,653,296<br />(LDIR x 7.5)|
|MegaLZ|unmegalz_fast_v2|            233|        167,609<br />(63.93%)|     20,775,177<br />(LDIR x 3.4)|
|MegaLZ|unmegalz_small_v2|             92|        167,609<br />(63.93%)|     32,642,661<br />(LDIR x 5.4)|
|Pletter|unpletter|            170|        167,494<br />(63.89%)|     28,812,190<br />(LDIR x 4.7)|
|Pletter|unpletter_180|            169|        167,494<br />(63.89%)|     28,746,568<br />(LDIR x 4.7)|
|Shrinkler|shrinkler_recall_209|            209|        153,164<br />(58.42%)|  2,648,153,963<br />(LDIR x 439.2)|
|Shrinkler|shrinkler_recall_209_r800_rom|            209|        153,164<br />(58.42%)|  2,638,632,095<br />(LDIR x 437.6)|
|zx7|dzx7_lom_v1|            214|        170,296<br />(64.96%)|     23,446,544<br />(LDIR x 3.8)|
|zx7|dzx7_turbo|             88|        170,296<br />(64.96%)|     27,346,595<br />(LDIR x 4.5)|
|zx7|dzx7_standard|             69|        170,296<br />(64.96%)|     36,700,476<br />(LDIR x 6.0)|
|zx7b|dzx7b_fast|            191|        170,425<br />(65.01%)|     20,907,617<br />(LDIR x 3.4)|
|zx7b|dzx7b_fast_r800|            191|        170,425<br />(65.01%)|     20,907,617<br />(LDIR x 3.4)|
|zx7b|dzx7b_slow|             64|        170,425<br />(65.01%)|     33,688,687<br />(LDIR x 5.5)|
|zx7b|dzx7b_slow_r800|             64|        170,425<br />(65.01%)|     33,688,687<br />(LDIR x 5.5)|
|zx7mini|dzx7mini|             39|        190,540<br />(72.68%)|     20,556,427<br />(LDIR x 3.4)|


## Original readme

```
------------------------------------------------------------------------
lze LZSS亜種データ圧縮/展開ツール
------------------------------------------------------------------------


------------------------------------------------------------------------
■ 履歴

・20080228a
  最初のバージョン。

------------------------------------------------------------------------
■ 概要

LZSS亜種圧縮/展開アルゴリズムにより作られたデータ圧縮/展開ツールとデコー
ダです。
デコーダはアセンブラでわずか100ステップ程度で書かれており、非常に高速に
動作します。
圧縮データはzipで圧縮した場合の20～30%増程度となります。

------------------------------------------------------------------------
■ インストール方法

win32コマンドラインツールとそのソースであり、インストールは特に必要あり
ません。

------------------------------------------------------------------------
■ 使用方法

   lze.exe e infile outfile
        infileを圧縮してoutfileへ出力します。

   lze.exe d infile outfile
        圧縮済みのinfileを展開してoutfileへ出力します。

   lzed.exe infile outfile
        圧縮済みのinfileを展開してoutfileへ出力します。
        lzedec.cを使用します。

------------------------------------------------------------------------
■ ソースと歴史的経緯

   lzedec.c         Cによるデコーダ
   lzedec_8086.asm  MASM(8086)アセンブラによるデコーダ
                    入力・出力ともに１セグメント内のみ有効
   lzedec_x68k.has  has(MC68000)アセンブラによるデコーダ

デコーダの対象CPUが古いものしかないのは、歴史的理由によるものです。

lzeの圧縮方式は、TONBE氏のX68000用汎用データ圧縮プログラム「BZ.X」を元に
作られています。
TONBE氏のBZ.Xは、F&I氏のX68000用実行ファイル圧縮プログラム「lzx」を元に
作られています。
F&I氏のlzxは、Fabrice Bellard氏のMS-DOS用実行ファイル圧縮プログラム
「LZEXE」を元に作られています。
これらはいずれもソースコードが公開されておらず、リバースエンジニアリング
によって作られ、実行ファイルのみが公開されてきました。

本lzeは、当方の学習用および実務用として1995年に作られたものですが、これ
らの圧縮方式をソースコードとして残しておくために公開するものです。

------------------------------------------------------------------------
■ その他

このプログラムおよびソースコードは、一切の制限なく使用・改造・配布等を
行うことができます。

--
Hiroaki GOTO as GORRY : 後藤 浩昭
E-mail: gorry@hauN.org
Homepage: http://GORRY.hauN.org/

[EOF]
```

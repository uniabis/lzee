# LZEe - LZE enhancement for Z80 by uniabis

  LZE Original Copyright (C)1995,2008 GORRY.

  Porting for Z80 by Kei Moroboshi 2017/SEP.

 License:zlib license or original LZE license

## Description

[LZEe](https://github.com/uniabis/lzee) is file compressor/decompressor derivated from [LZE](http://gorry.haun.org/pw/?lze).

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

|SectionName|exomizer|mhmt-base|lze|lzee|megalz|pletter|shrinkler|zx7b|
|-|-|-|-|-|-|-|-|-|
|MEGASDHC.B00|9,373|9,397|10,092|10,088|9,718|9,706|8,984|9,762|
|MEGASDHC.B01|4,902|4,923|5,463|5,459|5,124|5,083|4,680|5,091|
|MEGASDHC.B02|12,494|12,592|13,472|13,468|12,965|12,945|12,148|13,103|
|MEGASDHC.B03|12,297|12,320|13,187|13,183|12,660|12,700|11,916|12,810|
|MSX2MAIN.B00|12,740|12,790|13,698|13,694|13,072|13,205|12,276|13,248|
|MSX2MAIN.B01|13,402|13,485|14,389|14,385|13,917|13,909|13,100|14,002|
|MSXMUSIC.B00|10,068|10,118|10,830|10,826|10,407|10,466|9,536|10,495|
|MSX2EXT.B00|12,351|12,370|13,303|13,299|12,833|12,858|11,820|12,964|
|KANJJ1.B00|6,097|6,454|7,027|7,023|6,514|6,511|5,728|6,591|
|KANJJ1.B01|3,975|4,241|4,664|4,660|4,320|4,269|3,700|4,424|
|KANJJ1.B02|10,688|10,960|11,696|11,692|11,362|11,340|10,212|11,629|
|KANJJ1.B03|10,510|10,765|11,493|11,489|11,161|11,105|10,020|11,451|
|KANJJ1.B04|10,415|10,708|11,373|11,369|11,016|10,992|9,876|11,327|
|KANJJ1.B05|10,348|10,610|11,283|11,279|11,012|10,908|9,808|11,341|
|KANJJ1.B06|10,650|10,934|11,634|11,630|11,281|11,252|10,148|11,601|
|KANJJ1.B07|9,701|9,953|10,578|10,574|10,247|10,245|9,212|10,586|
|ALL|160,011|162,620|174,182|174,118|167,609|167,494|153,164|170,425|


### Decompression speed


test data:ALL(16*16KB)

|packer|unpacker|unpacker size|packed size|unpacking clocks|
|-|-|-|-|-|
Exomizer|deexo.asm|            169|        160,011|    108,490,817|
Exomizer|deexo_180.asm|            168|        160,011|    108,508,513|
Exomizer|deexo_180_fast.asm|            173|        160,011|     94,297,587|
Exomizer|deexo_180_fast_jp.asm|            184|        160,011|     93,483,961|
mhmt|dehrust_ix|            234|        162,620|     45,607,398|
mhmt|dehrust_stk|            209|        162,620|     41,333,579|
lze|lzdec|            119|        174,182|     21,831,226|
lze|lzdec_104|            104|        174,182|     20,141,132|
lzee|lzee_dec|             99|        174,118|     19,608,607|
MegaLZ|megalz_dec40|            110|        167,609|     45,653,296|
Pletter|unpletter	|            170|        167,494|     28,812,190|
Pletter|unpletter_180|            169|        167,494|     28,812,318|
Shrinkler|shrinkler_recall_209|            209|        153,164|  2,648,153,963|
Shrinkler|shrinkler_recall_209_r800|            209|        153,164|  2,648,153,963|
zx7b|dzx7b_fast|            191|        170,425|     20,907,617|
zx7b|dzx7b_fast_r800|            193|        170,425|     21,155,467|
zx7b|dzx7b_slow|             64|        170,425|     33,688,687|
zx7b|dzx7b_slow_r800|             65|        170,425|     33,936,537|


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

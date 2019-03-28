# LZEe - LZE enhancement for z80 by uniabis

  LZE Original Copyright (C)1995,2008 GORRY.
  Porting for Z80 by Kei Moroboshi 2017/SEP.

 License:original LZE license or zlib/libpng license


## Usage

```
lzee.exe E infile outfile

 pack infile to outfile with header

lzee.exe e infile outfile

 pack infile to outfile without header

lzee.exe D infile outfile

 unpack infile with header to outfile

lzee.exe d infile outfile

 unpack infile without header to outfile

 header is unpacked size in little endian 32bit integer

```

## original LZE readme.txt

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

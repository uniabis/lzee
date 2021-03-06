﻿# LZEe - LZE enhancement for Z80

  LZE
  Copyright (C)1995,2008 GORRY.

  Porting for Z80 by Kei Moroboshi 2017/SEP.

  LZEe - LZE enhancement for Z80 by uniabis
  LZEee - LZE extra enhancement for Z80 by uniabis

  License:zlib license or original LZE license

## Description

[LZEe](https://github.com/uniabis/lzee) is file compressor/decompressor derived from [LZE](http://gorry.haun.org/pw/?lze).

LZEe is designed to be effective with fast depacking on Z80 machines.

## Usage

```
Usage: lzee [option] {command} {infile} {outfile}

  {command}
    e : Encode without header
    E : Encode with header
    d : Decode without header
    D : Decode with header

  [option]
    f[format]...

  [format]
    1 : lze
    2 : LZEe(default)
    3 : LZEXE
    4 : LZEee f4(obsoleted)
    5 : LZEee f5
    r : Force without header

 header is unpacked size in big endian 32bit integer
```


## [Benchmarks](https://github.com/uniabis/z80depacker)

### Compression rate

test data:DEOCM-PLD-CV BIOS(16x16KB)

|Packer|ALL|MEGASDHC.B00|MEGASDHC.B01|MEGASDHC.B02|MEGASDHC.B03|MSX2MAIN.B00|MSX2MAIN.B01|MSXMUSIC.B00|MSX2EXT.B00|KANJJ1.B00|KANJJ1.B01|KANJJ1.B02|KANJJ1.B03|KANJJ1.B04|KANJJ1.B05|KANJJ1.B06|KANJJ1.B07|
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
|ApLib<br />(OaPACK)|161,422<br />(61.58%)|9,367<br />(57.17%)|4,926<br />(30.07%)|12,594<br />(76.87%)|12,340<br />(75.32%)|12,835<br />(78.34%)|13,579<br />(82.88%)|10,048<br />(61.33%)|12,361<br />(75.45%)|6,222<br />(37.98%)|4,090<br />(24.96%)|10,834<br />(66.13%)|10,642<br />(64.95%)|10,519<br />(64.20%)|10,453<br />(63.80%)|10,815<br />(66.01%)|9,797<br />(59.80%)|
|Bitbuster Extreme|172,080<br />(65.64%)|9,830<br />(60.00%)|5,133<br />(31.33%)|13,188<br />(80.49%)|12,856<br />(78.47%)|13,293<br />(81.13%)|14,088<br />(85.99%)|10,551<br />(64.40%)|13,013<br />(79.43%)|6,683<br />(40.79%)|4,507<br />(27.51%)|11,785<br />(71.93%)|11,599<br />(70.79%)|11,542<br />(70.45%)|11,493<br />(70.15%)|11,778<br />(71.89%)|10,741<br />(65.56%)|
|Exomizer2<br />(-P0)|160,011<br />(61.04%)|9,373<br />(57.21%)|4,902<br />(29.92%)|12,494<br />(76.26%)|12,297<br />(75.05%)|12,740<br />(77.76%)|13,402<br />(81.80%)|10,068<br />(61.45%)|12,351<br />(75.38%)|6,097<br />(37.21%)|3,975<br />(24.26%)|10,688<br />(65.23%)|10,510<br />(64.15%)|10,415<br />(63.57%)|10,348<br />(63.16%)|10,650<br />(65.00%)|9,701<br />(59.21%)|
|Exomizer3<br />(-P7)|160,007<br />(61.04%)|9,373<br />(57.21%)|4,902<br />(29.92%)|12,494<br />(76.26%)|12,297<br />(75.05%)|12,739<br />(77.75%)|13,402<br />(81.80%)|10,068<br />(61.45%)|12,351<br />(75.38%)|6,097<br />(37.21%)|3,974<br />(24.26%)|10,688<br />(65.23%)|10,509<br />(64.14%)|10,415<br />(63.57%)|10,347<br />(63.15%)|10,650<br />(65.00%)|9,701<br />(59.21%)|
|hruST<br />(oh1c -r)|162,217<br />(61.88%)|9,369<br />(57.18%)|4,895<br />(29.88%)|12,563<br />(76.68%)|12,282<br />(74.96%)|12,768<br />(77.93%)|13,454<br />(82.12%)|10,079<br />(61.52%)|12,331<br />(75.26%)|6,434<br />(39.27%)|4,230<br />(25.82%)|10,940<br />(66.77%)|10,753<br />(65.63%)|10,679<br />(65.18%)|10,597<br />(64.68%)|10,906<br />(66.56%)|9,937<br />(60.65%)|
|lz4<br />(lz4ultra)|191,416<br />(73.02%)|10,833<br />(66.12%)|5,794<br />(35.36%)|14,742<br />(89.98%)|14,290<br />(87.22%)|14,837<br />(90.56%)|15,448<br />(94.29%)|11,630<br />(70.98%)|14,578<br />(88.98%)|8,088<br />(49.37%)|5,431<br />(33.15%)|13,003<br />(79.36%)|12,732<br />(77.71%)|12,673<br />(77.35%)|12,535<br />(76.51%)|12,972<br />(79.17%)|11,830<br />(72.20%)|
|lz48|198,227<br />(75.62%)|10,717<br />(65.41%)|5,752<br />(35.11%)|14,588<br />(89.04%)|14,250<br />(86.98%)|14,268<br />(87.08%)|15,305<br />(93.41%)|12,121<br />(73.98%)|14,074<br />(85.90%)|8,167<br />(49.85%)|5,532<br />(33.76%)|14,290<br />(87.22%)|14,024<br />(85.60%)|13,960<br />(85.21%)|13,952<br />(85.16%)|14,179<br />(86.54%)|13,048<br />(79.64%)|
|lz49|195,027<br />(74.40%)|10,628<br />(64.87%)|5,559<br />(33.93%)|14,512<br />(88.57%)|14,030<br />(85.63%)|14,196<br />(86.65%)|15,254<br />(93.10%)|11,980<br />(73.12%)|13,969<br />(85.26%)|7,824<br />(47.75%)|5,240<br />(31.98%)|13,985<br />(85.36%)|13,761<br />(83.99%)|13,717<br />(83.72%)|13,674<br />(83.46%)|13,920<br />(84.96%)|12,778<br />(77.99%)|
|LZE<br />(lzee f1r)|174,118<br />(66.42%)|10,088<br />(61.57%)|5,459<br />(33.32%)|13,468<br />(82.20%)|13,183<br />(80.46%)|13,694<br />(83.58%)|14,385<br />(87.80%)|10,826<br />(66.08%)|13,299<br />(81.17%)|7,023<br />(42.86%)|4,660<br />(28.44%)|11,692<br />(71.36%)|11,489<br />(70.12%)|11,369<br />(69.39%)|11,279<br />(68.84%)|11,630<br />(70.98%)|10,574<br />(64.54%)|
|LZEee<br />(lzee f5)|174,118<br />(66.42%)|10,088<br />(61.57%)|5,459<br />(33.32%)|13,468<br />(82.20%)|13,183<br />(80.46%)|13,694<br />(83.58%)|14,385<br />(87.80%)|10,826<br />(66.08%)|13,299<br />(81.17%)|7,023<br />(42.86%)|4,660<br />(28.44%)|11,692<br />(71.36%)|11,489<br />(70.12%)|11,369<br />(69.39%)|11,279<br />(68.84%)|11,630<br />(70.98%)|10,574<br />(64.54%)|
|LZEXE<br />(lzee f3)|174,132<br />(66.43%)|10,089<br />(61.58%)|5,460<br />(33.33%)|13,469<br />(82.21%)|13,184<br />(80.47%)|13,695<br />(83.59%)|14,386<br />(87.81%)|10,828<br />(66.09%)|13,300<br />(81.18%)|7,023<br />(42.86%)|4,660<br />(28.44%)|11,692<br />(71.36%)|11,490<br />(70.13%)|11,370<br />(69.40%)|11,280<br />(68.85%)|11,631<br />(70.99%)|10,575<br />(64.54%)|
|lzsa1<br />(-f1)|182,295<br />(69.54%)|10,338<br />(63.10%)|5,391<br />(32.90%)|14,043<br />(85.71%)|13,703<br />(83.64%)|14,087<br />(85.98%)|14,892<br />(90.89%)|11,047<br />(67.43%)|13,719<br />(83.73%)|7,316<br />(44.65%)|4,804<br />(29.32%)|12,544<br />(76.56%)|12,252<br />(74.78%)|12,189<br />(74.40%)|12,075<br />(73.70%)|12,507<br />(76.34%)|11,388<br />(69.51%)|
|lzsa2<br />(-f2)|167,502<br />(63.90%)|9,670<br />(59.02%)|5,091<br />(31.07%)|13,125<br />(80.11%)|12,803<br />(78.14%)|13,291<br />(81.12%)|14,057<br />(85.80%)|10,339<br />(63.10%)|12,806<br />(78.16%)|6,421<br />(39.19%)|4,249<br />(25.93%)|11,288<br />(68.90%)|11,056<br />(67.48%)|10,936<br />(66.75%)|10,848<br />(66.21%)|11,275<br />(68.82%)|10,247<br />(62.54%)|
|megalz|167,609<br />(63.94%)|9,718<br />(59.31%)|5,124<br />(31.27%)|12,965<br />(79.13%)|12,660<br />(77.27%)|13,072<br />(79.79%)|13,917<br />(84.94%)|10,407<br />(63.52%)|12,833<br />(78.33%)|6,514<br />(39.76%)|4,320<br />(26.37%)|11,362<br />(69.35%)|11,161<br />(68.12%)|11,016<br />(67.24%)|11,012<br />(67.21%)|11,281<br />(68.85%)|10,247<br />(62.54%)|
|pletter|167,494<br />(63.89%)|9,706<br />(59.24%)|5,083<br />(31.02%)|12,945<br />(79.01%)|12,700<br />(77.51%)|13,205<br />(80.60%)|13,909<br />(84.89%)|10,466<br />(63.88%)|12,858<br />(78.48%)|6,511<br />(39.74%)|4,269<br />(26.06%)|11,340<br />(69.21%)|11,105<br />(67.78%)|10,992<br />(67.09%)|10,908<br />(66.58%)|11,252<br />(68.68%)|10,245<br />(62.53%)|
|shrinkler|153,168<br />(58.43%)|8,984<br />(54.83%)|4,680<br />(28.56%)|12,148<br />(74.15%)|11,916<br />(72.73%)|12,276<br />(74.93%)|13,100<br />(79.96%)|9,536<br />(58.20%)|11,820<br />(72.14%)|5,728<br />(34.96%)|3,700<br />(22.58%)|10,212<br />(62.33%)|10,020<br />(61.16%)|9,876<br />(60.28%)|9,808<br />(59.86%)|10,148<br />(61.94%)|9,216<br />(56.25%)|
|shrinkler(NP)|152,324<br />(58.11%)|8,912<br />(54.39%)|4,644<br />(28.34%)|12,092<br />(73.80%)|11,844<br />(72.29%)|12,176<br />(74.32%)|13,020<br />(79.47%)|9,516<br />(58.08%)|11,772<br />(71.85%)|5,664<br />(34.57%)|3,656<br />(22.31%)|10,164<br />(62.04%)|9,980<br />(60.91%)|9,840<br />(60.06%)|9,756<br />(59.55%)|10,116<br />(61.74%)|9,172<br />(55.98%)|
|zx7|170,296<br />(64.96%)|9,781<br />(59.70%)|5,080<br />(31.01%)|13,104<br />(79.98%)|12,784<br />(78.03%)|13,224<br />(80.71%)|14,021<br />(85.58%)|10,515<br />(64.18%)|12,943<br />(79.00%)|6,532<br />(39.87%)|4,401<br />(26.86%)|11,623<br />(70.94%)|11,436<br />(69.80%)|11,337<br />(69.20%)|11,331<br />(69.16%)|11,612<br />(70.87%)|10,572<br />(64.53%)|
|zx7b|170,425<br />(65.01%)|9,762<br />(59.58%)|5,091<br />(31.07%)|13,103<br />(79.97%)|12,810<br />(78.19%)|13,248<br />(80.86%)|14,002<br />(85.46%)|10,495<br />(64.06%)|12,964<br />(79.13%)|6,591<br />(40.23%)|4,424<br />(27.00%)|11,629<br />(70.98%)|11,451<br />(69.89%)|11,327<br />(69.13%)|11,341<br />(69.22%)|11,601<br />(70.81%)|10,586<br />(64.61%)|
|zx7mini<br />(back)|190,540<br />(72.69%)|10,580<br />(64.58%)|5,702<br />(34.80%)|14,358<br />(87.63%)|14,064<br />(85.84%)|14,015<br />(85.54%)|15,267<br />(93.18%)|12,073<br />(73.69%)|13,874<br />(84.68%)|7,390<br />(45.10%)|4,921<br />(30.04%)|13,428<br />(81.96%)|13,182<br />(80.46%)|13,091<br />(79.90%)|13,039<br />(79.58%)|13,311<br />(81.24%)|12,245<br />(74.74%)|


### Decompression speed

test data:DEOCM-PLD-CV BIOS(16x16KB)

|packer|unpacker|unpacker size|packed size|unpacking clocks|
|---|---|---:|---:|---:|
|ApLib|aplib156b|            156|        161,422<br />(61.57%)|     59,168,483<br />(LDIR x 9.81)|
|ApLib|aplib247b|            249|        161,422<br />(61.57%)|     35,485,949<br />(LDIR x 5.88)|
|ApLib|aplib247b_180_minimal|            152|        161,422<br />(61.57%)|     44,514,579<br />(LDIR x 7.38)|
|ApLib|aplib247b_180_small|            171|        161,422<br />(61.57%)|     34,169,981<br />(LDIR x 5.66)|
|ApLib|aplib247b_180_fast|            234|        161,422<br />(61.57%)|     32,552,096<br />(LDIR x 5.39)|
|ApLib|unaplib_fast|            235|        161,422<br />(61.57%)|     29,350,495<br />(LDIR x 4.86)|
|ApLib|unaplib_fast_180|            233|        161,422<br />(61.57%)|     29,636,463<br />(LDIR x 4.91)|
|ApLib|unaplib_small|            139|        161,422<br />(61.57%)|     45,350,252<br />(LDIR x 7.52)|
|BitbusterExtreme|debitbust|             89|        172,080<br />(65.64%)|     35,875,562<br />(LDIR x 5.95)|
|BitbusterExtreme|debitbustp1|             88|        172,080<br />(65.64%)|     32,099,423<br />(LDIR x 5.32)|
|BitbusterExtreme|debitbustp2|             96|        172,080<br />(65.64%)|     26,884,565<br />(LDIR x 4.45)|
|Exomizer2|deexo|            169|        160,011<br />(61.03%)|    108,490,817<br />(LDIR x 17.99)|
|Exomizer2|deexo_180|            166|        160,011<br />(61.03%)|    108,490,229<br />(LDIR x 17.99)|
|Exomizer2|deexo_180_fast_jp|            176|        160,011<br />(61.03%)|     92,969,945<br />(LDIR x 15.41)|
|Exomizer2|deexoopt_f3_180_p0|            242|        160,011<br />(61.03%)|     74,159,660<br />(LDIR x 12.29)|
|Exomizer3|deexo3p7|            176|        160,007<br />(61.03%)|     82,034,254<br />(LDIR x 13.60)|
|Exomizer3|deexo3p7_fast_jp|            181|        160,007<br />(61.03%)|     70,324,722<br />(LDIR x 11.66)|
|Exomizer3|deexoopt_p7|            219|        160,007<br />(61.03%)|     63,745,458<br />(LDIR x 10.57)|
|Exomizer3|deexoopt_f3_p7|            212|        160,007<br />(61.03%)|     61,265,322<br />(LDIR x 10.16)|
|Exomizer3|deexoopt_f3_180_p7|            219|        160,007<br />(61.03%)|     63,774,934<br />(LDIR x 10.57)|
|Exomizer3|deexo3|            191|        160,007<br />(61.03%)|     68,910,122<br />(LDIR x 11.42)|
|hrust|dehrust_ix|            234|        162,217<br />(61.88%)|     45,520,962<br />(LDIR x 7.54)|
|hrust|dehrust_ix_232b|            232|        162,217<br />(61.88%)|     45,413,861<br />(LDIR x 7.53)|
|hrust|dehrust_hl|            226|        162,217<br />(61.88%)|     44,726,210<br />(LDIR x 7.41)|
|hrust|dehrust_stk|            209|        162,217<br />(61.88%)|     41,277,317<br />(LDIR x 6.84)|
|lz4|lz4dec|             97|        191,416<br />(73.01%)|     10,893,051<br />(LDIR x 1.80)|
|lz4|unlz4_spke|            103|        191,416<br />(73.01%)|     10,031,857<br />(LDIR x 1.66)|
|lz4|unlz4_spke_fast|             96|        191,416<br />(73.01%)|      9,650,674<br />(LDIR x 1.60)|
|lz4|unlz4_spke_small|             65|        191,416<br />(73.01%)|      9,970,571<br />(LDIR x 1.65)|
|lz48|lz48decrunch\_v006\_|             70|        198,227<br />(75.61%)|      9,987,125<br />(LDIR x 1.65)|
|lz48|lz48decrunch_v006__180|             71|        198,227<br />(75.61%)|      9,503,964<br />(LDIR x 1.57)|
|lz49|lz49decrunch_v001|            106|        195,027<br />(74.39%)|     11,349,204<br />(LDIR x 1.88)|
|lz49|lz49decrunch_v001_180|            101|        195,027<br />(74.39%)|     11,002,608<br />(LDIR x 1.82)|
|lze|lzdec|            119|        174,118<br />(66.42%)|     21,831,226<br />(LDIR x 3.62)|
|lze|dlze_fast|             90|        174,118<br />(66.42%)|     17,122,936<br />(LDIR x 2.83)|
|lze|dlze_small|             79|        174,118<br />(66.42%)|     21,975,061<br />(LDIR x 3.64)|
|lzeee|dlzeee_fast|             87|        174,118<br />(66.42%)|     15,771,965<br />(LDIR x 2.61)|
|lzeee|dlzeee_fast2|             97|        174,118<br />(66.42%)|     15,533,041<br />(LDIR x 2.57)|
|lzeee|dlzeee_small|             72|        174,118<br />(66.42%)|     21,330,646<br />(LDIR x 3.53)|
|lzexe|z80unlze|            156|        174,132<br />(66.42%)|     25,663,296<br />(LDIR x 4.25)|
|lzexe|z80unlzep2|            133|        174,132<br />(66.42%)|     23,882,407<br />(LDIR x 3.96)|
|lzexe|z80unlze_small|            112|        174,132<br />(66.42%)|     31,984,416<br />(LDIR x 5.30)|
|lzexe|z80unlzep2_small|             88|        174,132<br />(66.42%)|     30,313,875<br />(LDIR x 5.02)|
|lzsa1|unlzsa1_fast|            109|        182,295<br />(69.54%)|     10,141,189<br />(LDIR x 1.68)|
|lzsa1|unlzsa1_small|             67|        182,295<br />(69.54%)|     11,309,112<br />(LDIR x 1.87)|
|lzsa2|unlzsa2_fast|            216|        167,502<br />(63.89%)|     15,810,936<br />(LDIR x 2.62)|
|lzsa2|unlzsa2_fast_180|            214|        167,502<br />(63.89%)|     16,079,288<br />(LDIR x 2.66)|
|lzsa2|unlzsa2_small|            139|        167,502<br />(63.89%)|     17,997,952<br />(LDIR x 2.98)|
|lzsa2|unlzsa2_small_180|            137|        167,502<br />(63.89%)|     18,266,304<br />(LDIR x 3.02)|
|MegaLZ|megalz_dec40|            110|        167,609<br />(63.93%)|     45,653,296<br />(LDIR x 7.57)|
|MegaLZ|unmegalz_fast_v2|            233|        167,609<br />(63.93%)|     20,775,177<br />(LDIR x 3.44)|
|MegaLZ|unmegalz_fast_v2p1|            229|        167,609<br />(63.93%)|     20,533,028<br />(LDIR x 3.40)|
|MegaLZ|unmegalz_small_v2|             92|        167,609<br />(63.93%)|     32,642,661<br />(LDIR x 5.41)|
|Pletter|unpletter|            170|        167,494<br />(63.89%)|     28,812,190<br />(LDIR x 4.77)|
|Pletter|unpletter_180|            146|        167,494<br />(63.89%)|     26,619,594<br />(LDIR x 4.41)|
|Shrinkler|shrinkler_recall_209|            209|        153,168<br />(58.42%)|  2,648,202,619<br />(LDIR x 439.21)|
|Shrinkler|shrinkler_recall_209_r800_rom|            207|        153,168<br />(58.42%)|  2,636,690,003<br />(LDIR x 437.30)|
|Shrinkler(NP)|deshrink_np|            202|        152,324<br />(58.10%)|  2,643,754,822<br />(LDIR x 438.47)|
|Shrinkler(NP)|deshrink_np_r800|            201|        152,324<br />(58.10%)|  2,632,444,897<br />(LDIR x 436.60)|
|zx7|dzx7_lom_v1|            214|        170,296<br />(64.96%)|     23,446,544<br />(LDIR x 3.88)|
|zx7|dzx7_lom_v1p1|            198|        170,296<br />(64.96%)|     22,383,853<br />(LDIR x 3.71)|
|zx7|dzx7_turbo|             88|        170,296<br />(64.96%)|     27,346,595<br />(LDIR x 4.53)|
|zx7|dzx7_standard|             69|        170,296<br />(64.96%)|     36,700,476<br />(LDIR x 6.08)|
|zx7b|dzx7b_fast|            191|        170,425<br />(65.01%)|     20,907,617<br />(LDIR x 3.46)|
|zx7b|dzx7b_fast_r800|            184|        170,425<br />(65.01%)|     20,659,431<br />(LDIR x 3.42)|
|zx7b|dzx7b_slow|             64|        170,425<br />(65.01%)|     33,688,687<br />(LDIR x 5.58)|
|zx7b|dzx7b_slow_r800|             64|        170,425<br />(65.01%)|     33,688,687<br />(LDIR x 5.58)|
|zx7mini|dzx7mini|             39|        190,540<br />(72.68%)|     20,556,427<br />(LDIR x 3.40)|


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

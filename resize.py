import cv2
import os
import numpy as np
import subprocess

# 画像のリサイズを行うプログラム


# Airdropで転送した画像の名前がIMG_15〇〇.jpgなのでtitleに代入
# ディレクトリも絶対パスで指定して代入
title = input('filename:IMG_15')
title = './Downloads/IMG_15' + title
title += '.jpg'

# 画像の読み込み
img = cv2.imread(title)

# 画像の縦幅，横幅を取得
Height, Width = img.shape[:2]

# リサイズ後の画像の大きさを元の0.3倍に
size = (round(Width*0.3), round(Height*0.3))
decreaseImg = cv2.resize(img, size)

# 授業の番号をnumに格納
# ex) 月曜1限なら11，木曜3限なら43
num = input('classnumber:')
pathplus = numtest(num)
path = './Downloads' + pathplus


# リサイズ後の画像の名前を設定
# 必要なら学籍番号を代入
m = input('Use student number? no = n')
if m != 'n':
    changedtitle = '2019311078_auto_'
    
changedtitle += input('after changed name:')
changedtitle += '.jpg'

# パスを標準出力
print(path)

# リサイズした画像を作成して保存
cv2.imwrite(os.path.join(path,changedtitle), decreaseImg)

os.remove(title)

if os.path.exists(path):
    subprocess.call(["open", path])

from urllib import request  # urllib.requestモジュールをインポート
from bs4 import BeautifulSoup  # BeautifulSoupクラスをインポート

# 競技プログラミングで入力変数を読み込んで
# 自動でファイルに書き込むプログラム
# 自分で入力した方が効率がいいことがわかったため作成を中断した

url = 'https://atcoder.jp/contests/abc198/tasks/abc198_a'
response = request.urlopen(url)
soup = BeautifulSoup(response)
response.close()

# 変数の制約を入手
found = soup.find('div', class_ = 'part')
print(found.next_sibling.next_sibling.text)

# 変数の入力方法を入手
print(found.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.next_sibling.text)
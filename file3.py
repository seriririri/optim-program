import os

num = input('Enter problem number : ')

folder = str(num)
new_dir_path = './' + folder
os.mkdir(new_dir_path)


for i in range(8):
    a = str(i)
    ch = a.zfill(3)
    path = new_dir_path + '/' + ch + '.cpp'
    
    f = open(path, 'w')
    f.write('#include <iostream>\n#include <vector>\n#include <string>\n#include <algorithm>\n#include <queue>\n#include <deque>\n#include <map>\ntypedef long long LL;\nusing namespace std;\n\nint main() {\n    \n}')
    f.close()
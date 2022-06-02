#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ios>
#include <iomanip>
using namespace std;

// 拡張子が.mp4の動画ファイルの時間を指定して
// ffmpegで指定した時間ごとに区切るためのプログラム
// 分割した動画は個別の動画ファイルとして保存される
// ffmpegのコマンドはvideoData.txtに格納される


// ffmpeg用に動画の長さを計算する配列
// ex) 0:20:50 ~ 0:33:56 -> 0:13:06
void calc(int sa1, int sb1, int sc1, int sa2, int sb2, int sc2, int *ta, int *tb, int *tc) {
    int SA1 = sa1, SB1 = sb1, SC1 = sc1, SA2 = sa2, SB2 = sb2, SC2 = sc2;

    sc2 -= sc1;
    if (sc2 < 0) {
        sb2--;
        sc2 +=  60;
    }
    sb2 -= sb1;
    if (sb2 < 0) {
        sa2--;
        sb2 += 60;
    }
    sa2 -= sa1;

    *ta  =  sa2;
    *tb  =  sb2;
    *tc  =  sc2;

}


int main() {
    
    // N:動画を区切る時間の数
    int N;
    cin >> N;
    
    // start:動画を区切る際の時間（開始時間）を格納する配列
    // start_nh:startに時間を格納する前処理を行うための配列
    // time:区切られた動画の長さを格納する配列
    vector<vector<int> > start(3, vector<int>(N + 1));
    vector<vector<int> > start_nh(2, vector<int>(N + 1));
    vector<vector<int> > time(3, vector<int>(N));
    
    
    for (int i = 0; i < 3; i++) {
        start[i][0] = 0;
    }
    
    // count:動画のタイトルにある空白の数
    // name:動画のタイトルを格納する配列
    int count;
    cin >> count;
    vector<string> name(count + 1);
    
    for (int i = 0; i < count + 1; i++) {
        cin >> name[i];
    }
    
    puts("");
    
    for (int j = 1; j < N + 1; j++) {
        
        // windowsのアプリとffmpegで時間の表示が違うように変更されたので
        // 入力した時間をffmpeg用に計算しなおす関数
        // ex) 115:30 -> 1:55:30
        
        cin >> start_nh[0][j];
        cin >> start_nh[1][j];
        
        start[0][j]  =  start_nh[0][j] / 60;
        start[1][j]  =  start_nh[0][j] - start[0][j] * 60;
        start[2][j]  =  start_nh[1][j];
        
        calc(start[0][j-1], start[1][j-1], start[2][j-1], start[0][j], start[1][j], start[2][j], &time[0][j-1], &time[1][j-1], &time[2][j-1]);
        
    }
    
    
    ofstream fout("videoData.txt");
    
    // videoData.txtにffmpegコマンドの格納を行う
    for (int i = 0; i < N; i++) {
        
        fout << "ffmpeg.exe -ss " << setfill('0') << right << setw(2) << start[0][i] << ":" << setfill('0') << right << setw(2) << start[1][i] << ":" << setfill('0') << right << setw(2) << start[2][i] << " -t " << setfill('0') << right << setw(2) << time[0][i] << ":" << setfill('0') << right << setw(2) << time[1][i] << ":" << setfill('0') << right << setw(2) << time[2][i] << " -i \"" << flush;
        
        for (int j = 0; j < count + 1; j++) {
            fout << name[j].c_str() << flush;
            if (j != count) fout << " " << flush;
        }
        
        fout << ".mp4\" -vcodec copy -acodec copy \"" << flush;
        
        for (int j = 0; j < count + 1; j++) {
            fout << name[j].c_str() <<  " " << flush;
        }
        
        fout << "(" << i + 1 << ").mp4\"" << flush;
        
        if (i != N - 1)  {
            fout << " && " << flush;
        }
        
    }
    
}
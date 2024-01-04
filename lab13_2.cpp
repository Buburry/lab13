#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void updateImage(bool image[N][M],int s,int x,int y){
    if(s == 1){   // เพื่อเป็นค่าเริ่มต้น คือ ถ้า 1 ให้เข้าอันนี้
        image[x][y] = 1;
    }
    else {
        for(int i = 0;i < N ;i++){
            for(int j = 0 ; j < M;j++){
                if (sqrt(pow((x-i),2)+pow((y-j),2)) <= s-1){    // สมการวงกลม แค่ย้ายมาข้างซ้าย x2 +y2 = r2 แต่ไม่มี r2 ส่วน i j คือกำหนดตำแหน่ง s-1 คือ ลอง run แล้วให้ได้ขนาดที่ต้องการ
                image[i][j] = 1;
                }
            }
        }
    }
}

void showImage(const bool image[N][M]) {
    cout << "------------------------------------------------------------------------\n";

    for (int i = 0; i < N; i++) {
        cout << "|";
        
        for (int j = 0; j < M; j++) {
            if (image[i][j]) { // ให้ค่ามันเท่ากัน เพื่อที่จะได้ตรงช่อง เหมือนลองแล้ว แต่ผิดป่าว image[n][m]
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "|\n";
    }

    cout << "------------------------------------------------------------------------\n";
}
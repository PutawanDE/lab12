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

void showImage(const bool draw[N][M]){
    cout << "------------------------------------------------------------------------" << '\n';
    for(int y = 0; y < N; ++y){
        cout << '|';
        for (int x = 0; x < M; ++x){
            if(draw[y][x] == 1) cout << '*';
            else cout << ' ';
        }

        cout << '|' << '\n';
    }
    cout << "------------------------------------------------------------------------" << '\n';
}

void updateImage(bool draw[N][M],int s,int originY,int originX){
    for(int y = 0; y < N; ++y){
        for (int x = 0; x < M; ++x){
            if(sqrt((pow(x - originX, 2.0)+(pow(y-originY,2.0)))) <= (s-1.0)){
                draw[y][x] = 1;
            }
        }
    }
}

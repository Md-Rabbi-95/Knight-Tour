#include <bits/stdc++.h>
using namespace std;
#define n 8
const int row [n] = {1,1,-1,-1,2,2,-2,-2};
const int col [n] = {2,-2,2,-2,1,-1,1,-1};
int chess[n][n];
bool valid(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n ){
        return false;
    }
    return true;
}

bool travel(int a, int b, int mov){
    chess[a][b] = mov;
    if(mov == n*n)
        return true;

    for(int k = 0; k < n; k++){
        int x = a + row[k];
        int y = b + col[k];

        if(valid(x, y) && chess[x][y] == -1)
        {
            if (travel(x, y, mov + 1))
                return true;
        }
    }
    return false;
}

int main(){

    for(int i = 0;i < n;i++){
        for(int j = 0; j < n;j++){
            chess[i][j] = -1;
        }
    }

    if (!travel(0, 0, 0)) {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << setw(2) << chess[i][j] << " ";
            cout << "\n";
        }
    }
}

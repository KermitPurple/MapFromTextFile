#include<iostream>
#include<raylib.h>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

vector<vector<char>> vector_from_file(string file_name){
    vector<vector<char>> v;
    int i = 0;
    string line;
    ifstream f(file_name);
    while(getline(f, line)){
        v.push_back(vector<char>(line.begin(), line.end()));
        i++;
    }
    std::cout << i << std::endl;
    return v;
}

void draw_from_vector(vector<vector<char>> v, int window_x, int window_y){
    int x_size = v[0].size();
    int y_size = v.size();
    int x_scale = window_x / x_size;
    int y_scale = window_y / y_size;
    for(int i = 0; i < y_size; i++)
        for(int j = 0; j < x_size; j++){
            Color color;
            switch(v[i][j]){
                case 'r':
                    color = RED;
                    break;
                case 'g':
                    color = GREEN;
                    break;
                case 'b':
                    color = BLUE;
                    break;
                default:
                    color = BLACK;
            }
            DrawRectangle(j * x_scale, i * y_scale, x_scale, y_scale, color);
        }
}

int main(){
    const int WINDOW_X = 600;
    const int WINDOW_Y = 600;
    auto v = vector_from_file("assets/map.txt");
    InitWindow(WINDOW_X, WINDOW_Y, "Load map from file");
    while(!WindowShouldClose()){
        BeginDrawing();
        draw_from_vector(v, WINDOW_X, WINDOW_Y);
        EndDrawing();
    }
	return 0;
}

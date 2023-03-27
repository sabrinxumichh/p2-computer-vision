// Project UID af1f95f547e44c8ea88730dfb185559d

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <string>
#include "Image.h"
#include "processing.h"
using namespace std;

int main(int argc, char *argv[]) {

    if(argc != 4 && argc != 5) {
        
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
        << "WIDTH and HEIGHT must be less than or equal to original" << endl;

        return 1;
    }

    string filename = argv[1];
    ifstream fin;
    fin.open(filename);

    Image *img = new Image;
    Image_init(img, fin);
    
    if (!fin.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return 1;
    }

    string filename2 = argv[2];
    ofstream fout;
    fout.open(filename2);

    if (!fout.is_open()) {
        cout << "Error opening file: " << filename2 << endl;
        return 1;
    }

    int width;
    int height;

    if(argc == 4){
        width = atoi(argv[3]);
        seam_carve_width(img, width);
    }
    else{
        width = atoi(argv[3]);
        height = atoi(argv[4]);
        seam_carve(img, width, height);
    }

    Image_print(img, fout);
    delete img;
}

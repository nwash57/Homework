#include <windows.h>
#include <iostream>
#include <fstream>
#include "main.h"

using namespace std;

BITMAPFILEHEADER bmpfile_header;

void writeHeader(ostream &out, int width, int height);
void printVectors(Point p);

int gWidth, gHeight;

int main()
{
    int width, height;
    cout << "Enter width: ";
    cin >> width;
    cout << "\nEnter height: ";
    cin >> height;

    gWidth = width;
    gHeight = height;

    Point p;
    p.x = 0.33f;
    p.y = 0.66f;
    printVectors(p);

    //createCheckerBoardBmp(width, height);
}

void printVectors(Point p)
{
    Vector * innerVectors = &p.getInnerVectors(gWidth, gHeight);

    for (int i = 0; i < 4; i++)
    {
        cout << "(" << innerVectors[i].x << ", " << innerVectors[i].y << ")\n";
    }
}

float noise2d(float x, float y)
{

}

void createCheckerBoardBmp(int width, int height)
{
    ofstream ofs;
    ofs.open("test.bmp");

    writeHeader(ofs, width, height);

    for (int row = 0; row < height; row++)
    {
        if (row % 2 == 0)
            for (int col = 0; col < width; col++)
            {
                if (col % 2 == 0)
                {
                    ofs << static_cast<unsigned char>(0);
                    ofs << static_cast<unsigned char>(0);
                    ofs << static_cast<unsigned char>(0);
                }
                else
                {
                    ofs << static_cast<unsigned char>(255);
                    ofs << static_cast<unsigned char>(0);
                    ofs << static_cast<unsigned char>(0);
                }
            }
        else
            for (int col = 0; col < width; col++)
            {
                if (col % 2 != 0)
                {
                    ofs << static_cast<unsigned char>(0);
                    ofs << static_cast<unsigned char>(255);
                    ofs << static_cast<unsigned char>(0);
                }
                else
                {
                    ofs << static_cast<unsigned char>(0);
                    ofs << static_cast<unsigned char>(0);
                    ofs << static_cast<unsigned char>(255);
                }
            }
    }
    ofs.close();
}

void writeHeader(ostream &out, int width, int height)
{
    if (width % 4 != 0)
    {
        cerr << "width must be multiple of 4";
        exit(1);
    }

    BITMAPFILEHEADER header;
    header.bfType = 0x4d42;
    header.bfSize = 14 + 40 + (width * height * 3);
    header.bfReserved1 = 0;
    header.bfReserved2 = 0;
    header.bfOffBits = 14 + 40;

    BITMAPINFOHEADER info;
    memset(&info, 0, 40);
    info.biSize = 40;
    info.biWidth = width;
    info.biHeight = height;
    info.biPlanes = 1;
    info.biBitCount = 24;
    info.biCompression = 0;

    out.write((char *) (&header), 14);
    out.write((char *) (&info), 40);
}






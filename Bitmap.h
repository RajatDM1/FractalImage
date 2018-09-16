

#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include<cstdint>
#include<memory>
using namespace std;

namespace fractal{
class Bitmap {
private:
    int m_height{0};
    int m_width{0};
    unique_ptr<uint8_t[]> m_pPixels{nullptr};
public:
    Bitmap(int width, int height);
    bool write(string filename);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
//    Bitmap(const Bitmap& orig);
    virtual ~Bitmap();
private:

};
}

#endif /* BITMAP_H */


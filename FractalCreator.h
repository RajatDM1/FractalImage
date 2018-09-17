
#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H
#include<string>
#include "zoom.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include <cstdlib>
#include <math.h>
#include <cstdint>
using namespace std;
namespace fractal{
class FractalCreator {
private:
    int m_width;
    int m_height;
    unique_ptr<int[]> m_histogram;
    unique_ptr<int[]> m_fractal;
    Bitmap m_bitmap;
    ZoomList m_zoomList;
    int m_total{0};
private:
    void calculateIterations();
    void calculateTotalIterations();
    void drawFractal();
    void addZoom(const Zoom& zoom);
    void writeBitmap(string name);
public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();
    void run(string name);
};
}
#endif /* FRACTALCREATOR_H */


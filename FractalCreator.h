
#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H
#include<string>
#include "zoom.h"
using namespace std;
namespace fractal{
class FractalCreator {
public:
    FractalCreator();
    virtual ~FractalCreator();
    void calculateIterations();
    void drawFractal();
    void addZoom(const Zoom& zoom);
    void writeBitmap(string name);
};
}
#endif /* FRACTALCREATOR_H */


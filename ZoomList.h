
#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include <vector>
#include<utility>
#include "zoom.h"
using namespace std;
namespace fractal{
class ZoomList {
private:
    int m_height{0};
    int m_width{0};
    vector <zoom> zooms;
public:
    ZoomList(int width, int height);
    void add(const zoom& zoo);
    pair<double,double> doZoom(int x,int y);
};
}

#endif /* ZOOMLIST_H */

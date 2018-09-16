
#include "ZoomList.h"
#include "zoom.h"
namespace fractal{
ZoomList::ZoomList(int width, int height):m_height(height), m_width(width){
}

void ZoomList::add(const zoom& zoo){
    zooms.push_back(zoo);
}

pair<double,double> ZoomList::doZoom(int x,int y){
    return pair<double,double>(0,0);
}
//ZoomList::ZoomList(const ZoomList& orig) {
//}
}



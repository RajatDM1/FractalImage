
#include "ZoomList.h"
#include "zoom.h"
#include <iostream>
using namespace std;
namespace fractal{
ZoomList::ZoomList(int width, int height):m_height(height), m_width(width){
}

void ZoomList::add(const zoom& zoo){
    zooms.push_back(zoo);
    m_xCenter  +=(zoo.x - m_width/2)*m_scale;//how far from center point has user clicked
    m_yCenter  +=(zoo.y - m_width/2)*m_scale;
    
    m_scale = m_scale*zoo.scale;//new scale
}

pair<double,double> ZoomList::doZoom(int x,int y){
    return pair<double,double>(0,0);
}
//ZoomList::ZoomList(const ZoomList& orig) {
//}
}



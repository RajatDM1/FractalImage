#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(2)

namespace fractal {
//int16_t shows that we'll be using 16 bit type
struct BitmapInfoHeader {
	int32_t headerSize{40};//size of the struct
	int32_t width;//weidth and height of the bitmap
	int32_t height;
	int16_t planes{1};
	int16_t bitsPerPixel{24};//1 byte for each color and rgb color thus 3*8
	int32_t compression{0};
	int32_t dataSize{0};
	int32_t horizontalResolution{2400};
	int32_t verticalResolution{2400};
	int32_t colors{0};
	int32_t importantColors{0};
};

}

#endif

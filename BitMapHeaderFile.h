

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>//using this to use 32bit int

using namespace std;

#pragma pack(2)//makes cpp align all the data in 2byte boundry without adding any hidden padding to the data of the struct

namespace fractal {

struct BitmapFileHeader {
	char header[2] { 'B', 'M' };
	int32_t fileSize;//the size of the final file using 32bit int
	int32_t reserved { 0 };
	int32_t dataOffset;//how long into the file the actual data begins
};

}

#endif /* BITMAPFILEHEADER_H_ */


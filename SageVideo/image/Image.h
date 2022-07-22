#pragma once

#include "definitions/local_definitions.h"
#include "data/Data.h"
#include "utils/Size.h"

namespace img {

#pragma pack(push, 1)
struct Image : public DataHeader {
    Image() : DataHeader(DataType::Image),
    imgFormat(ImageFormat::Undefined),
    imgSize(um::Size<int>(0,0)),
    imgSourceType(ImageSource::Undefined) {

    }
    ImageFormat imgFormat;
    um::Size<int> imgSize;
    ImageSource imgSourceType;
    ColorType imgColorType;
    uint8_t channels;

};
#pragma pack(pop)


using swImage = DataCore<Image>;
}
#include "local_definitions.h"

const char* toString(img::ImageFormat format) {
    switch (format) {
    case img::ImageFormat::H264:
        return "H264";
    case img::ImageFormat::JPEG:
        return "JPEG";
    case img::ImageFormat::RAW:
        return "RAW";
    case img::ImageFormat::MPEG4:
        return "MPEG4";
    default:
        return "Undefined";
    }        
}

const char* toString(img::ImageSource source) {
    switch (source) {
    case img::ImageSource::RTSP:
        return "RTSP";
    case img::ImageSource::DISK:
        return "DISK";
    default:
        return "Undefined";
    }        
}
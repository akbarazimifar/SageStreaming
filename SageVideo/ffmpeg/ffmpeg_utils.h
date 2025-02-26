#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <map>

extern "C" {
    #include <libavutil/error.h>
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavformat/avio.h>
    #include <libavutil/opt.h>
    #include <libavdevice/avdevice.h>
};

#include "definitions/local_definitions.h"

enum class RtspCameraState {
    Undefined = 0,
    Ok = 1,
    HttpBadRequest = 2,
    HttpUnauthorized = 3,
    HttpForbidden = 4,
    HttpNotFound = 5,
    HttpOther = 6,
    HttpServerError = 7,
    InvalidData = 8,
    NoConnection = 9,
    WrongStream = 10,
    NoLicense = 11,
    NoData = 12,
    StreamEnded = 13,
    BlockingTimer = 14,
    Stopped = 15
};

struct TrimmedAVPacket {
    uint8_t* data;
    int size;
};

const int timeoutConnection = 15000;
const int timeoutStream = 5000;
const int timeoutTeardown = 1000;

bool initializeFFmpeg(int logLevel = -8);
std::string errorToString(int code);
RtspCameraState errortoCameraState(int code, bool timerExpired);
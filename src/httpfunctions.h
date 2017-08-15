#include "strip.h"
#include "application.h"

#ifndef HTTPFUNCTIONS_H
#define HTTPFUNCTIONS_H

class HttpFunctions {
    public:
        HttpFunctions(Strip strip);
        int setAllToColor(String command);

    private:
        Strip strip;
};

#endif


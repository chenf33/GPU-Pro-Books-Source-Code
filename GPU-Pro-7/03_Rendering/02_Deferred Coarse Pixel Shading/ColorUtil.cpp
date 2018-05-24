/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
//
// Modified by StephanieB5 to remove dependencies on DirectX SDK in 2017
//
/////////////////////////////////////////////////////////////////////////////////////////////

#include "ColorUtil.h"

using namespace DirectX;

XMVECTOR HueToRGB(float hue)
{
    float intPart;
    float fracPart = modff(hue * 6.0f, &intPart);
    int region = static_cast<int>(intPart);
    
    switch (region) {
    case 0: return  XMVectorSet(1.0f, fracPart, 0.0f, 0.f);
    case 1: return  XMVectorSet(1.0f - fracPart, 1.0f, 0.0f, 0.f);
    case 2: return  XMVectorSet(0.0f, 1.0f, fracPart, 0.f);
    case 3: return  XMVectorSet(0.0f, 1.0f - fracPart, 1.0f, 0.f);
    case 4: return  XMVectorSet(fracPart, 0.0f, 1.0f, 0.f);
    case 5: return  XMVectorSet(1.0f, 0.0f, 1.0f - fracPart, 0.f);
    };

    return  XMVectorSet(0.0f, 0.0f, 0.0f, 0.f);
}
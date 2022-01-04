#pragma once
#include <iostream>
#include "Laundromat.h"


struct LaundromatWrapper
{
    LaundromatWrapper(Laundromat* ptr): pointerToLaundromat(ptr) {}
    ~LaundromatWrapper()
    {
        delete pointerToLaundromat;
    }
    Laundromat* pointerToLaundromat = nullptr;
};
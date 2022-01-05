#pragma once
#include "Wrapper.h"
#include "Laundromat.h"
#include "Restaurant.h"
#include "Speaker.h"
#include "Server.h"
#include "Equipment.h"
#include "Data.h"

struct LaundromatWrapper
{
    LaundromatWrapper(Laundromat* ptr): pointerToLaundromat(ptr) {}
    ~LaundromatWrapper()
    {
        delete pointerToLaundromat;
    }
    Laundromat* pointerToLaundromat = nullptr;
};

struct RestaurantWrapper
{
    RestaurantWrapper(Restaurant* ptr): pointsToRestaurant(ptr){}
    ~RestaurantWrapper()
    {
        delete pointsToRestaurant;
    }
    Restaurant* pointsToRestaurant = nullptr;
};

struct SpeakerWrapper
{
    SpeakerWrapper(Speakers* ptr): pointsToSpeaker(ptr){}
    ~SpeakerWrapper()
    {
        delete pointsToSpeaker;
    }
    Speakers* pointsToSpeaker = nullptr;
};

struct EquipmentWrapper
{
    EquipmentWrapper(Equipment* ptr): pointsToEquipment(ptr){}
    ~EquipmentWrapper()
    {
        delete pointsToEquipment;
    }
    Equipment* pointsToEquipment = nullptr;
};

struct DataWrapper
{
    DataWrapper(Data* ptr): pointsToData(ptr){}
    ~DataWrapper()
    {
        delete pointsToData;
    }
    Data* pointsToData =nullptr;
};











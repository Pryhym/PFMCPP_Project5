#include "Wrapper.h"
#include "Wrapper.h"
#include "Laundromat.h"
#include "Restaurant.h"
#include "Speaker.h"
#include "Server.h"
#include "Equipment.h"
#include "Data.h"

LaundromatWrapper::LaundromatWrapper(Laundromat* ptr) : pointerToLaundromat(ptr) {}
LaundromatWrapper::~LaundromatWrapper()
{
    delete pointerToLaundromat;
}

  RestaurantWrapper::RestaurantWrapper(Restaurant* ptr) : pointsToRestaurant(ptr){}
    RestaurantWrapper::~RestaurantWrapper()
    {
        delete pointsToRestaurant;
    }

   SpeakerWrapper::SpeakerWrapper(Speakers* ptr): pointsToSpeaker(ptr){}
    SpeakerWrapper::~SpeakerWrapper()
    {
        delete pointsToSpeaker;
    } 

    EquipmentWrapper::EquipmentWrapper(Equipment* ptr): pointsToEquipment(ptr){}
    EquipmentWrapper::~EquipmentWrapper()
    {
        delete pointsToEquipment;
    }

    DataWrapper::DataWrapper(Data* ptr): pointsToData(ptr){}
    DataWrapper::~DataWrapper()
    {
        delete pointsToData;
    }










  
    




























#pragma once
struct Laundromat;
struct Restaurant;
struct Speakers;
struct Server;
struct Equipment;
struct Data;

struct LaundromatWrapper
{
    LaundromatWrapper(Laundromat* ptr);
    ~LaundromatWrapper();
    Laundromat* pointerToLaundromat = nullptr;
};

struct RestaurantWrapper
{
    RestaurantWrapper(Restaurant* ptr);
    ~RestaurantWrapper();
    Restaurant* pointsToRestaurant = nullptr;
};

struct SpeakerWrapper
{
    SpeakerWrapper(Speakers* ptr);
    ~SpeakerWrapper();
    Speakers* pointsToSpeaker = nullptr;
};

struct EquipmentWrapper
{
    EquipmentWrapper(Equipment* ptr);
    ~EquipmentWrapper();
    Equipment* pointsToEquipment = nullptr;
};

struct DataWrapper
{
    DataWrapper(Data* ptr);
    ~DataWrapper();
    Data* pointsToData =nullptr;
};











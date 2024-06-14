// Fill out your copyright notice in the Description page of Project Settings.


#include "StreetDoorKey.h"

AStreetDoorKey::AStreetDoorKey()
{
	LinkedDoor = nullptr;
}

AStreetDoor* AStreetDoorKey::GetLinkedDoor()
{
	return LinkedDoor;
}

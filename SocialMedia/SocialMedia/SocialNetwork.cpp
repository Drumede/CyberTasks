#include "SocialNetwork.h"
#include <iostream>
#define WINDOWS "Windows1"

void SocialNetwork::init(std::string networkName, int minAge) {
	this->networkName = networkName;
	this->minAge = minAge;
	this->profiles = new ProfileList;
	this->profiles->init();
}

void SocialNetwork::clear() {
	this->networkName = "";
	this->minAge = 0;
	this->profiles->clear();
	delete this->profiles;
}

std::string SocialNetwork::getNetworkName() {
	return this->networkName;
}

int SocialNetwork::getMinAge() {
	return this->minAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add) {
	if (profile_to_add.getOwner().getAge() < this->minAge)
		return false;
	this->profiles->add(profile_to_add);
	return true;
}

std::string SocialNetwork::getWindowsDevices() {
	ProfileNode* temp;
	DeviceNode* temp2;
	std::string returnval = "";
	temp = this->profiles->get_first();
	if (temp == nullptr)
		return "";
	while (temp != nullptr)
	{
		temp2 = temp->get_data().getOwner().getDevices().get_first();
		if (temp2 == nullptr)
			continue;
		while (temp2 != nullptr)
		{
			if (temp2->get_data().getOS().find(WINDOWS) != std::string::npos && temp2->get_data().isActive())
				returnval += "[" + std::to_string(temp2->get_data().getID()) + ", " + temp2->get_data().getOS() + "]" + ", ";
			temp2 = temp2->get_next();
		}
		temp = temp->get_next();
	}
	if (returnval.empty())
		return returnval;
	returnval.pop_back();
	returnval.pop_back();
	return returnval;
}
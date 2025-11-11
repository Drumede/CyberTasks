#include "User.h"
#include <iostream>

void User::init(unsigned int id, std::string username, unsigned int age) {
	this->id = id;
	this->username = username;
	this->age = age;
	this->devicesList = new DevicesList;
	this->devicesList->init();
}

void User::clear() {
	this->devicesList->clear();
	this->username = "";
	this->age = 0;
	this->id = 0;
}

unsigned int User::getID() const {
	return this->id;
}

std::string User::getUserName() const {
	return this->username;
}

unsigned int User::getAge() const {
	return this->age;
}

DevicesList& User::getDevices() const {
	return *this->devicesList;
}

void User::addDevice(Device newDevice) {
	this->devicesList->add(newDevice);
}

bool User::checkIfDevicesAreOn() const {
	DeviceNode* temp;
	temp = this->devicesList->get_first();
	if (temp == nullptr)
		return true;
	while (temp->get_next() != nullptr)
	{
		if (!temp->get_data().isActive()) {
			return false;
		}
		temp = temp->get_next();
	}
	return true;
}
#include "Device.h"
#include <iostream>

void Device::init(int deviceId, DeviceType deviceType, std::string deviceOs) {
	this->id = deviceId;
	this->type = deviceType;
	this->os = deviceOs;
}

std::string Device::getOS() const {
	return this->os;
}

int Device::getID() const {
	return this->id;
}


DeviceType Device::getType() const {
	return this->type;
}

bool Device::isActive() const {
	return this->active;
}

void Device::activate() {
	this->active = true;
}

void Device::deactivate() {
	this->active = false;
}
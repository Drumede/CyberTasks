#include "Device.h"

void Device::init(int id, DeviceType type, std::string os) {
	this->id = id;
	this->type = type;
	this->os = os;
	this->active = true;
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
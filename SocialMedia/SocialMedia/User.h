#pragma once
#include <string>
#include "DeviceList.h"

class User {
	public:
		void init(unsigned int id, std::string username, unsigned int age);
		void clear();

		int unsigned getID() const;
		std::string getUserName() const;
		unsigned int getAge() const;

		DevicesList& getDevices() const;
		void addDevice(Device newDevice);;
		bool checkIfDevicesAreOn() const;

	private:
		unsigned int id;
		std::string username;
		unsigned int age;
		DevicesList* devicesList;
};
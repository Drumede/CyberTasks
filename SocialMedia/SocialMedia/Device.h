#pragma once
#include <string>

///////////////////////////////////////////////////////////
/*														 //
	Those definitions are used for tests,                //
	you can add your own, but please do not delete any.  //
*/														 //
enum DeviceType {PHONE, PC, LAPTOP, TABLET};		     //
													     //
#define UbuntuOS "UbuntuLinux"                           //						
#define RedHatOS "RedHatLinux"							 // wheres arch linux smh
#define MacOS "MacOS"									 //
#define IOS "IOS"										 //
#define WINDOWS7 "Windows7"                              //
#define WINDOWS10 "Windows10"                            //
#define WINDOWS11 "Windows11"                            //
#define ANDROID "Android"                                //
													     //
/// ///////////////////////////////////////////////////////


class Device
{
	public:
		void init(int deviceId, DeviceType deviceType, std::string deviceOs);
		std::string getOS() const;
		int getID() const;
		DeviceType getType() const;
		bool isActive() const;
		void activate();
		void deactivate();

	private:
		int id;
		DeviceType type;
		bool active;
		std::string os;

};


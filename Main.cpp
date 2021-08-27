#include "Serialization.h"
#include <iostream>

bool CheckSerialization(std::string filePath) {
	// Make the data
	User user("Ali", "123Ali");
	Vehicle vehicle(60, 20, 100);
	DataTransfer theData(user, vehicle);

	// Serialize it
	Serialization serialization;
	try {
		serialization.SerializeData(theData, filePath);
	}
	// Check if it's any error
	catch (std::exception e) {
		std::cout << "Error : " << e.what();
		return false;
	}
	
	return true;
}

bool CheckDeserialization(std::string filePath) {
	// Make the data
	User user("Ali", "123Ali");
	Vehicle vehicle(40, 50, 105);
	DataTransfer theData(user, vehicle);

	// Serialize it
	Serialization serialization;
	serialization.SerializeData(theData, filePath);

	// Deserialize it
	DataTransfer newData;
	try {
		newData = serialization.DeserializeData(filePath);
	}
	// Check if it's any error
	catch (std::exception e) {
		std::cout << "Error : " << e.what();
		return false;
	}
	
	return true;
}

bool CheckCreatedFile(std::string filePath) {
	// Make the data
	User user("Ali", "123Ali");
	Vehicle vehicle(60, 20, 100);
	DataTransfer theData(user, vehicle);

	// Serialize it
	Serialization serialization;
	serialization.SerializeData(theData, filePath);
	
	// Check if file exist
	std::ifstream inFile(filePath);
	if (!inFile) {
		return false;
	}

	return true;
}

bool CheckContentFile(std::string filePath) {
	// Make the data
	User user("Ali", "123Ali");
	Vehicle vehicle(40, 50, 105);
	DataTransfer theData(user, vehicle);

	// Serialize it
	Serialization serialization;
	serialization.SerializeData(theData, filePath);

	// Deserialize it
	DataTransfer newData;
	newData = serialization.DeserializeData(filePath);

	// Load it
	User newUser;	
	Vehicle newVehicle;  

	newUser = newData.GetUserData();
	newVehicle = newData.GetVehicleData();

	if (newUser.GetName() != user.GetName()) {
		return false;
	}
	if (newUser.Getpassword() != user.Getpassword()) {
		return false;
	}
	if (newVehicle.GetWight() != vehicle.GetWight()) {
		return false;
	}
	if (newVehicle.GetMaxSpeed() != vehicle.GetMaxSpeed()) {
		return false;
	}
	if (newVehicle.GetGunCalibre() != vehicle.GetGunCalibre()) {
		return false;
	}

	return true;
}

int main() {
	std::string filePath = "D:\\Tugas_Kuliah\\Workshop_Game_Tester\\Minggu_1\\Serialization_Tester\\Saved_Data.txt";

	// Checking Serialization
	if (CheckSerialization(filePath)) {
		std::cout << "Serialization ok\n";
	}

	// Checking Deserialization
	if (CheckDeserialization(filePath)) {
		std::cout << "Serialization ok\n";
	}

	// Checking created .txt file
	if (CheckCreatedFile(filePath)) {
		std::cout << "File has been created\n";
	}
	else {
		std::cout << "File not created\n";
	}

	// Checking content in file
	if (CheckContentFile(filePath)) {
		std::cout << "File Content ok\n";
	}
	else {
		std::cout << "File Content Not ok\n";
	}

	return 0;
}
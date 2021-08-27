#include "Serialization.h"

void Serialization::SerializeData(DataTransfer theData ,std::string filePath) {
	std::ofstream outFile(filePath);
	boost::archive::text_oarchive archive(outFile);
	archive << theData;
}
DataTransfer Serialization::DeserializeData(std::string filePath) {
	DataTransfer theData;
	std::ifstream inFile(filePath);
	boost::archive::text_iarchive archive(inFile);
	archive >> theData;
	inFile.close();

	return theData;
}
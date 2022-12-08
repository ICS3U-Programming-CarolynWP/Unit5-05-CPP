// Copyright Carolyn
// Created by: Carolyn Webster Pless
// Created on: 22/12/06
// Gets the user inputs for information to display their mailing
// Address. Uses a default statement for whether they have an
// Apartment or not

#include <algorithm>
#include <cctype>
#include <iostream>


// To format the address
std::string FormatMailingAddress(std::string name, std::string streetNum,
                                 std::string street, std::string city,
                                 std::string province,
                                 std::string postalCode,
                                 std::string apartmentNum = "") {
    // Mailing format variable
    std::string mailingFormat;

    // If the user has an apartment
    if (apartmentNum != "") {
        mailingFormat = name + "\n" + apartmentNum[0] + "-" + streetNum + " " +
        street + "\n" + city + " " + province + " " + postalCode;
    } else {
        mailingFormat = name + "\n" + streetNum + " " + street + "\n" +
        city + " " + province + " " + postalCode;
    }
    return mailingFormat;
}

int main() {
    // Variables for the inputs and mailing address
    std::string userName, userStreetNum, userStreetName;
    std::string userCity, userProvince;
    std::string userPostalCode, userApartmentAsk;
    std::string mailingAddress, userApartmentNum;

    // Title
    std::cout << "Mailing Address\n";

    // User inputs
    std::cout << "Please enter your name: ";
    std::getline(std::cin, userName);
    std::cout << "Do you live in an apartment? (y/n):";
    std::getline(std::cin, userApartmentAsk);

    // If the user has an apartment, ask for the apartment number
    if (userApartmentAsk == "y") {
        std::cout << "Enter your apartment number: ";
        std::getline(std::cin, userApartmentNum);
    }

    // User inputs for the rest of the mailing address
    std::cout << "Enter your street number: ";
    std::getline(std::cin, userStreetNum);
    std::cout << "Enter your street name: ";
    std::getline(std::cin, userStreetName);
    std::cout << "Enter your City: ";
    std::getline(std::cin, userCity);
    std::cout << "Enter your Province: ";
    std::getline(std::cin, userProvince);
    std::cout << "Enter your Postal Code: ";
    std::getline(std::cin, userPostalCode);

    // Calling the formatting function
    mailingAddress = FormatMailingAddress(
        userName,
        userStreetNum,
        userStreetName,
        userCity,
        userProvince,
        userPostalCode, userApartmentNum);

    // Displaying the mailing address
    std::cout << "Your mailing address is:\n";
    std::cout << mailingAddress;
}

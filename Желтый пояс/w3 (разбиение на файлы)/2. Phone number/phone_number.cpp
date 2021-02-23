#include "phone_number.h"

#include <sstream>

PhoneNumber::PhoneNumber(const string& international_number) {
	istringstream ss(international_number);
	char ch = ss.get();
	if (ch != '+')
	{
		throw invalid_argument("plus");
	}

	if (getline(ss, country_code_, '-') && (!country_code_.empty()))
	{

	}
	else
	{
		throw invalid_argument("country");
	}

	if (getline(ss, city_code_, '-') && (!city_code_.empty()))
	{

	}
	else
	{
		throw invalid_argument("city");
	}
	if (ss >> local_number_ && !local_number_.empty())
	{

	}
	else {
		throw invalid_argument("local");
	}

}
string PhoneNumber::GetCountryCode() const {
	return country_code_;
}
string PhoneNumber::GetCityCode() const
{
	return city_code_;
}
string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
	return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}

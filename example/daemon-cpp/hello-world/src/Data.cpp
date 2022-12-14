#include <sstream>
#include "logic/Data.hpp"

Data::Data() : title("") {}

Data::~Data() {}

std::string Data::getTitle() const {
    std::string tmp;
    if (title.length() > 0) {
        tmp = title;
    } else {
        tmp = "No title set";
    }
    return tmp + " (C++)";
}

void Data::setTitle(const std::string& title) { this->title = title; }

std::string Data::getMessage(const std::string& name) const {
    if (name.length() > 0) {
        std::stringstream ss;
        ss << "Hello " << name << ", welcome to PolyScope!";
        return ss.str();
    } else {
        return "No name set";
    }
}

#include <iostream>
#include <string>
#include <fstream>

class Address {
public:
    Address() {
        city = "";
        street = "";
        house = 0;
        flat = 0;
    }
    Address(std::string city, std::string street, int house, int flat) :city(city), street(street), house(house), flat(flat) {
    }

    void setCity(std::string city) {
        this->city = city;
    }
    void setStreet(std::string street) {
        this->street = street;
    }
    void setHouse(int house) {
        this->house = house;
    }
    void setFlat(int flat) {
        this->flat = flat;
    }

    std::string getCity() {
        return city;
    }
    std::string getStreet() {
        return street;
    }
    int getHouse() {
        return house;
    }
    int getFlat() {
        return flat;
    }
private:
    std::string city;
    std::string street;
    int house;
    int flat;
};

std::ostream& operator<<(std::ostream& out, Address& a) {
    out << a.getCity() << ", " <<
        a.getStreet() << ", " <<
        a.getHouse() << ", " <<
        a.getFlat() << '\n';
    return out;
}

int main() {

    std::ifstream ifile("in.txt");
    if (!ifile) return 1;

    int count;
    ifile >> count;

    Address* addr = new Address[count];
    std::string c = "", s = "";
    int h = 0, f = 0;

    for (int i = 0; i < count; ++i) {
        ifile >> c;
        addr[i].setCity(c);
        ifile >> s;
        addr[i].setStreet(s);
        ifile >> h;
        addr[i].setHouse(h);
        ifile >> f;
        addr[i].setFlat(f);
    }
    ifile.close();

    std::ofstream ofile("out.txt");
    ofile << count << '\n';
    for (int i = 0; i < count; ++i) {
        ofile << addr[i];
    }

    ofile.close();
    delete[]addr;
    return 0;
}
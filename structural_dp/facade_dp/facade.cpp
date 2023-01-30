#include "facade.hpp"

int main() {
    Facade facade;
    facade.queryMySQL("SELECT * FROM users");
    std::cout << facade.getWeather("FRD") << std::endl;
    facade.queryMongoDB("SELECT * FROM users");
    std::cout << facade.getStockPrice("ZFCVINDIA") << std::endl;
}

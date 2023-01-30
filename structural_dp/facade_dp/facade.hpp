#include <iostream>

class MySQLDatabase
{
public:
    void connect()
    { /* Connect to MySQL database */
        std::cout << "opening sql db." << std::endl;
    }
    void query(std::string sql)
    { /* Execute SQL query */
        std::cout << "getting user data from sql db." << std::endl;
    }
    void close()
    { /* Close connection to MySQL database */
        std::cout << "closing sql db." << std::endl;
    }
};

class MongoDBDatabase
{
public:
    void connect()
    { /* Connect to MongoDB database */
        std::cout << "opening mongo db." << std::endl;
    }
    void query(std::string json)
    { /* Execute JSON query */
        std::cout << "getting user data from mongo db." << std::endl;
    }
    void close()
    { /* Close connection to MongoDB database */
        std::cout << "closing mongo db." << std::endl;
    }
};

class WeatherWebService
{
public:
    std::string getWeather(std::string city)
    { /* Retrieve weather data from web service */
        return std::string("-1*C");
    }
};

class StockMarketWebService
{
public:
    double getStockPrice(std::string stock)
    { /* Retrieve stock data from web service */
        return 8965.00;
    }
};

class Facade
{
private:
    MySQLDatabase         mysql;
    MongoDBDatabase       mongodb;
    WeatherWebService     weather;
    StockMarketWebService market;

public:
    void queryMySQL(std::string sql)
    {
        mysql.connect();
        mysql.query(sql);
        mysql.close();
    }

    void queryMongoDB(std::string json)
    {
        mongodb.connect();
        mongodb.query(json);
        mongodb.close();
    }

    std::string getWeather(std::string city) { return weather.getWeather(city); }

    double getStockPrice(std::string stock) { return market.getStockPrice(stock); }
};

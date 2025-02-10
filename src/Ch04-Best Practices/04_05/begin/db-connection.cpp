#include <iostream>
#include <stdexcept>
// #include <cstdio> // For the FILE handle
#include <memory>
#include <fstream>

/*
    TODO
    Database Connection is leaking resources
    Apply RAII idiom to prevent memory leak and ensure file handle closed

    HINTS
    Convert bufer raw ptr to std::unique_ptr (auto mem management)
    Replace std::FILE handle w/ std::fstream obj

*/

class DatabaseConnection
{
private:
    // char *buffer;
    std::unique_ptr<char[]> buffer; // Raw pointer for database connection data
    // std::FILE *logFile;
    std::fstream logFile; // Raw FILE handle for logging

public:
    DatabaseConnection() : buffer(std::make_unique<char[]>(1024)), logFile("dbLog.txt", std::ios::out | std::ios::app)
    {
        std::cout << "Attempting to open database connection." << std::endl;

        // If opening the log file fails, throw an exception
        if (!logFile)
        {
            throw std::runtime_error("Failed to open log file");
        }

        // Simulate another potential issue after opening the file
        throw std::runtime_error("Failed to connect to database");
    }
    /*
    ~DatabaseConnection()
    {
        std::cout << "Closing database connection.\n";
        delete[] buffer;      // Memory deallocation for the database connection data
        std::fclose(logFile); // Closing the log file handle
    }
    */
};

void simulateDatabaseOperation()
{
    try
    {
        DatabaseConnection dbConn;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

int main()
{
    simulateDatabaseOperation();
    return 0;
}
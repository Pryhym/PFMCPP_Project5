#include "Server.h"

Server::Server():
amOfPeopleServed(8),
hoursWorked(17.5f){}

Server::~Server()
{
    std::cout << "Server Class Now  Out of Scope!" << std::endl;
}

void Server::serveCustomer()
{

}

void Server::cleanTable()
{

}

float Server::countTip(float tip)
{
    return tip;
}

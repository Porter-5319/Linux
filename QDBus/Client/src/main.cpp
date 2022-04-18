#include <iostream>
#include "DBusClient.h"


int main(int argc, char *argv[])
{
    DBusClient client;
//    client.testDBusInterface();
    client.testCreateMethodCall1();
//    client.testCreateSignals();
    return 0;
}

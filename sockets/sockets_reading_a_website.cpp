#include <iostream>
#include <cstring>
#include <netinet/in.h> // struct
#include <arpa/inet.h>  //inet_pton()
#include <netdb.h>      // gethostbyname()
//--- socket
#include <sys/types.h>
#include <sys/socket.h>

using namespace std;

const short HTTP_PORT = 80;

bool entireWebsiteLoaded(const char *websitePart)
{
    return NULL != strstr(websitePart, "</html>");
}

const char *getIpByName(const char *hostName)
{
    hostent *he = NULL;
    if ((he = gethostbyname(hostName)) == NULL)
    {
        herror("gethostbyname");
        exit(-1);
    }
    const char *ipAddress = inet_ntoa(**(in_addr **)he->h_addr_list);
    puts(ipAddress);
    return ipAddress;
}

int main()
{
    sockaddr_in serwer;
    serwer.sin_family = AF_INET;
    serwer.sin_port = htons(HTTP_PORT);

    const char *ipAddress = getIpByName("www.fox-in-the-box.com");
    inet_pton(serwer.sin_family, ipAddress, &serwer.sin_addr);
    const int s = socket(serwer.sin_family, SOCK_STREAM, 0);
    connect(s, (sockaddr *)&serwer, sizeof(serwer));

    char buffer[1000] = "GET / HTTP/1.1\nHOST: www.fox-in-the-box.com\n\n";
    send(s, buffer, strlen(buffer), 0);
    while (recv(s, buffer, sizeof(buffer), 0) > 0)
    {
        puts(buffer);
        if (entireWebsiteLoaded(buffer))
        {
            strcpy(buffer, "^]");
            send(s, buffer, strlen(buffer), 0);
            break;
        }
    }

    shutdown(s, SHUT_RDWR);

    return 0;
}
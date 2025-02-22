#include<bits/stdc++.h>
#include<winsock2.h>

using namespace std;

int main()
{
    WSADATA Winsockdata;
    SOCKET TCPServerSocket, sAcceptSocket;
    struct sockaddr_in TCPServerAdd, TCPClientAdd;
    int iTCPClientAdd = sizeof(TCPClientAdd), iRecv, iSend;
    char RecvBuffer[512];
    char SenderBuffer[512];

    WSAStartup(MAKEWORD(2,2), &Winsockdata);

    TCPServerAdd.sin_family = AF_INET;
    TCPServerAdd.sin_addr.s_addr = inet_addr("192.168.102.33");
    TCPServerAdd.sin_port = htons(8000);

    TCPServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    bind(TCPServerSocket, (SOCKADDR*)&TCPServerAdd, sizeof(TCPServerAdd));
    listen(TCPServerSocket, 2);
    sAcceptSocket = accept(TCPServerSocket, (SOCKADDR*)&TCPClientAdd, &iTCPClientAdd);

    cout << "Connection Established. Start Chatting!\n";
    while (true) {
        // Receive message from the client
        iRecv = recv(sAcceptSocket, RecvBuffer, sizeof(RecvBuffer), 0);
        if (iRecv > 0) {
            RecvBuffer[iRecv] = '\0';
            cout << "Client: " << RecvBuffer << endl;
            if (strcmp(RecvBuffer, "exit") == 0) break;
        }

        // Send message to the client
        cout << "Server: ";
        cin.getline(SenderBuffer, sizeof(SenderBuffer));
        iSend = send(sAcceptSocket, SenderBuffer, strlen(SenderBuffer), 0);
        if (strcmp(SenderBuffer, "exit") == 0) break;
    }

    closesocket(sAcceptSocket);
    closesocket(TCPServerSocket);
    WSACleanup();
    return 0;
}

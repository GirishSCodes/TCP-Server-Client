#include<bits/stdc++.h>
#include<winsock2.h>

using namespace std;

int main()
{
    WSADATA Winsockdata;
    SOCKET TCPClientSocket;
    struct sockaddr_in TCPServerAdd;
    int iRecv, iSend;
    char RecvBuffer[512];
    char SenderBuffer[512];

    WSAStartup(MAKEWORD(2,2), &Winsockdata);

    TCPServerAdd.sin_family = AF_INET;
    TCPServerAdd.sin_addr.s_addr = inet_addr("192.168.102.33");
    TCPServerAdd.sin_port = htons(8000);

    TCPClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    connect(TCPClientSocket, (SOCKADDR*)&TCPServerAdd, sizeof(TCPServerAdd));

    cout << "Connected to Server. Start Chatting!\n";
    while (true) 
    {
        // Send message to the server
        cout << "Client: ";
        cin.getline(SenderBuffer, sizeof(SenderBuffer));
        iSend = send(TCPClientSocket, SenderBuffer, strlen(SenderBuffer), 0);
        if (strcmp(SenderBuffer, "exit") == 0) break;

        // Receive message from the server
        iRecv = recv(TCPClientSocket, RecvBuffer, sizeof(RecvBuffer), 0);
        if (iRecv > 0) 
        {
            RecvBuffer[iRecv] = '\0';
            cout << "Server: " << RecvBuffer << endl;
            if (strcmp(RecvBuffer, "exit") == 0) break;
        }
    }

    closesocket(TCPClientSocket);
    WSACleanup();
    return 0;
}

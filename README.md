# TCP Client-Server Implementation

This project demonstrates a basic TCP client-server implementation using Windows Sockets.

---

## Basics of TCP
TCP (Transmission Control Protocol) is a connection-oriented communication protocol widely used for reliable data transmission over networks. Key features of TCP include:
- **Reliability**: Ensures data is delivered without errors and in the correct order.
- **Connection-Oriented**: Establishes a connection before data transfer begins.
- **Full-Duplex Communication**: Enables simultaneous data exchange between client and server.
- **Flow Control and Congestion Control**: Manages data transmission rates to avoid congestion.

In this project, TCP is used to establish a reliable connection between a server and a client for data exchange.

---

## Prerequisites
- g++ compiler with Windows Sockets 2 (WinSock2) library support

---

## Compilation
To compile the server and client programs, use the following commands:
```bash
g++ -o tcp_server tcp_server.cpp -lws2_32
g++ -o tcp_client tcp_client.cpp -lws2_32
```

---

## Execution
1. Start the server first:
   ```bash
   ./tcp_server
   ```
2. Then, start the client:
   ```bash
   ./tcp_client
   ```

---

## Setting Up IP Address
1. Check your IP address:
   ```bash
   ipconfig
   ```
2. Replace the IP address in both `tcp_server.cpp` and `tcp_client.cpp` with your machine's IPv4 address (e.g., `192.168.x.x`).

---

## Server Workflow
1. **Initialize WinSock (`WSAStartup`)**: Start the Winsock library.
2. **Create a Socket (`socket`)**: Create a socket to establish communication.
3. **Bind (`bind`)**: Assign the socket to a specific IP address and port.
4. **Listen (`listen`)**: Put the socket in listening mode to accept incoming connections.
5. **Accept (`accept`)**: Accept a connection from a client.
6. **Send and Receive Messages (`send` and `recv`)**:
   - Use `recv` to receive data from the client.
   - Use `send` to send data to the client.
7. **Cleanup (`closesocket` and `WSACleanup`)**: Close the sockets and clean up resources.

---

## Client Workflow
1. **Initialize WinSock (`WSAStartup`)**: Start the Winsock library.
2. **Create a Socket (`socket`)**: Create a socket for communication with the server.
3. **Connect (`connect`)**: Establish a connection with the server using its IP and port.
4. **Send and Receive Messages (`send` and `recv`)**:
   - Use `send` to send data to the server.
   - Use `recv` to receive data from the server.
5. **Cleanup (`closesocket` and `WSACleanup`)**: Close the socket and clean up resources.

---

## Running the Client on a Smartphone
To connect to the server using a smartphone:
1. Ensure both devices (server and client) are on the same network.
2. Replace `inet_addr("192.168.102.33")` in `tcp_server.cpp` with `inet_addr("0.0.0.0")` to bind the server to all network interfaces.
3. Compile and run the server program again.
4. Use a TCP Client app (such as "TCP Client" from the app store) on your smartphone to connect to the server. Enter the server's IP address and port (`8000`).

---

## Features
- Full-duplex communication between server and client
- Data exchange over a reliable TCP connection

---

## Improvements
1. Add multi-client support to the server.
2. Implement a graphical user interface (GUI) for easier interaction.
3. Secure the communication with encryption (e.g., TLS).
4. Optimize the buffer size and handle edge cases like large messages.
5. Add logging for server activity.

---

## Resources for `winsock2.h`
For detailed documentation and examples, refer to:
- [Microsoft WinSock Documentation](https://learn.microsoft.com/en-us/windows/win32/winsock/windows-sockets-start-page)
- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/) (general networking concepts, not Windows-specific)

---

## What I Learned
- Basics of TCP communication
- Key functions for TCP communication: `WSAStartup`, `bind`, `connect`, `send`, `recv`
- TCP client-server architecture
- Compiling and linking with `-lws2_32` for networking
- IP configuration and networking setup for local devices

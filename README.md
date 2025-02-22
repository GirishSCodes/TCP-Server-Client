# TCP Client-Server Implementation

This project demonstrates a simple TCP-based client-server chat application using Windows Sockets.

## Prerequisites
- Windows operating system
- g++ compiler with Windows Sockets 2 (WinSock2) library support

## Compilation
To compile the server and client programs, use the following commands:
```bash
g++ -o tcp_server tcp_server.cpp -lws2_32
g++ -o tcp_client tcp_client.cpp -lws2_32
```

## Execution
1. Start the server first:
   ```bash
   ./tcp_server
   ```
2. Then, start the client:
   ```bash
   ./tcp_client
   ```

## Setting Up IP Address
1. Check your IP address:
   ```bash
   ipconfig
   ```
2. Replace the IP address in both `tcp_server.cpp` and `tcp_client.cpp` with your machine's IPv4 address (e.g., `192.168.x.x`).

## Running the Client on a Smartphone
To connect to the server using a smartphone:
1. Ensure both devices (server and client) are on the same network.
2. Replace `inet_addr("192.168.102.33")` in `tcp_server.cpp` with `inet_addr("0.0.0.0")` to bind the server to all network interfaces.
3. Compile and run the server program again.
4. Use a TCP Client app (such as "TCP Client" from the app store) on your smartphone to connect to the server. Enter the server's IP address and port (`8000`).

## Features
- Full-duplex communication between server and client
- Exit the chat by typing `exit` on either side.

## Improvements
1. Add multi-client support to the server.
2. Implement a graphical user interface (GUI) for easier interaction.
3. Secure the communication with encryption (e.g., TLS).
4. Optimize the buffer size and handle edge cases like large messages.
5. Add logging for server activity.

## What I Learned
- Basics of Windows Sockets API
- TCP client-server architecture
- Compiling and linking with `-lws2_32` for networking
- IP configuration and networking setup for local devices

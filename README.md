# Minitalk: Client-Server Communication with Signals

This project demonstrates a basic client-server communication system using UNIX signals. The client sends a message to the server, and the server receives and displays the message character by character.

## Files

- `client.c`: Client implementation that takes the server's PID and a message as command-line arguments. It converts each character into bits and sends them to the server using SIGUSR1 and SIGUSR2 signals.

- `server.c`: Server implementation that prints its PID, sets up signal handlers for SIGUSR1 and SIGUSR2, and displays the received characters.

## Compilation

Compile the client and server using the following commands:

```bash
gcc client.c -o client
gcc server.c -o server

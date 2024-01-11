# Minitalk: Client-Server Communication with Signals

This project demonstrates a basic client-server communication system using UNIX signals. The client sends a message to the server, and the server receives and displays the message character by character.

## Files

- `client.c`: Client implementation that takes the server's PID and a message as command-line arguments. It converts each character into bits and sends them to the server using SIGUSR1 and SIGUSR2 signals.

- `server.c`: Server implementation that prints its PID, sets up signal handlers for SIGUSR1 and SIGUSR2, and displays the received characters.

## Compilation

Compile the client and server using the following commands:

```bash
gcc -Wall -Wextra -Werror client.c libfta/libft.a -o client
gcc -Wall -Wextra -Werror server.c libfta/libft.a -o server
```
## Usage

1. Start the server in one terminal:

```bash
./server
```
1. Note the displayed Server PID.
2. In another terminal, run the client with the server PID and a message:

```bash
./client <server_pid> "<message>"
```
Replace <server_pid> with the actual server PID and <message> with the desired message.

## Example
```bash
#Terminal 1 (server)
./server
#Output: Server PID: <pid>

#Terminal 2 (client)
./client <pid> "Hive Helsinki"
```
The server will display each received character from the client.

### Important Notes
1) Ensure that both the client and server are compiled successfully.
2) Check for error messages during compilation and execution.
3) If issues persist, consider using printf instead of a custom ft_printf for debugging.
4) Adjust the usleep delay in the client if needed to ensure proper signal processing.

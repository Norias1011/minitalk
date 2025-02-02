# Minitalk

Minitalk is a simple message communication program between a client and a server using UNIX signals. This project is part of the 42 curriculum and aims to deepen the understanding of process communication.

## Features
- Server displays its PID upon startup.
- Client sends a string message to the server using signals.
- Server receives and displays the message quickly.
- Server can handle multiple messages sequentially without restarting.
- Communication is done strictly using `SIGUSR1` and `SIGUSR2` signals.

## Bonus Features
- Server acknowledges each received message by sending a signal back to the client.
- Unicode character support for message transmission.

## Allowed Functions
- `write`
- `ft_printf` (or a self-coded equivalent)
- `signal`
- `sigemptyset`
- `sigaddset`
- `sigaction`
- `kill`
- `getpid`
- `malloc`
- `free`
- `pause`
- `sleep`
- `usleep`
- `exit`

## Installation
Clone the repository and compile the program using the provided Makefile:
```sh
make
```

## Usage
### Start the Server
Run the server first:
```sh
./server
```
It will display its PID, which is needed for the client to send messages.

### Send a Message from the Client
Use the client with the server's PID and a message:
```sh
./client <server_pid> "Your message here"
```

## Requirements
- The program must handle errors gracefully (no segmentation faults, memory leaks, or unexpected crashes).
- The server must process messages efficiently.
- The client and server can each use one global variable, but its usage must be justified.

## License
This project is part of the 42 curriculum and follows its guidelines.



<p align="center">
  <img src="assets_github/minitalk.png" width="350" />
</p>
<h3 align="center">
  <em>Code a small data exchange program using UNIX signals.</em>
</h3>

---

## ⚠️ Disclaimer

- **Full Portfolio:** This repository focuses on this specific project. You can find my entire 42 curriculum 👉 [here](https://github.com/Overtekk/42).
- **Subject Rules:** I strictly follow the rules regarding 42 subjects; I cannot share the PDFs, but I explain the concepts in this README.
- **Archive State:** The code is preserved exactly as it was during evaluation (graded state). I do not update it, so you can see my progress and mistakes from that time.
- **Academic Integrity:** I encourage you to try the project yourself first. Use this repo only as a reference, not for copy-pasting. Be patient, you will succeed.

## 📂 Description

The goal of Minitalk is to create a small data exchange program using UNIX signals. It is an introductory project to inter-process communication (IPC).

The challenge is to create a Client and a Server that communicate only using two specific signals: **SIGUSR1** and **SIGUSR2**. Since we cannot use standard networking sockets or pipes, we must encode our messages into binary (0 and 1) and transmit them signal by signal.

 We have to produce a communication channel that is fast and reliable:
- The Server: Must launch first, print its PID, and wait for signals endlessly.
- The Client: Takes the Server's PID and a string as arguments, then sends the string to the server.

> [!Note]
> SIGUSR1 : Represents the bit 0.\
> SIGUSR2 : Represents the bit 1.\
> kill() : System call, used by the client to send signals.\
> signal() : System call used by the server to receive and handle signals.

🏆 Goal: Reconstruct the string on the server side correctly and display it, regardless of the speed or the length of the message.

## 🐨 Status

Not completed yet.

## 🔷 Instructions

### 1.
### First, clone this repository and run `make`:

```bash
git clone https://github.com/Overtekk/minitalk
cd minitalk
make
```

### 2. Execution
#### You need two terminal windows to test the program.

**Terminal 1 (Server)**: Start the server first. It will display its Process ID (PID).

```bash
./server
> [Server] PID: 4242
```

**Terminal 2 (Client)**: Send a message using the PID displayed by the server.
```bash
./client 4242 "Hello, World!"
```

### 3. Error Management Checklist

The program handles the following edge cases:

- [ ] Error if arguments are missing (PID or Message).
- [ ] Error if the PID is invalid (negative or non-numeric).
- [ ] Error if the PID does not belong to an active process (kill check).
- [ ] Handles rapid transmission without losing bits (synchronization).

## ⚙️ Technical Implementation

Since we are restricted to **SIGUSR1** and **SIGUSR2**, I implemented a bitwise communication protocol.

### 1. The Client (Sender)

The client breaks down every character of the message string into **8 bits** (1 byte).

- It iterates through the string, character by character.
- For each character, it iterates from the 7th bit down to the 0th bit.
- It uses bitwise operators (>> and &) to determine if a bit is 0 or 1.
- It sends SIGUSR1 for 0 and SIGUSR2 for 1.
- Timing: A micro-pause (usleep) is added between signals to ensure the server has time to process the previous bit (tuned to match the server's processing speed).

### 2. The Server (Receiver)

The server waits for signals using **signal**.

It uses a static variable to store the character being built.
When it receives a signal:
- If **SIGUSR1**: Adds a 0 (shifts left).
- If **SIGUSR2**: Adds a 1 (shifts left and adds 1 via |).

Once 8 signals are received, the byte is complete. The character is printed (or stored in a buffer for faster printing) and the variables are reset for the next character.

## 📚 Resources & AI Usage

https://42-cursus.gitbook.io/guide/2-rank-02/minitalk\
https://github.com/hanshazairi/42-minitalk\
https://medium.com/@digitalpoolng/42-minitalk-building-a-simple-client-server-communication-program-in-c-a5e6d96c97ec\
https://github.com/leogaudin/minitalk\
https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/manipulation-des-bits/\
Man pages for signal(), kill(), etc...

#### AI Usage Disclaimer

I used AI during the development of this project for specific tasks:

**Debugging Signal Timing**: I asked AI to explain why signals were being lost when sent too fast in a VM environment. This helped me understand the need for usleep and buffering. Because I work in a VM, signal was lost faster and I didn't know how to fix that.

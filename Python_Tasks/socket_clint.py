import socket

# Set up client socket
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Get the server's IP address
server_ip = input("Enter the server IP address: ")
print("Your IP is: " + socket.gethostbyname(socket.gethostname()))
print("=============================")

# Connect to the server
client.connect((server_ip, 5000))

while True:
    # Send a message to the server
    msg = input("Please enter the message that you want to send: ")
    msg_encoded = msg.encode('UTF-8')
    client.send(msg_encoded)

    # Receive a message from the server
    rodata = client.recv(1024)
    if not rodata:
        print("Server has disconnected.")
        break
    print(f"{server_ip} is sending to you this message: {rodata.decode('UTF-8')}")

    # Optionally close the client after one message exchange or continue
    if msg.lower() == "exit":
        print("Closing connection...")
        client.close()
        break

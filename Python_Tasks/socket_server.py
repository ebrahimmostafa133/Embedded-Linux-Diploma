import socket

# Set up server socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # IPv4, TCP
ip = socket.gethostbyname(socket.gethostname())  # Get the server IP
print("Your IP is: " + ip)
print("==============================")

# Bind the socket to the IP and port
s.bind((ip, 5000))
s.listen(5)  # Maximum number of queued connections

while True:
    client, address = s.accept()  # Wait for a client to connect
    print(f"Connection from {address} has been established.")
    print("==============================")

    while True:
        try:
            # Receive message from client
            rodata = client.recv(1024)
            
            if not rodata:
                print("Client has disconnected.")
                break
            
            print(f"{address} is sending to you this message: {rodata.decode('UTF-8')}")
            print("==============================")
            
            # Send a message back to the client
            msg = input("Please enter the message that you want to send: ")
            msg_encoded = msg.encode('UTF-8')
            client.send(msg_encoded)

        except ConnectionResetError:
            print("Connection was reset by the client.")
            break
        except Exception as e:
            print(f"An error occurred: {e}")
            break

    client.close()  # Close the client connection after exiting the inner loop

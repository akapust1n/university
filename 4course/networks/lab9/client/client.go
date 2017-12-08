package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
)

// only needed below for sample processing

func main() {

	fmt.Println("Launching server...")
	conn, _ := net.Dial("tcp", "localhost:8080")
	//fmt.Fprintf(conn, "hello"+"\n")
	message, _ := bufio.NewReader(conn).ReadString('\n')
	fmt.Print("Message from server: " + message)

	go func() {
		for {
			message, _ := bufio.NewReader(conn).ReadString('\n')
			fmt.Print("Message from server: " + message)
		}
	}()
	for {
		// read in input from stdin
		reader := bufio.NewReader(os.Stdin)
		fmt.Print("Text to send: ")
		text, _ := reader.ReadString('\n')
		// send to socket
		fmt.Fprintf(conn, text+"\n")
		fmt.Println("text sended")
		// listen for reply
		//message, _ := bufio.NewReader(conn).ReadString('\n')
	}
}

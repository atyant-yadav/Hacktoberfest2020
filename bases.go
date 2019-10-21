package main 

import (
	"fmt"
)

func main() {
	thestring := "anything"
	fmt.Println(thestring)	// prints the string provided 
	fmt.Printf("%T \n",thestring)	// returns the type of data provided to "thestring" [datatype]

	arraygi := []rune(thestring)	// assigning "string" to uint32 DT
	fmt.Println(arraygi)

	for _,i := range arraygi {
		fmt.Printf("%d - %b - %#X \n",i,i,i,)	// %d for number in arraygi, %b for binary of that number, %#X for hex of same number
	}
}
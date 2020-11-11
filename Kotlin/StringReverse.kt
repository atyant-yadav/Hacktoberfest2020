fun main(args: Array<String>) {
    print("Write anything here: ")

    val enteredString = readLine()
    print(reverse(enteredString))
}

fun reverse(str: String): String {
	var reverse = ""

	for (i in str.length - 1 downTo 0) {
		reverse += str[i]
	}

	return reverse
}

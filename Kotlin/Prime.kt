//Kotlin program to check if the number is prime or not

  fun main(args: Array<String>) {
        val read = Scanner(System.` in`)
        val n = read.nextInt()
        var div = 2
        while (div * div <= n) {
            if (n % div == 0) {
                break
            }
            div++
        }
        if (div * div > n) {
            print("prime")
        } else {
            print("not prime")
        }
    }

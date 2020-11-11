fun printPermutation(str: String, prefix: String) {
   // If string is empty
   if (str.length == 0) {
       print("$prefix ")
       return
   }
   for (i in 0 until str.length) {
  
       val ch = str[i]
    
       val ros = str.substring(0, i) + str.substring(i + 1)

       printPermutation(ros, prefix + ch)
   }
}
void main(List<String> args) {
  //entry point for execution

//variable = spot in a memory or somthing to hold the data/value
//Types of variable
  /*
            String
            numbers
            Booleans
            List
            Maos
          */
  // Boolean -1 or 0 i.e. either tre or false
  // Const and final keywords
  /* const = we can use when we want our value to be constant at compile
          time
          final = if we want to use to keep our value same at every time then we 
          can use this keyword
           */
//  CONCATENATION
// the method to print different strings in a single line

  // String name = "Ayush";
  // String lastName = "Gautam";
  // int age = 18;

  // print("$name $lastName is $age years old");
  // print("Hello there $name ${lastName.toUpperCase()}");
  //if you want to add some property to an string then you can use{} this bracket and add it.

  //Arithmetic operatorrs
  /* +, -, %, x
       % = remainder
      / = division
       */
  int number = 12;
  int numberTwo = 12;
/*------------------------------*/
  double num1 = 9.8;
  double num2 = 2.3;

//FOR loop

  // for (var i = 0; i <= 20; i++) {
  //   if (i % 3 == 0) {
  //     print("Hello $i");
  //   }
  // }

  //switch case
  var age = 18;
  switch (age) {
    case 20:
      print("old enough");
      break;
    case 40:
      print("shouldn't consider");
      break;
    case 80:
      print("shouldn't buy too old");
      break;
    default:
      print("haha gotcha");

    //DO WHILE loop
    // while (true) {
    //   print(
    //       "hello world"); //here this is the infinite loop so to break the loop we use break
    //   break;
    // }

/*Equality and relational operators
      (==, !=, >, <, >=, <=)
      == this means equal 
      = means certain value assigned to any variable..
      relational operators
      is & is!
      
  */
    // print(num1 == num2); //here the result is false..
    // print(num1 is String); the result is false because num1 is not string

    //If Else Statement
    // if (num1 != 9.8)
    // {
    // print("This will run");
    // }
    // else
    //   print("HeHe try again");

    //logical operators ! not  || OR  && AND
    /*OR operater prints the result true if one of the expression is true but 
     in order to print the result true in AND operator both of the condition have to be true!! */

    /*     if (!(num1 != 9.8) || (num1 >10)) //if one condition is true then the compiler prints the reslt truee!
  {
  print("This will run");
  }
  else
  print("HeHe try again"); 
   */
  }
}

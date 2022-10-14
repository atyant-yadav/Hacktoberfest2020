class Hello {
  late String name; //late tells the compiler that the given string is null....
  late String color;
  late int roll;
}

void main(List<String> arguments) {
  var greet = new Hello();
  greet.color = "red panda";
  greet.name = "chor";
  greet.roll = 12;
  print(greet.roll);
}



























// String sayHello(String name, String lastName, [int? age]) =>
//     "Hello My name is  $name $lastName and i am $age years old."; //=> this replaces return expression;

// String yourAge(String name, String lastName,[int? age]) {
//   var finalResult = "$name $lastName";
//   if (age == null) {
//     finalResult = "$finalResult doesnt want to tell their age";
//   }
//   return finalResult;














// whatIsMyName() {
//   print("Your Name is Aayush!");
//   var name = "Aayush";
//   if (name.contains("h")) {
//     print("gotha");
//   } else
//     print("try again!");
// }

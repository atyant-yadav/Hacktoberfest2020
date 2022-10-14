class Ayush {
  late String first;
  late String last;
  late String age;

  //syntatic sugar constructor
  Ayush(this.first, this.last, this.age); //constructor created.
  // named constructor..
  Ayush.initialize() {
    first = "Ayush gautam omg!!";
    age = "20";
  }

  String get getName => first;
  String setName(String value) => first = value;

  void onClick() {
    print("$first $last is $age years old.");
  }

  bool okClick() => true;
}

main(List<String> args) {
  var name = Ayush("Ayush", "Gautam", "19"); //name= name of the obj..
  // name.setName = "HelloWorld";  //idk why this isnt running will find the solution and try later!!

  // var nameSec = Ayush.initialize();
  // print(nameSec.first);
  // name.onClick();
  // print(name.okClick());
}

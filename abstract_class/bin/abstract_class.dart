abstract class Animal {
  void eatsGrass();

  void eatsMeat() {
    print("omnivorous animals eat meat");
  }
}

class Person implements Animal {
  Person(this.name, this.gender);
  late String name, gender;

  @override
  void eatsGrass() {
    print("hervicorous animal eats grass");
  }

  @override
  void eatsMeat() {
    print("omnivoros eats meat");
  }

  @override
  String toString() => "$name,$gender";
}

class Comedian extends Person implements IsFunny {
  Comedian(String name, String gender) : super(name, gender);

  @override
  late String behavoir;

}

class IsFunny {
    late String behavoir;
}

main(List<String> args) {
  var shyam = new Person("Ayush", "Male");
  print(shyam);
}

class School {
  late String name;
  late String caste;
  late num roll;

  School(this.name, this.caste, this.roll);
}

class newSchool extends School {
  newSchool(String name, String caste, num roll) : super(name, caste, roll);

  @override
  String toString() {
    // TODO: implement toString
    var result = "$name $caste studies at grade $roll";
    return result;
  }
}

main(List<String> args) {
  String name = "hello";
  var skool = newSchool("Aayush", "Gautam", 12);
  print(skool.toString());
}

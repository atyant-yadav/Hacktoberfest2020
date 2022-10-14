class Person {
  late String name, lastName, nationality;
  late int age;

  void showName() {
    // ignore: unnecessary_this
    print(this.name);
  }
}

class Ayush extends Person {
  //extends means inherit
  late String profession;
  void showProf() {
    print("Doctor");
  }

  @override
  void showName() {
    // TODO: implement showName
    print("holaaaaaaa ya naholaaaaaaaaa");
  }
}

main(List<String> arguments) {
  var ayush = new Ayush();
  ayush.name = "hahahaha";
  ayush.profession = "Doctor";
  ayush.showName();
  ayush.showProf();
}

import 'package:flutter/material.dart';

import './my_home_page.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Streams',
      theme: ThemeData(
        primarySwatch: Colors.blue, 
      ),
      home: MyHomePage(),
    );
  }
}

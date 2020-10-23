import 'dart:async';

import 'package:flutter/material.dart';

class MyHomePage extends StatefulWidget {
  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  //final StreamController _streamController = StreamController();

  // addData() async {
  //   for (int i = 1; i <= 10; i++) {
  //     await Future.delayed(
  //       Duration(seconds: 1),
  //     );
  //     _streamController.sink.add(i);
  //   }
  // }

  Stream<int> numberStream() async* {
    for (int i = 1; i <= 10; i++) {
      await Future.delayed(Duration(seconds: 1));
      yield i;
    }
  }

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).primaryColor,
        title: Text('Streams'),
      ),
      body: Center(
        child: StreamBuilder(
          stream: numberStream().where((event) => event%2 == 0).map((number) => "the number is $number"),
          builder: (context, snapshot) {
            if (snapshot.hasError) {
              return Text('Some Error');
            } else if (snapshot.connectionState == ConnectionState.waiting) {
              return CircularProgressIndicator();
            }
            return Text(
              "${snapshot.data}",
              style: Theme.of(context).textTheme.headline4,
            );
          },
        ),
      ),
    );
  }
}

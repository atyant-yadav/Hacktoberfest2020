import 'package:flutter/material.dart';
import 'package:flutter_icons/flutter_icons.dart';

import 'feed.dart';

class HomeScreen extends StatefulWidget {
  @override
  _HomeScreenState createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  var _pages = [
    Feed(),
    Feed(),
    Feed(),
    Feed(),
    Feed(),
  ];

  int currentPage = 0;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,
      appBar: PreferredSize(
        preferredSize: Size.fromHeight(48),
        child: AppBar(
          elevation: 1,
          backgroundColor: Colors.white,
          //backgroundColor: Color(0xFFEEEEEE),
          brightness: Brightness.light,
          centerTitle: true,
          title: Text(
            'Instagram',
            style: TextStyle(color: Colors.black),
          ),
          leading: IconButton(
            icon: Icon(Feather.camera, color: Colors.black),
            onPressed: null,
          ),
          actions: [
            IconButton(
              icon: Icon(Feather.send, color: Colors.black),
              onPressed: null,
            ),
          ],
        ),
      ),
      body: _pages[currentPage],
      bottomNavigationBar: BottomNavigationBar(
        currentIndex: currentPage,
        onTap: (i){
          setState(() {
            currentPage = i;
          });
        },
        type: BottomNavigationBarType.fixed,
        showSelectedLabels: false,
        showUnselectedLabels: false,
        selectedItemColor: Colors.black,
        items: [
          BottomNavigationBarItem(
            icon: Icon(Foundation.home),
            title: Text('Feed'),
          ),
          BottomNavigationBarItem(
            icon: Icon(Feather.search),
            title: Text('Search'),
          ),
          BottomNavigationBarItem(
            icon: Icon(Feather.plus_square),
            title: Text('Upload'),
          ),
          BottomNavigationBarItem(
            icon: Icon(Feather.heart),
            title: Text('likes'),
          ),
          BottomNavigationBarItem(
            icon: Icon(Feather.user),
            title: Text('account'),
          ),
        ],
      ),
    );
  }
}

import 'package:flutter/material.dart';
import 'package:flutter_icons/flutter_icons.dart';
import 'package:insta_clone/models/post.dart';
import 'package:insta_clone/models/story.dart';

class Feed extends StatelessWidget {

  final List<Story> _stories = [
    Story(
        "https://images.pexels.com/photos/4407688/pexels-photo-4407688.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
        "jessica"),
    Story(
        "https://images.pexels.com/photos/2859616/pexels-photo-2859616.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
        "sarah"),
    Story(
        "https://images.pexels.com/photos/4286947/pexels-photo-4286947.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
        "jacob"),
    Story(
        "https://images.pexels.com/photos/4348327/pexels-photo-4348327.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
        "cassie"),
    Story(
        "https://images.pexels.com/photos/774909/pexels-photo-774909.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
        "ana"),
    Story(
        "https://images.pexels.com/photos/220453/pexels-photo-220453.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
        "eric"),
    Story(
        "https://images.pexels.com/photos/415829/pexels-photo-415829.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
        "gal Gadot"),
    Story(
        "https://images.pexels.com/photos/1681010/pexels-photo-1681010.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
        "tim"),
    Story(
        "https://images.pexels.com/photos/614810/pexels-photo-614810.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
        "brian"),
    Story(
        "https://images.pexels.com/photos/2379004/pexels-photo-2379004.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
        "abishek"),
    Story(
        "https://images.pexels.com/photos/1855582/pexels-photo-1855582.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
        "vanya"),
  ];

  final List<Post> posts = [
    Post(
      username: "Brianne",
      userImage:
          "https://images.pexels.com/photos/614810/pexels-photo-614810.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      postImage:
          "https://images.pexels.com/photos/3859774/pexels-photo-3859774.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      caption: "New York in the evening.",
    ),
    Post(
      username: "Jammie",
      userImage:
          "https://images.pexels.com/photos/4348327/pexels-photo-4348327.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      postImage:
          "https://images.pexels.com/photos/1049622/pexels-photo-1049622.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      caption: "Anime expo.",
    ),
    Post(
      username: "Laura",
      userImage:
          "https://images.pexels.com/photos/1130626/pexels-photo-1130626.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      postImage:
          "https://images.pexels.com/photos/5970/road-nature-forest-trees.jpg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      caption: "Nature at its best",
    ),
    Post(
      username: "Celine",
      userImage:
          "https://images.pexels.com/photos/762020/pexels-photo-762020.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      postImage:
          "https://images.pexels.com/photos/678725/pexels-photo-678725.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      caption: "Malidives..speechless",
    ),
    Post(
      username: "James",
      userImage:
          "https://images.pexels.com/photos/1438275/pexels-photo-1438275.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      postImage:
          "https://images.pexels.com/photos/6259/space-camera-desk-laptop.jpg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      caption: "Finally. A desk Upgrade!",
    ),
    Post(
      username: "Graham",
      userImage:
          "https://images.pexels.com/photos/4904569/pexels-photo-4904569.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      postImage:
          "https://images.pexels.com/photos/2225439/pexels-photo-2225439.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      caption: "The Collosium",
    ),
    Post(
      username: "Edgar",
      userImage:
          "https://images.pexels.com/photos/4330308/pexels-photo-4330308.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      postImage:
          "https://images.pexels.com/photos/1851164/pexels-photo-1851164.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      caption: "wwrrrrrrry PewdiePie",
    ),
    Post(
      username: "Torvald",
      userImage:
          "https://images.pexels.com/photos/428364/pexels-photo-428364.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      postImage:
          "https://images.pexels.com/photos/1904769/pexels-photo-1904769.jpeg?auto=compress&cs=tinysrgb&dpr=1&w=500",
      caption: "Simply thrilling",
    ),
  ];

  @override
  Widget build(BuildContext context) {
    return Container(
        child: SingleChildScrollView(
          child: Column(
            children: [
              Divider(
                thickness: 0,
                height: 9,
                color: Colors.white,
              ),
              Container(
                width: MediaQuery.of(context).size.width,
                //margin: EdgeInsets.symmetric(vertical: 15),
                height: 90,
                child: ListView.builder(
                  scrollDirection: Axis.horizontal,
                  shrinkWrap: true,
                  itemCount: _stories.length,
                  itemBuilder: (context, i) {
                    return Column(
                      children: [
                        Container(
                          padding: EdgeInsets.all(2),
                          margin: EdgeInsets.symmetric(horizontal: 9.5),
                          decoration: BoxDecoration(
                            // gradient: LinearGradient(
                            //   colors: [
                            //     Colors.amber,
                            //     Colors.orange,
                            //     Colors.pink[600],
                            //     Colors.purple[700],
                            //     Colors.blue[800],
                            //   ],
                            // ),
                            borderRadius: BorderRadius.circular(80),
                            border: Border.all(
                              width: 2,
                              color: Colors.pink[700],
                              //color: Color(0xFF8e44ad),
                            ),
                          ),
                          child: ClipRRect(
                            borderRadius: BorderRadius.circular(80),
                            child: Image(
                              image: NetworkImage(_stories[i].image),
                              height: 55,
                              width: 55,
                              fit: BoxFit.cover,
                            ),
                          ),
                        ),
                        SizedBox(height: 5),
                        Text(_stories[i].name),
                      ],
                    );
                  },
                ),
              ),

              //Posts
              Container(
                width: MediaQuery.of(context).size.width,
                child: ListView.builder(
                  shrinkWrap: true,
                  physics: NeverScrollableScrollPhysics(),
                  itemCount: posts.length,
                  itemBuilder: (ctx, i) {
                    return Container(
                      //color: Colors.white,
                      child: Column(
                        children: [
                          Container(
                            padding: EdgeInsets.symmetric(
                              vertical: 10,
                              horizontal: 10,
                            ),
                            child: Row(
                              mainAxisAlignment: MainAxisAlignment.spaceBetween,
                              children: [
                                Row(
                                  children: [
                                    ClipRRect(
                                      borderRadius: BorderRadius.circular(40),
                                      child: Image(
                                        image: NetworkImage(posts[i].userImage),
                                        width: 40,
                                        height: 40,
                                        fit: BoxFit.cover,
                                      ),
                                    ),
                                    SizedBox(width: 10),
                                    Text(posts[i].username),
                                  ],
                                ),
                                IconButton(
                                  icon: Icon(
                                    SimpleLineIcons.options_vertical,
                                    color: Colors.black,
                                    size: 18,
                                  ),
                                  onPressed: null,
                                ),
                              ],
                            ),
                          ),
                          Image(
                            image: NetworkImage(posts[i].postImage),
                            width: MediaQuery.of(context).size.width,
                          ),
                          Row(
                            //this has the heart,comment icons
                            mainAxisAlignment: MainAxisAlignment.spaceBetween,
                            children: [
                              Row(
                                children: [
                                  IconButton(
                                    icon: Icon(
                                      FontAwesome.heart_o,
                                      color: Colors.black,
                                    ),
                                    onPressed: null,
                                  ),
                                  IconButton(
                                    icon: Icon(
                                      FontAwesome.comment_o,
                                      size: 25,
                                      color: Colors.black,
                                    ),
                                    onPressed: null,
                                  ),
                                  IconButton(
                                    icon: Icon(
                                      Feather.send,
                                      color: Colors.black,
                                    ),
                                    onPressed: null,
                                  ),
                                ],
                              ),
                              IconButton(
                                icon: Icon(
                                  FontAwesome.bookmark_o,
                                  color: Colors.black,
                                ),
                                onPressed: null,
                              ),
                            ],
                          ),
                          Container(
                            //this has the liked by text
                            width: MediaQuery.of(context).size.width,
                            margin: EdgeInsets.symmetric(horizontal: 14),
                            child: RichText(
                              softWrap: true,
                              overflow: TextOverflow.visible,
                              text: TextSpan(
                                children: [
                                  TextSpan(
                                    text: "Liked By",
                                    style: TextStyle(
                                      color: Colors.black,
                                    ),
                                  ),
                                  TextSpan(
                                    text: " Sigmund",
                                    style: TextStyle(
                                      fontWeight: FontWeight.bold,
                                      color: Colors.black,
                                    ),
                                  ),
                                  TextSpan(
                                    text: " and ",
                                    style: TextStyle(
                                      color: Colors.black,
                                    ),
                                  ),
                                  TextSpan(
                                    text: "1,326 others",
                                    style: TextStyle(
                                      fontWeight: FontWeight.bold,
                                      color: Colors.black,
                                    ),
                                  ),
                                ],
                              ),
                            ),
                          ),
                          SizedBox(height: 5),
                          Container(
                            width: MediaQuery.of(context).size.width,
                            margin: EdgeInsets.symmetric(horizontal: 14),
                            child: RichText(
                              text: TextSpan(
                                children: [
                                  TextSpan(
                                    text: posts[i].username,
                                    style: TextStyle(
                                      fontWeight: FontWeight.bold,
                                      color: Colors.black,
                                    ),
                                  ),
                                  TextSpan(
                                    text: " ${posts[i].caption}",
                                    style: TextStyle(
                                      //fontWeight: FontWeight.bold,
                                      color: Colors.black,
                                    ),
                                  ),
                                ],
                              ),
                            ),
                          ),
                          //post date
                          SizedBox(height: 5),
                          Container(
                            alignment: Alignment.centerLeft,
                            margin: EdgeInsets.symmetric(horizontal: 14),
                            child: Text(
                              '2 days ago',
                              style: TextStyle(
                                fontSize: 10,
                                color: Colors.grey,
                              ),
                            ),
                          ),
                        ],
                      ),
                    );
                  },
                ),
              ),
            ],
          ),
        ),
      );
  }
}
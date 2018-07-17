# darknet-cpp

Darknet is well known for yolo implementation. However, darknet is built in c and it makes it little painful to integrate with other c++ projects. In this project, I will update darknet c library to c++.

Current Status:
- Cmake files added
- Yolo v3 added
- Network detection memory leak fix after darknet update

Future work:
- Replace c style raw pointers to smart pointers
- Improve modularity

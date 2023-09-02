HEADERS += \
    $$PWD/desk_read.h \
    $$PWD/myfacedetect.h \
    $$PWD/video_common.h \
    $$PWD/video_read.h

SOURCES += \
    $$PWD/desk_read.cpp \
    $$PWD/myfacedetect.cpp \
    $$PWD/video_read.cpp

#使用opencv 4.2.0
INCLUDEPATH+=$$PWD\opencv-release\include\opencv2\
             $$PWD\opencv-release\include

LIBS+=$$PWD\opencv-release\lib\libopencv_calib3d420.dll.a\
      $$PWD\opencv-release\lib\libopencv_core420.dll.a\
      $$PWD\opencv-release\lib\libopencv_features2d420.dll.a\
      $$PWD\opencv-release\lib\libopencv_flann420.dll.a\
      $$PWD\opencv-release\lib\libopencv_highgui420.dll.a\
      $$PWD\opencv-release\lib\libopencv_imgproc420.dll.a\
      $$PWD\opencv-release\lib\libopencv_ml420.dll.a\
      $$PWD\opencv-release\lib\libopencv_objdetect420.dll.a\
      $$PWD\opencv-release\lib\libopencv_video420.dll.a\
      $$PWD\opencv-release\lib\libopencv_videoio420.dll.a

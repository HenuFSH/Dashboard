TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dashboard_detect.cpp \
    dashboard.cpp

LIBS += -L$$PWD/../../opencv/lib/

INCLUDEPATH += $$PWD/../../opencv

#LIBS += $$PWD/../../opencv/lib/libopencv_aruco.so
#LIBS += $$PWD/../../opencv/lib/libopencv_objdetect.so
#LIBS += $$PWD/../../opencv/lib/libopencv_bgsegm.so
#LIBS += $$PWD/../../opencv/lib/libopencv_optflow.so
#LIBS += $$PWD/../../opencv/lib/libopencv_bioinspired.so
#LIBS += $$PWD/../../opencv/lib/libopencv_phase_unwrapping.so
#LIBS += $$PWD/../../opencv/lib/libopencv_calib3d.so
LIBS += $$PWD/../../opencv/lib/libopencv_photo.so
#LIBS += $$PWD/../../opencv/lib/libopencv_ccalib.so
#LIBS += $$PWD/../../opencv/lib/libopencv_plot.so
LIBS += $$PWD/../../opencv/lib/libopencv_core.so
#LIBS += $$PWD/../../opencv/lib/libopencv_reg.so
#LIBS += $$PWD/../../opencv/lib/libopencv_datasets.so
#LIBS += $$PWD/../../opencv/lib/libopencv_rgbd.so
#LIBS += $$PWD/../../opencv/lib/libopencv_dnn_objdetect.so
#LIBS += $$PWD/../../opencv/lib/libopencv_saliency.so
#LIBS += $$PWD/../../opencv/lib/libopencv_dnn.so
#LIBS += $$PWD/../../opencv/lib/libopencv_shape.so
#LIBS += $$PWD/../../opencv/lib/libopencv_dpm.so
#LIBS += $$PWD/../../opencv/lib/libopencv_stereo.so
#LIBS += $$PWD/../../opencv/lib/libopencv_face.so
#LIBS += $$PWD/../../opencv/lib/libopencv_stitching.so
#LIBS += $$PWD/../../opencv/lib/libopencv_features2d.so
#LIBS += $$PWD/../../opencv/lib/libopencv_structured_light.so
#LIBS += $$PWD/../../opencv/lib/libopencv_flann.so
LIBS += $$PWD/../../opencv/lib/libopencv_superres.so
#LIBS += $$PWD/../../opencv/lib/libopencv_freetype.so
#LIBS += $$PWD/../../opencv/lib/libopencv_surface_matching.so
#LIBS += $$PWD/../../opencv/lib/libopencv_fuzzy.so
#LIBS += $$PWD/../../opencv/lib/libopencv_text.so
#LIBS += $$PWD/../../opencv/lib/libopencv_gapi.so
#LIBS += $$PWD/../../opencv/lib/libopencv_tracking.so
#LIBS += $$PWD/../../opencv/lib/libopencv_hfs.so
#LIBS += $$PWD/../../opencv/lib/libopencv_videoio.so
LIBS += $$PWD/../../opencv/lib/libopencv_highgui.so
#LIBS += $$PWD/../../opencv/lib/libopencv_video.so
LIBS += $$PWD/../../opencv/lib/libopencv_imgcodecs.so
#LIBS += $$PWD/../../opencv/lib/libopencv_videostab.so
LIBS += $$PWD/../../opencv/lib/libopencv_img_hash.so
#LIBS += $$PWD/../../opencv/lib/libopencv_xfeatures2d.so
LIBS += $$PWD/../../opencv/lib/libopencv_imgproc.so
#LIBS += $$PWD/../../opencv/lib/libopencv_ximgproc.so
#LIBS += $$PWD/../../opencv/lib/libopencv_line_descriptor.so
#LIBS += $$PWD/../../opencv/lib/libopencv_xobjdetect.so
#LIBS += $$PWD/../../opencv/lib/libopencv_ml.so
LIBS += $$PWD/../../opencv/lib/libopencv_xphoto.so

HEADERS += \
    dashboard_detect.h \
    dashboard.h

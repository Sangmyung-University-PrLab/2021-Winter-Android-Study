#include <jni.h>
#include <string>
#include "opencv2/opencv.hpp"

using namespace cv;

extern "C" JNIEXPORT jstring JNICALL
Java_ac_kr_smu_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}extern "C"
JNIEXPORT void JNICALL
Java_ac_kr_smu_MainActivity_processing(JNIEnv *env, jobject thiz, jlong input_addr,
                                       jlong output_addr) {
    Mat &input = *(Mat *)input_addr;
    Mat &ret = *(Mat *)output_addr;

    cvtColor(input,ret,COLOR_BGR2GRAY);
}
#include "page_frame.h"

PageFrame::PageFrame() {
    std::cout << "Hello, PageFrame!" << std::endl;
}

void PageFrame::helloPageFrame() {
    int num;
    num = getNumFrames();
    std::cout << "Hello, helloPageFrame!" << std::endl
              << "The number of frames is : " << num << std::endl;
}

int PageFrame::getNumFrames() {
    return numFrames;
}

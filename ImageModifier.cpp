#include <iostream>
#include <stdexcept>
#include <opencv2/opencv.hpp> // using opencv4 - ppen source computer vision library

using namespace std;



class ImageModifier {    
  public:
    ImageModifier(const string filename, double alpha, int gamma);

    void changeContrast();
    void displayImages();

  private:
    string originalFilename;
    cv::Mat originalImage;
    cv::Mat modifiedImage;

    double alpha; // Simple contrast control
    int gamma;    // Simple brightness control

    static constexpr const double MIN_ALPHA = 1.0;
    static constexpr const double MAX_ALPHA = 3.0;
    static constexpr const int MIN_GAMMA = 0;
    static constexpr const int MAX_GAMMA = 100;

    void validateInput();
};   


ImageModifier::ImageModifier(const string filename, double alpha, int gamma)
  : originalFilename(filename), alpha(alpha), gamma(gamma) { 
  try {
    originalImage = cv::imread(filename);
    modifiedImage = cv::Mat::zeros(originalImage.size(), originalImage.type());
    validateInput();
  } catch (const exception& e) {
    cerr << "Exception: " << e.what() << endl;
    exit(1);
  }
}

void ImageModifier::validateInput() {
  if (originalImage.empty()) {
    throw runtime_error("Image file not found or invalid.");
  }

  if (!(MIN_ALPHA <= alpha && alpha <= MAX_ALPHA)) {
    throw out_of_range("Alpha must be in the range [1.0, 3.0].");
  }

  if (!(MIN_GAMMA <= gamma && gamma <= MAX_GAMMA)) {
    throw out_of_range("Gamma must be in the range [0, 100].");
  }
}

void ImageModifier::changeContrast() {
  for (int i = 0; i < originalImage.rows; i++) {
    for (int j = 0; j < originalImage.cols; j++) {
      for (int channel = 0; channel < originalImage.channels(); channel++) {
        modifiedImage.at<cv::Vec3b>(i, j)[channel] = cv::saturate_cast<uchar>(alpha * originalImage.at<cv::Vec3b>(i, j)[channel] + gamma);
      }
    }
  }

  cout << "\nYour image has been modified" << endl;
}

void ImageModifier::displayImages() {
  cv::imshow("Original image", originalImage);
  cv::imshow("Modified image", modifiedImage);

  cv::waitKey(0);
}




// Main for testing the class only
int main() {
  ImageModifier img("söpö.jpg", 1.2, 65);
  //cout << img.originalImage;

  img.changeContrast(); 
  img.displayImages();

  return 0;
}
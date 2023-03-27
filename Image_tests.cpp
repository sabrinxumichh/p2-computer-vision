// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.

TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

TEST(test_image_init){
  Image *img = new Image;
  Image_init(img, 6, 9);

  ASSERT_EQUAL(Image_width(img), 6);
  ASSERT_EQUAL(Image_height(img), 9);

  delete img;
}

TEST(image_init2){
  Image *img = new Image;
  Image_init(img, 1, 1);

  ASSERT_EQUAL(Image_width(img), 1);
  ASSERT_EQUAL(Image_height(img), 1);

  delete img;
}

TEST(image_init3){
  Image *img = new Image;
  Image_init(img, MAX_MATRIX_WIDTH, MAX_MATRIX_HEIGHT);

  ASSERT_EQUAL(Image_width(img), MAX_MATRIX_WIDTH);
  ASSERT_EQUAL(Image_height(img), MAX_MATRIX_HEIGHT);

  delete img;
}

TEST(image_init4){
  Image *img = new Image;
  
  stringstream os;
  os << "P3\n1 1\n255\n";
  os << "0 255 255 \n";

  Image_init(img, os);

  ostringstream out;
  Image_print(img, out);

  ASSERT_EQUAL(os.str(), out.str());
  delete img;
}

TEST(image_init5){
  Image *img = new Image;
  
  stringstream os;
  os << "P3\n2 3\n255\n";
  os << "0 255 0 255 255 255 \n"
     << "0 0 0 255 0 255 \n"
     << "255 255 0 0 255 255 \n";

  Image_init(img, os);

  ostringstream out;
  Image_print(img, out);

  ASSERT_EQUAL(os.str(), out.str());
  delete img;
}

TEST(test_image_width){
  Image *img = new Image;
  Image_init(img, 6, 4);

  ASSERT_EQUAL(Image_width(img), 6);

  delete img;
}

TEST(test_image_width2){
  Image *img = new Image;
  Image_init(img, 1, 1);

  ASSERT_EQUAL(Image_width(img), 1);

  delete img;
}

TEST(test_image_height){
  Image *img= new Image;
  Image_init(img, 6, 4);

  ASSERT_EQUAL(Image_height(img), 4);

  delete img;
}

TEST(test_image_height2){
  Image *img = new Image;
  Image_init(img, 1, 1);

  ASSERT_EQUAL(Image_height(img), 1);

  delete img;
}

TEST(test_image_get_pixel){
  Image *img = new Image;
  

  stringstream right;
  right << "P3\n2 3\n255\n";
  right << "0 255 0 255 255 255 \n";
  right << "0 0 0 255 0 255 \n";
  right << "255 255 0 0 255 255 \n";
  Image_init(img, right);

  Pixel a = Image_get_pixel(img, 0, 0);
  ASSERT_EQUAL(a.r, 0);
  ASSERT_EQUAL(a.g, 255);
  ASSERT_EQUAL(a.b, 0);

  Pixel b = Image_get_pixel(img, 0, 1);
  ASSERT_EQUAL(b.r, 255);
  ASSERT_EQUAL(b.g, 255);
  ASSERT_EQUAL(b.b, 255);

  Pixel c = Image_get_pixel(img, 1, 0);
  ASSERT_EQUAL(c.r, 0);
  ASSERT_EQUAL(c.g, 0);
  ASSERT_EQUAL(c.b, 0);

  Pixel d = Image_get_pixel(img, 1, 1);
  ASSERT_EQUAL(d.r, 255);
  ASSERT_EQUAL(d.g, 0);
  ASSERT_EQUAL(d.b, 255);

  Pixel e = Image_get_pixel(img, 2, 0);
  ASSERT_EQUAL(e.r, 255);
  ASSERT_EQUAL(e.g, 255);
  ASSERT_EQUAL(e.b, 0);

  Pixel f = Image_get_pixel(img, 2, 1);
  ASSERT_EQUAL(f.r, 0);
  ASSERT_EQUAL(f.g, 255);
  ASSERT_EQUAL(f.b, 255);

  delete img;
}

TEST(test_image_get_pixel2){
  Image *img = new Image;
  

  stringstream right;
  right << "P3\n1 1\n255\n";
  right << "0 255 255 \n";
  Image_init(img, right);

  Pixel a = Image_get_pixel(img, 0, 0);
  ASSERT_EQUAL(a.r, 0);
  ASSERT_EQUAL(a.g, 255);
  ASSERT_EQUAL(a.b, 255);

  delete img;
}

TEST(test_image_fill) {
Image *img = new Image;
const Pixel red = {255, 0, 0};

Image_init(img, 2, 3);
Image_fill(img, red);

ostringstream out; 
Image_print(img,out);

stringstream os;

os << "P3\n2 3\n255\n";
os << "255 0 0 255 0 0 \n"
   << "255 0 0 255 0 0 \n"
   << "255 0 0 255 0 0 \n";


ASSERT_EQUAL(out.str(),os.str());

delete img;
}

TEST(test_image_fill2) {
Image *img = new Image;
const Pixel green = {0, 255, 0};

Image_init(img, 1, 1);
Image_fill(img, green);

ostringstream out; 
Image_print(img,out);

stringstream os;

os << "P3\n1 1\n255\n";
os << "0 255 0 \n";


ASSERT_EQUAL(out.str(),os.str());

delete img;
}

TEST(test_image_basic) {
  Pixel red = {255, 0, 0};
  Pixel green = {0, 255, 0};
  Image *img = new Image;
  Image_init(img, 3, 4);

  ASSERT_EQUAL(Image_width(img), 3);
  ASSERT_EQUAL(Image_height(img), 4);

  Image_fill(img, red);
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 2, 2), red));

  Image_set_pixel(img, 0, 0, green);
  ASSERT_TRUE(Pixel_equal(Image_get_pixel(img, 0, 0), green));

  delete img;
}

TEST(test_image_from_and_to_stream) {
  Image *img = new Image;

  // A very poorly behaved input PPM.
  string input = "P3 2 2\t255 255 0 0\n0\n255 0 \n0 0 255 255 255 255 \n";
  std::istringstream ss_input(input);
  Image_init(img, ss_input);

  // Should be well behaved when you print it though!
  string output_correct = "P3\n2 2\n255\n255 0 0 0 255 0 \n0 0 255 255 255 255 \n";
  std::ostringstream ss_output;
  Image_print(img, ss_output);
  string actual = ss_output.str();
  std::cout << actual << std::endl;
  ASSERT_EQUAL(actual, output_correct);

  delete img;
}
// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here

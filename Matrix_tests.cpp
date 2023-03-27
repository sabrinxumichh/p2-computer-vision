// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"
#include <sstream>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.


TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(test_fill_basic2) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 9;
  const int height = 2;
  const int value = 23;
  Matrix_init(mat, 9, 2);
  Matrix_fill(mat, 23);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(test_fill_basic3) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 1;
  const int height = 1;
  const int value = 30;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, 30);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}



TEST(test_matrix_print) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);

  *Matrix_at(mat, 0, 0) = 42;
  ostringstream expected;
  expected << "1 1\n"
           << "42 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());

  delete mat;
}

TEST(test_matrix_print2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 2, 3);

  
  Matrix_fill(mat, 0);

  ostringstream expected;
  expected << "2 3\n"
           << "0 0 \n"
           << "0 0 \n"
           << "0 0 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());

  delete mat;
}

TEST(test_width) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1 , 1);

  ASSERT_EQUAL(1, Matrix_width(mat));

  delete mat;

}

TEST(test_width2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 6 , 9);

  ASSERT_EQUAL(6, Matrix_width(mat));

  delete mat;

}

TEST(test_height) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 2);

  ASSERT_EQUAL(2, Matrix_height(mat));

  delete mat;
}

TEST(test_height2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 7, 4);

  ASSERT_EQUAL(4, Matrix_height(mat));

  delete mat;
}

TEST(test_height3) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);

  ASSERT_EQUAL(1, Matrix_height(mat));

  delete mat;
}

TEST(test_row) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 3);

  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 2, 0)), 2);

  delete mat;

}

TEST(test_row2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);

  ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 0, 0)), 0);

  delete mat;

}

TEST(test_column){
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 3);

  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 1, 1)), 1);

  delete mat;
}

TEST(test_column2){
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);

  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 0, 0)), 0);

  delete mat;
}

TEST(test_column3){
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 2);

  ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 1, 0)), 0);

  delete mat;
}

TEST(test_matrix_at) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 4, 5);
  Matrix_fill(mat, 4);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0; j < Matrix_width(mat); j++) {
      ASSERT_EQUAL(*Matrix_at(mat, 4, 3), 4);
    }
  }

  delete mat;
}

TEST(test_matrix_at2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, 3);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0; j < Matrix_width(mat); j++) {
      ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 3);
    }
  }

  delete mat;
}

TEST(test_fill) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, 3);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0; j < Matrix_width(mat); j++) {
      ASSERT_EQUAL(*Matrix_at(mat, 2, 2), 3);
    }
  }
    
  delete mat;

}

TEST(test_fill2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, 7);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0; j < Matrix_width(mat); j++) {
      ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 7);
    }
  }
    
  delete mat;

}

TEST(test_fill3) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 9, 11);
  Matrix_fill(mat, 2);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0; j < Matrix_width(mat); j++) {
      ASSERT_EQUAL(*Matrix_at(mat, 4, 5), 2);
    }
  }
    
  delete mat;

}

TEST(test_fill4) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 4, 1);
  Matrix_fill(mat, 7);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0; j < Matrix_width(mat); j++) {
      ASSERT_EQUAL(*Matrix_at(mat, 0, 3), 7);
    }
  }
    
  delete mat;

}

TEST(test_fill5) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 4);
  Matrix_fill(mat, 7);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0; j < Matrix_width(mat); j++) {
      ASSERT_EQUAL(*Matrix_at(mat, 3, 0), 7);
    }
  }
    
  delete mat;

}

TEST(test_fill_border) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 5);
  Matrix_fill(mat, 6);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0; j < Matrix_width(mat); j++) {
      ASSERT_EQUAL(*Matrix_at(mat, 0, 1), 6);
    }
  }

  delete mat;
}

TEST(test_fill_border2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, 3);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0; j < Matrix_width(mat); j++) {
      ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 3);
    }
  }

  delete mat;
}

TEST(test_fill_border3) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 4, 1);
  Matrix_fill(mat, 8);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0; j < Matrix_width(mat); j++) {
      ASSERT_EQUAL(*Matrix_at(mat, 0, 3), 8);
    }
  }

  delete mat;
}

TEST(test_fill_border4) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 4);
  Matrix_fill(mat, 8);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0; j < Matrix_width(mat); j++) {
      ASSERT_EQUAL(*Matrix_at(mat, 3, 0), 8);
    }
  }

  delete mat;
}

TEST(test_fill_border5) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 4, 8);
  Matrix_fill(mat, 6);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0; j < Matrix_width(mat); j++) {
      ASSERT_EQUAL(*Matrix_at(mat, 2, 3), 6);
    }
  }

  delete mat;
}


TEST(test_max) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, 5);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0 ; j < Matrix_width(mat); j++) {
      *Matrix_at(mat, 2, 2) = 6;
    }
  }
  ASSERT_EQUAL(Matrix_max(mat), 6);

  delete mat;
  
}

TEST(test_max2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 4, 7);
  Matrix_fill(mat, 5);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0 ; j < Matrix_width(mat); j++) {
      *Matrix_at(mat, 2, 2) = 2;
    }
  }
  ASSERT_EQUAL(Matrix_max(mat), 5);

  delete mat;
  
}

TEST(test_max3) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, 5);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0 ; j < Matrix_width(mat); j++) {
      *Matrix_at(mat, 0, 0) = 27;
    }
  }
  ASSERT_EQUAL(Matrix_max(mat), 27);

  delete mat;
  
}

TEST(test_mincol) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, 5);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0 ; j < Matrix_width(mat); j++) {
      *Matrix_at(mat, 2, 2) = 3;
    }
  }
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 0, 3), 2);

  delete mat;

}

TEST(test_mincol2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 1);
  Matrix_fill(mat, 5);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0 ; j < Matrix_width(mat); j++) {
      *Matrix_at(mat, 0, 1) = 2;
    }
  }
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 2), 1);

  delete mat;

}

TEST(test_minrow) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 5);
  Matrix_fill(mat, 8);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0 ; j < Matrix_width(mat); j++) {
      *Matrix_at(mat, 3, 2) = 3;
    }
  }
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 3, 0, 4), 3);

  delete mat;
}

TEST(test_minrow2) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 1);
  Matrix_fill(mat, 5);
  for (int i = 0; i < Matrix_height(mat); i++) {
    for (int j = 0 ; j < Matrix_width(mat); j++) {
      *Matrix_at(mat, 0, 1) = 2;
    }
  }
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 2), 2);

  delete mat;

}


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here


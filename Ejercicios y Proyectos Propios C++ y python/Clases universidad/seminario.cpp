#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void imfilter( const cv::Mat & image ) {

  // Creando las ventanas
  namedWindow( "Imagen Original", WINDOW_AUTOSIZE );
  namedWindow( "Imagen Filtrada", WINDOW_AUTOSIZE );

  // Muestra imagen original//
  imshow( "Imagen Original", image );

  // Variable para imagen de salida
  Mat out;

  // Filtro Gaussiano 
  GaussianBlur( image, out, Size(3,3), 3, 3);
  GaussianBlur(   out, out, Size(3,3), 3, 3);

  // Muestra imagen filtrada
  imshow( "Imagen Filtrada", out );

  // Presiona una tecla para salir
  waitKey( 0 );

  destroyWindow( "Imagen Original" );
  destroyWindow( "Imagen Filtrada" );

}

int main( int argc, char** argv ){
  //imread puede leer “BMP, DIB, JPEG, JPE, PNG, PBM, PGM, PPM, SR, RAS, and TIFF”
  Mat img = imread(argv[1],-1); 

  if( img.empty() ) 
    return -1;


  imfilter( img );


  return 0;
}


// Función de similaridad entre parches
float patchSimilarity(const Mat& input, int x1, int y1, int x2, int y2, int patchSize, float h) {
    float similarity = 0.0;
    float totalWeight = 0.0;

    for (int i = -patchSize; i <= patchSize; i++) {
        for (int j = -patchSize; j <= patchSize; j++) {
            float distance = 0.0;
            for (int k = 0; k < input.channels(); k++) {
                distance += pow(input.at<Vec3b>(x1 + i, y1 + j)[k] - input.at<Vec3b>(x2 + i, y2 + j)[k], 2);
            }
            float weight = exp(-distance / (h * h));
            similarity += weight * input.at<Vec3b>(x2 + i, y2 + j)[0]; // Usando el canal R para simplificar
            totalWeight += weight;
        }
    }

    return similarity / totalWeight;
}

// Aplicar el filtrado Nonlocal Means a una imagen
Mat nonLocalMeansFilter(const Mat& input, int patchSize, int searchWindowSize, float h) {
    Mat output = Mat::zeros(input.size(), input.type());

    int halfPatchSize = patchSize / 2;
    int halfSearchWindowSize = searchWindowSize / 2;

    for (int i = halfSearchWindowSize; i < input.rows - halfSearchWindowSize; i++

) {
        for (int j = halfSearchWindowSize; j < input.cols - halfSearchWindowSize; j++) {
            float totalWeight = 0.0;
            float filteredValue = 0.0;

            for (int k = i - halfSearchWindowSize; k <= i + halfSearchWindowSize; k++) {
                for (int l = j - halfSearchWindowSize; l <= j + halfSearchWindowSize; l++) {
                    float similarity = patchSimilarity(input, i, j, k, l, halfPatchSize, h);
                    float weight = exp(-similarity / (h * h));

                    totalWeight += weight;
                    filteredValue += weight * input.at<Vec3b>(k, l)[0]; // Usando el canal R para simplificar
                }
            }

            output.at<Vec3b>(i, j)[0] = filteredValue / totalWeight; // Usando el canal R para simplificar
        }
    }

    return output;
}

int main() {
    Mat inputImage = imread("input_image.jpg"); // Cargar la imagen de entrada
    if (inputImage.empty()) {
        cout << "No se pudo cargar la imagen de entrada.";
        return -1;
    }

    Mat filteredImage = nonLocalMeansFilter(inputImage, 3, 7, 20.0); // Llamar a la función de filtrado Nonlocal Means

    imshow("Input Image", inputImage);
    imshow("Filtered Image", filteredImage);
    waitKey(0);

    return 0;
}


//En este código, se utilizan las funciones de OpenCV para cargar una imagen de entrada, aplicar el filtrado Nonlocal Means y mostrar la imagen original junto con la imagen filtrada. Asegúrate de reemplazar "inpu.//

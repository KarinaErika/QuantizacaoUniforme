/*
Karina Erika dos Santos
Trabalho da disciplina de Processamento de Imagem
Programa de Pós-Graduação em Ciência da Computação
Prof.: Aristófanes Correa
Técnica de quantização uniforme
*/

#include "pch.h"
#include<opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <cstdlib>
#include<math.h>
#include <opencv2/core/types.hpp>
#include <opencv2/core/types_c.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

using namespace std;
using namespace cv;

void quantiza(int bits_resultado, Mat img) {

	CvScalar p;
	int k, i, j;
	int bits = 8; // retorna com os bits da imagem
	bits_resultado = pow(2, bits_resultado); //quantidade de bits para a nova imagem


	int cores = pow(2, bits); //bits da imagem original
	int intervalo = cores / bits_resultado; //intervalo medição

	//realiza o calculo da quantização
	if (bits_resultado > 2) {
		for (i = 0; i < img.cols; i++) {
			for (j = 0; j < img.rows; j++) {
				k = img.at<uchar>(i, j); //nova imagem
				k = k / intervalo;
				k = k * intervalo;
				img.at<uchar>(i, j) = round(k);
			}
		}
	}


	imshow("Quantizada", img);
	imwrite("../data/lenaQuantizadaUniforme.png", img); //Salva a imagem


	waitKey(0);
}



int main()
{

	Mat img, img2;
	String imageName("./data/lena.jpg");

	int bits_resultado;

	cout << "\nDigite o numero de bits para a nova imagem: ";

	cin >> bits_resultado;

	img = imread(imageName, IMREAD_GRAYSCALE);

	namedWindow("Original", WINDOW_AUTOSIZE);
	imshow("Original", img);
	quantiza(bits_resultado, img);


	return 0;
}
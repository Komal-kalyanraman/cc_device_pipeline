
/// @brief library used to convert image to byteStream and vice versa is from below repo
/// https://github.com/RonnyldoSilva/OpenCV_Mat_to_Base64
///

#include <opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include "cc_device_common.hpp"
#include <vector>
#include <string>

using namespace std;
using namespace cv;

#ifndef _IMAGE_BYTESTREAM_H_
#define _IMAGE_BYTESTREAM_H_

/**
 * Classe que converte as imagens para base64 e virse e versa
 */
class ImageConverter {
public:
	/// @brief Public static method getInstance(). This function is responsible for object creation.
    static ImageConverter* getInstance();

	/**
	 * Constritor default da classe
	 */
	ImageConverter();
	
	/**
	 * Método que converte uma imagem base64 em um cv::Mat
	 * @param imageBase64, imagem em base64
	 * @return imagem em cv::Mat
	 */
	cv::Mat str2mat(const string& imageBase64);
	
	/**
	 * Método que converte uma cv::Mat numa imagem em base64
	 * @param img_path as string
	 * @return imagem em base64
	 */
	string mat2str(const string& img_path);

	virtual ~ImageConverter();

private:
	/// @brief Static pointer instance to make this class singleton.
	static ImageConverter* m_pInstance;

	std::string base64_encode(uchar const* bytesToEncode, unsigned int inLen);

	std::string base64_decode(std::string const& encodedString);

};

#endif /* _IMAGE_BYTESTREAM_H_ */
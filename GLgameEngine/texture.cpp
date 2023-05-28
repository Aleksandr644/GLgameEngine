//#include "texture.h"
//
//OurTexture::OurTexture(const GLchar* texturePath) {
//
//	glGenTextures(1, &this->texture);
//	glBindTexture(GL_TEXTURE_2D, this->texture);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	int width, height, nrChannels;
//	unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
//	if (data) {
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else {
//		std::cout << "Failed to load texture: " << texturePath << std::endl;
//	}
//	stbi_image_free(data);
//	glBindTexture(GL_TEXTURE_2D, 0);
//}
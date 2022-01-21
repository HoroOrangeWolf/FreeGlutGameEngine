#include "BitMapHandler.h"
#include <iostream>
#include "stb_image.h"

/**
 * .
 * \brief Naklada bitmape na obiekcie
 */
void BitMapHandler::drawTexture()
{
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
		0, GL_RGB, GL_UNSIGNED_BYTE, text);
	// Filtrowanie:
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

}

/**
 * .
 * \brief Konstruktor
 * \param name Sciezka do pliku
 */
BitMapHandler::BitMapHandler(std::string name)
{
	this->name = name;
	text = stbi_load(name.c_str(), &width, &height, &nchan, 0);
}

/**
 * .
 * \brief Destruktor
 */
BitMapHandler::~BitMapHandler()
{

	if (cube_texc != NULL)
		delete[] cube_texc;

	if (text != NULL) {
		stbi_image_free(text);
	}
}

